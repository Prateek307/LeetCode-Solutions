// link to the problem ---> https://leetcode.com/problems/simplify-path/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    string simplifyPath(string path)
    {

        stack<string> st;
        int i, n = path.size();
        string res;
        for (i = 0; i < n; i++)
        {
            if (path[i] == '/')
                continue;
            string temp;
            while (i < n && path[i] != '/')
            {
                temp.push_back(path[i]);
                i++;
            }
            if (temp == ".")
                continue;
            else if (temp == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else
                st.push(temp);
        }
        while (!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        if (res.size() == 0)
            return "/";
        return res;
    }
};