class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        nums = []
        ans = []
        count = 0
        for i in range(len(matrix)):
            for j in range(len(matrix)):
                nums.append(matrix[j][i])
        for i in range(len(nums)):
            if (i+1)%len(matrix)==0:
                ans.append(nums[i])
                matrix.append(ans[::-1])
                ans = []
                matrix.pop(0)
            else:
                ans.append((nums[i]))



            