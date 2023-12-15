// link to the problem ---> https://leetcode.com/problems/destination-city/?envType=daily-question&envId=2023-12-15

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        int i;
        set<string> s;
        for (auto it : paths)
        {
            s.insert(it[0]);
        }
        for (auto it : paths)
        {
            string &des = it[1];
            if (s.find(des) == s.end())
            {
                return des;
            }
        }
        return "";
    }
};