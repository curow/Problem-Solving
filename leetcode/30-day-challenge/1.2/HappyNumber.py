class Solution:
    def isHappy(self, n: int) -> bool:
        def get_digits(n):
            digits = []
            while n != 0:
                digits.append(n % 10)
                n //= 10
            return digits
        def sum_square(digits):
            return sum(map(lambda x: x**2, digits))
        cycle_detector = set()
        happy = True
        while n != 1:
            if n not in cycle_detector:
                cycle_detector.add(n)
            else:
                happy = False  
                break
            n = sum_square(get_digits(n))
        return happy
