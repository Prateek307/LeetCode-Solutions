// link to the problem ---> https://leetcode.com/problems/plus-one/

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size(), i = n - 1;
        if (n == 1 && digits[0] == 9)
            return {1, 0};
        bool carry = 1;
        while (i >= 0)
        {
            if (digits[i] == 9 && carry == 1)
            {
                carry = 1;
                digits[i] = 0;
            }
            else if (digits[i] != 9 && carry == 1)
            {
                carry = 0;
                digits[i] += 1;
            }
            i--;
        }
        if (carry == 1)
        {
            vector<int> ans;
            ans.push_back(1);
            i = 0;
            while (i < n)
            {
                ans.push_back(digits[i]);
                i++;
            }
            return ans;
        }
        return digits;
    }
};