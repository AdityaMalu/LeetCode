class Solution:

    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        rows = len(grid)
        cols = len(grid[0])

        prefix_x = [[0] * (cols + 1) for _ in range(rows + 1)]
        prefix_y = [[0] * (cols + 1) for _ in range(rows + 1)]

        for r in range(rows):
            for c in range(cols):
                prefix_x[r+1][c+1] = prefix_x[r+1][c] + prefix_x[r][c+1] - prefix_x[r][c] + (1 if grid[r][c] == 'X' else 0)
                prefix_y[r+1][c+1] = prefix_y[r+1][c] + prefix_y[r][c+1] - prefix_y[r][c] + (1 if grid[r][c] == 'Y' else 0)

        count = 0
        
        for r1 in range(rows):
            for c1 in range(cols):
                if r1 == 0 and c1 == 0:
                    for r2 in range(r1, rows):
                        for c2 in range(c1, cols):
                            x_count = prefix_x[r2+1][c2+1] - prefix_x[r2+1][c1] - prefix_x[r1][c2+1] + prefix_x[r1][c1]
                            y_count = prefix_y[r2+1][c2+1] - prefix_y[r2+1][c1] - prefix_y[r1][c2+1] + prefix_y[r1][c1]
                            
                            if x_count > 0 and x_count == y_count:
                                count += 1
        
        return count