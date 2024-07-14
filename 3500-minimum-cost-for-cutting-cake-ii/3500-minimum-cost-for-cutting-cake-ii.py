class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        horizontalCut.sort(reverse=True)
        verticalCut.sort(reverse=True)
        
        h = 0  
        v = 0 
        
        horizontalPieces = 1  
        verticalPieces = 1   
        
        totalCost = 0
        
        while h < m - 1 and v < n - 1:
            if horizontalCut[h] >= verticalCut[v]:
                totalCost += horizontalCut[h] * verticalPieces
                h += 1
                horizontalPieces += 1
            else:
                totalCost += verticalCut[v] * horizontalPieces
                v += 1
                verticalPieces += 1
        
        while h < m - 1:
            totalCost += horizontalCut[h] * verticalPieces
            h += 1
        
        while v < n - 1:
            totalCost += verticalCut[v] * horizontalPieces
            v += 1
        
        return totalCost