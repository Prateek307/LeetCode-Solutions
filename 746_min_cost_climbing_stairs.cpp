#include <bits/stdc++.h>
using namespace std;

int dp[1013];

int solve(vector<int> &cost, int index)
{
    if (index >= cost.size())
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int val1 = solve(cost, index + 1) + cost[index];
    int val2 = solve(cost, index + 2) + cost[index];

    return dp[index] = min(val1, val2);
}

int main()
{
    int n, i;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    vector<int> cost(n);
    for (i = 0; i < n; i++)
        cin >> cost[i];
    cout << min(solve(cost, 0), solve(cost, 1));
    return 0;
}
