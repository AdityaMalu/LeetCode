class Solution:
    
    @staticmethod
    def generate_valid_strings(n: int) -> List[str]:
        if n == 1:
            return ["0", "1"]
        
        prev_strings = Solution.generate_valid_strings(n - 1)
        result = []
        
        for s in prev_strings:
            if s[-1] == '0':
                result.append(s + '1')
            else:
                result.append(s + '0')
                result.append(s + '1')
        
        return result

    def validStrings(self, n: int) -> List[str]:
        return Solution.generate_valid_strings(n)
