class Solution:
    def numberOfAlternatingGroups(self, colors: List[int]) -> int:
        n = len(colors)
        if n < 3:
            return 0
        
        extended_colors = colors + colors[:2]
        
        count = 0
        for i in range(n):
            if extended_colors[i] != extended_colors[i+1] and extended_colors[i+1] != extended_colors[i+2]:
                count += 1
        
        return count