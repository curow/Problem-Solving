import bisect
mapping = {'c':0, 'r':1, 'o':2, 'a':3, 'k':4}
class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        def binary_search(a, x):
            i = bisect.bisect_left(a, x)
            if i != len(a) and a[i] == x:
                return i
            return -1
        finished_frogs = 0
        current_frogs = []
        for x in croakOfFrogs:
            index = mapping[x]
            if index == 0: 
                if finished_frogs:
                    finished_frogs -= 1
                bisect.insort(current_frogs, 1)
            else:
                match = binary_search(current_frogs, index)
                if match != -1:
                    sound = (current_frogs[match] + 1) % 5
                    current_frogs.pop(match)
                    if sound:
                        bisect.insort(current_frogs, sound)
                    else:
                        finished_frogs += 1
                else:
                    return -1
        if current_frogs:
            return -1
        return finished_frogs
                        
        
