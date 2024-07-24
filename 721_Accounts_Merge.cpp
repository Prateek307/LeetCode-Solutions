// link to the problem --->  https://leetcode.com/problems/accounts-merge/

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // good implementaion qn
        // enough to revise the DSU for DSA

        // dekh merging krni hai + dynamically krni h ==> DSU ka qn i tried combination of maps and set to somehow avoid DSU but it was not possible
        // map bnao hr mail ko point krdo owner pe (owner here will be the i basically int se denote kr rhe hai owner)
        // agr duplicate mail aagyi that means map me pehle se thi toh hme connect krne hai woh current i(owner) and mpp[that mail](that is the prev owner)

        // aise DSU structure poora ho jayega
        // ab isse vec of vec of strings bnayenge..map iterate kro kyuki waha sare mails prhe hai unke penultiamte parent pe push krdo

        // ab pr isse unclear sa vector bnega mtlb na toh kuch khli honge rows and kisi me bhi owner nhi hai toh last me nyi vector me shift krdo sort krke
        int n = accounts.size();
        unordered_map<string, int> mailMapNode;
        DisjointSet ds(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                // map me daalo agar nhi kra
                if (mailMapNode.find(mail) == mailMapNode.end())
                {
                    mailMapNode[mail] = i;
                }
                else
                {
                    // map me mail already hai to union kro unke indexes me
                    ds.unionByRank(i, mailMapNode[mail]);
                }
            }
        }
        vector<string> mergedmail[n];

        for (auto it : mailMapNode)
        {
            string mail = it.first;
            //"johnsmith@mail.com"-0
            //"johnsmith@mail.com"-1 toh 1 ko 0 se connect kro kyuki ye map me already exist karta hai
            //"john00@mail.com" -1 hai to isko ham 1 hi push krenge
            int node = ds.findUPar(it.second);
            mergedmail[node].push_back(mail);
        }
        // name:mails
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergedmail[i].size() == 0)
                continue;
            sort(mergedmail[i].begin(), mergedmail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]); // the name
            for (auto it : mergedmail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};