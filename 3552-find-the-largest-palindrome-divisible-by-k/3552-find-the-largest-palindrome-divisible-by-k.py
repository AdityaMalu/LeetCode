class Solution:
    def largestPalindrome(self, n: int, k: int) -> str:
        if k== 1:
            ans = '9'*n
            return ans
        elif k == 2:
            if n == 1:
                return '8'
            ans = '8' + '9' * (n - 2) + '8'
            return ans
        elif k == 3 or k == 9:
            ans = '9' * n
            return ans
        elif k == 4:
            if n < 5:
                ans = '8' * n
            else:
                ans = '88' + '9' * (n - 4) + '88'
            return ans
        elif k == 5:
            if n == 1:
                return '5'
            ans = '5' + '9' * (n - 2) + '5'
            return ans
        elif k == 8:
            if n < 7:
                ans = '8' * n
            else:
                ans = '888' + '9' * (n - 6) + '888'
            return ans
        elif k == 6:
            if n == 1:
                return '6'
            elif n == 2:
                return '66'
            else:
                if n % 2 == 0:
                    ans = '8' + '9' * ((n - 4) // 2) + '77' + '9' * ((n - 4) // 2) + '8'
                else:
                    ans = '8' + '9' * ((n - 3) // 2) + '8' + '9' * ((n - 3) // 2) + '8'
            return ans
        else:
            if n % 6 == 0:
                return '9' * n
            elif n % 12 == 1:
                ans = '9' * ((n - 1) // 2) + '7' + '9' * ((n - 1) // 2)
            elif n % 12 == 2:
                ans = '9' * ((n - 2) // 2) + '77' + '9' * ((n - 2) // 2)
            elif n % 12 == 3:
                ans = '9' * ((n - 1) // 2) + '5' + '9' * ((n - 1) // 2)
            elif n % 12 == 4:
                ans = '9' * ((n - 2) // 2) + '77' + '9' * ((n - 2) // 2)
            elif n % 12 == 5:
                ans = '9' * ((n - 1) // 2) + '7' + '9' * ((n - 1) // 2)
            elif n % 12 == 7:
                ans = '9' * ((n - 1) // 2) + '4' + '9' * ((n - 1) // 2)
            elif n % 12 == 8:
                ans = '9' * ((n - 2) // 2) + '44' + '9' * ((n - 2) // 2)
            elif n % 12 == 9:
                ans = '9' * ((n - 1) // 2) + '6' + '9' * ((n - 1) // 2)
            elif n % 12 == 10:
                ans = '9' * ((n - 2) // 2) + '44' + '9' * ((n - 2) // 2)
            elif n % 12 == 11:
                ans = '9' * ((n - 1) // 2) + '4' + '9' * ((n - 1) // 2)
            return ans
