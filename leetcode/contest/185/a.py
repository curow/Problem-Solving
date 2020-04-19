import string
class Solution:
    def reformat(self, s: str) -> str:
        d, c = '', ''
        result = ''
        for x in s:
            if x in string.digits:
                d += x
            else:
                c += x
        diff = abs(len(d) - len(c))
        if diff == 0 or diff == 1:
            for digit, char in zip(d, c):
                result += digit + char
            if diff != 0:
                if len(d) > len(c):
                    result += d[-1]
                else:
                    result = c[-1] + result
        return result

        
