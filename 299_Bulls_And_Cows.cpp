// link to the problem --->  https://leetcode.com/problems/bulls-and-cows/description/

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bull = 0, cow = 0;
        unordered_map<char, int> m;

        for (int i = 0; i < secret.size(); ++i)
        {
            if (secret[i] == guess[i])
            {
                ++bull;
                secret[i] = '*'; // Marking bull positions
            }
            else
            {
                ++m[secret[i]]; // Counting characters not in correct position
            }
        }

        for (int i = 0; i < guess.size(); ++i)
        {
            if (secret[i] != '*' && m.find(guess[i]) != m.end() && m[guess[i]] > 0)
            {
                ++cow;
                --m[guess[i]]; // Marking characters used as cows
            }
        }

        string ans;
        ans += to_string(bull) + "A" + to_string(cow) + "B";

        return ans;
    }
};
