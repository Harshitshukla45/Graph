class Solution {
public:
    bool dfs(vector<int> &vis,vector<int>&check,vector<vector<int>>& adj,int x)
    {
        vis[x]=1;
        check[x]=1;
        for(auto it:adj[x])
        {
            if(!vis[it])
            {
                if(dfs(vis,check,adj,it))
                {
                    return true;
                }
            }
            else if(check[it]==1)
            {
                return true;
            }
        }
        check[x]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int v= adj.size();
        vector<int>vis(v,0);
        vector<int>check(v,0);
        vector<int>ans;
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                dfs(vis,check,adj,i);
            }
        }
        for(int i=0;i<v;i++)
        {
            if(check[i]==0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
