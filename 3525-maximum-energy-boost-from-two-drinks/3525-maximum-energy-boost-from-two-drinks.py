class Solution:
    def maxEnergyBoost(self, energyDrinkA: List[int], energyDrinkB: List[int]) -> int:
        n = len(energyDrinkA)
        if n == 0:
            return 0
        if n == 1:
            return max(energyDrinkA[0], energyDrinkB[0])
        
        dp = [[0, 0] for _ in range(n)]
        
        dp[0][0] = energyDrinkA[0]
        dp[0][1] = energyDrinkB[0]
        dp[1][0] = energyDrinkA[0] + energyDrinkA[1]
        dp[1][1] = energyDrinkB[0] + energyDrinkB[1]
        
        for i in range(2, n):
            dp[i][0] = max(dp[i-1][0] + energyDrinkA[i], dp[i-2][1] + energyDrinkA[i])
            dp[i][1] = max(dp[i-1][1] + energyDrinkB[i], dp[i-2][0] + energyDrinkB[i])
        
        return max(dp[n-1][0], dp[n-1][1])