class Solution:
    def splitArraySameAverage(self, A: List[int]) -> bool:
        def average(X):
            return sum(X) / len(X)
        def splitRecursive(B, C, currentIndex):
            if currentIndex >= len(A):
                if B and C:
                    return average(B) == average(C)
                return False
            current = [A[currentIndex]]
            currentIndex += 1
            return splitRecursive(
                    B + current, C, currentIndex
                ) \
                or splitRecursive(
                    B, C + current, currentIndex
                )
        return splitRecursive([], [], 0)
