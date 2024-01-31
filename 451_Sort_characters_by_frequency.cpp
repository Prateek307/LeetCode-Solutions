// link to the problem ---> https://leetcode.com/problems/sort-characters-by-frequency/

class Solution
{
public:
    std::string frequencySort(std::string s)
    {
        std::map<char, int> m;
        for (char c : s)
        {
            m[c]++;
        }

        std::vector<std::pair<int, char>> v;
        for (auto it : m)
        {
            v.push_back(std::make_pair(it.second, it.first));
        }

        // Sorting based on frequency in descending order
        sort(v.rbegin(), v.rend());

        std::string temp;
        for (auto pair : v)
        {
            char val = pair.second;
            int times = pair.first;
            while (times--)
            {
                temp.push_back(val);
            }
        }

        return temp;
    }
};