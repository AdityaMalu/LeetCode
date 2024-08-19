#User function Template for python3

class Solution:
	def Evaluate(self, str1):
		a = str1.split('+')
		b = a[1].split('=')
		
		return int(b[1]) - int(b[0])


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		str = input()
		ob = Solution()
		ans = ob.Evaluate(str)
		print(ans)
# } Driver Code Ends