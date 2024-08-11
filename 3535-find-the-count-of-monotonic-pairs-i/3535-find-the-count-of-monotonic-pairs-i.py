class Solution:
    def countOfPairs(self, nums: List[int]) -> int:
        M = 10**9 + 7
        n = len(nums)
        dp = [[[ -1 for _ in range(51)] for _ in range(51)] for _ in range(n)]

        def solve(i, p1, p2):
            if i == n:
                return 1
            if dp[i][p1][p2] != -1:
                return dp[i][p1][p2]
            cnt = 0
            for a1i in range(p1, nums[i] + 1):
                a2i = nums[i] - a1i
                if a2i <= p2:
                    cnt = (cnt + solve(i + 1, a1i, a2i)) % M
            dp[i][p1][p2] = cnt
            return cnt

        return solve(0, 0, 50)
