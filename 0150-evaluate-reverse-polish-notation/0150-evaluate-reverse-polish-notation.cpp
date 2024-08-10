#include <vector>
#include <stack>
#include <string>

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;

        for (const string &token : tokens)
        {
            if (token == "+")
            {
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                stk.push(first + second);
            }
            else if (token == "-")
            {
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                stk.push(first - second);
            }
            else if (token == "*")
            {
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                stk.push(first * second);
            }
            else if (token == "/")
            {
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                stk.push(first / second);
            }
            else
            {
                stk.push(stoi(token)); // Convert the token to an integer and push it
            }
        }

        return stk.top(); // The result will be the top of the stack
    }
};
