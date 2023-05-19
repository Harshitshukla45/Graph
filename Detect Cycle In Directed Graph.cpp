//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<int> &vis,vector<int>&check,vector<int> adj[],int x)
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
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int>vis(v,0);
        vector<int>check(v,0);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                if(dfs(vis,check,adj,i))
                {
                    return true;
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
