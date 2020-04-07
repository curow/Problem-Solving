class Solution:
    def get_mapping(self):
        import string
        mapping = {}
        codes = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        for char, code in zip(string.ascii_lowercase, codes):
            mapping[char] = code
        return mapping
    
    def transform(self, mapping, word):
        code = ''
        for char in word:
            code += mapping[char]
        return code

    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morses = set()
        mapping = self.get_mapping()
        for word in words:
            code = self.transform(mapping, word)
            morses.add(code)
        return len(morses)
