// link to the problem ---> https://leetcode.com/problems/third-maximum-number/description/

class Solution
{
public:
    struct DescendingComparator
    {
        bool operator()(const int &lhs, const int &rhs) const
        {
            return lhs > rhs;
        }
    };

    int thirdMax(vector<int> &nums)
    {
        set<int, DescendingComparator> st;
        for (auto it : nums)
            st.insert(it);

        auto it = st.begin();

        if (st.size() < 3)
            return *it;

        advance(it, 2);
        return *it;
    }
};