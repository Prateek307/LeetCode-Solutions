// link to the problem ---> https://leetcode.com/problems/smallest-string-with-swaps/

using ll = long long;
class DSU
{
public:
    vector<int> rank;
    vector<int> parent;
    int n;
    DSU(int n)
    {
        this->n = n;
        rank = vector<int>(n, 1);
        parent = vector<int>(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    ll find(ll a)
    {
        if (parent[a] == a)
            return a;
        else
            return parent[a] = find(parent[a]);
    }
    void unionF(ll a, ll b)
    {
        ll pa = find(a);
        ll pb = find(b);
        if (pa == pb)
            return;
        if (rank[pa] > rank[pb])
        {
            swap(pa, pb);
        }
        parent[pa] = pb;
        if (rank[pa] == rank[pb])
            rank[pb]++;
    }
};
class Solution
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &p)
    {
        DSU ds(s.size());
        for (auto i : p)
        {
            ds.unionF(i[0], i[1]);
        }
        // priority_queue<char, vector<char>, greater<char> >
        map<int, priority_queue<char, vector<char>, greater<char>>> pq;
        for (int i = 0; i < s.size(); i++)
        {
            pq[ds.find(i)].push(s[i]);
            // cout<<ds.find(i)<<"->"<<s[i]<<"  ";
        }
        // cout<<endl;

        for (int i = 0; i < s.size(); i++)
        {
            int par = ds.find(i);
            s[i] = pq[par].top();
            // cout<<pq[par].top()<<"->"<<par<<"  "<<i<<"  ";
            pq[par].pop();
        }
        return s;
    }
};