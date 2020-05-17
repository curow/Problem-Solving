class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ""
        for xs in zip(*strs):
            if all([x == xs[0] for x in xs]):
                prefix += xs[0]
            else:
                break
        return prefix
