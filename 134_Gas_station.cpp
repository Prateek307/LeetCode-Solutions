// link to the problem ---> https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index = 0 , total_diff = 0 ,i =0, fuel = 0;
        while(i<gas.size())
        {
            fuel+=gas[i] - cost[i];
            total_diff+=gas[i] - cost[i];
            if(fuel<0)
            {
                fuel = 0;
                index =  i + 1;
            }
            i++;
        }
        return (total_diff<0)?-1:index;
    }
};