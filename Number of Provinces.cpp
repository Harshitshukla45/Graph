class Solution {
public:
    void dfs(int item,vector<int> &visited,vector<vector<int>> &adj)
    {
        visited[item]=1;
        for(int i=0;i<adj[item].size();i++)
        {
            if(adj[item][i]==1 && !visited[i])
            {   
                dfs(i,visited,adj);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& adj) {
        
        int s=adj[0].size();
        vector<int>visited(s,0);
        int c=0;
        for(int i=0;i<visited.size();i++)
        {
            if(!visited[i])
            {   
                c++;
                dfs(i,visited,adj);
            }
        }
        return c;
    }
};
