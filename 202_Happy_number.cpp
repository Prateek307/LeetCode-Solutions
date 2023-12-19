// link to the problem ---> https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool isHappy(int n) {
        map<int,int> usedIntegers;
        while(1)
        {
            int sum = 0;
            while(n)
            {
                int last = n%10;
                sum+=pow(last,2);
                n/=10;
            }
            if(sum==1)
            return 1;

            n = sum;

            if(usedIntegers.find(n)!=usedIntegers.end())
            return 0;
            usedIntegers[n]++;
        }
        return 1;
    }
};