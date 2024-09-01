class Solution:
    def checkTwoChessboards(self, coordinate1: str, coordinate2: str) -> bool:
        def f(coordinate):
            column = ord(coordinate[0].upper()) - ord('A') + 1
            row = int(coordinate[1])  
            return (row, column)
        
        x1, y1 = f(coordinate1)
        x2, y2 = f(coordinate2)
        
        return (x1 + y1) % 2 == (x2 + y2) % 2