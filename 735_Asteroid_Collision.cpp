#include <stack>
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &ast)
    {
        stack<int> s;
        int i = 0;
        if (ast.size() == 0 || ast.size() == 1)
        {
            return ast;
        }
        int x = 0;
        while (!ast.empty())
        {
            i = ast.size() - 1;
            if (s.empty() || ast[i] < 0)
            {
                s.push(ast[i]);
            }
            else if (ast[i] * s.top() < 0)
            {
                if (ast[i] > abs(s.top()))
                {
                    s.pop();
                    if (!s.empty() && s.top() < 0)
                    {
                        continue;
                    }
                    s.push(ast[i]);
                }
                else if (ast[i] == abs(s.top()))
                {
                    s.pop();
                }
            }
            else if (ast[i] * s.top() > 0)
            {
                s.push(ast[i]);
            }
            ast.pop_back();
        }
        while (!s.empty())
        {
            ast.push_back(s.top());
            s.pop();
        }
        return ast;
    }
};