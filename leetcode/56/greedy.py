class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        intervals = sorted(intervals)
        finished = []
        working = intervals[0]
        for i in range(len(intervals)):
            # interval i has overlap with current working interval
            if working[1] >= intervals[i][0]:
                working[1] = max(working[1], intervals[i][1])
            else:
                finished.append(working)
                working = intervals[i]
        finished.append(working)
        return finished
