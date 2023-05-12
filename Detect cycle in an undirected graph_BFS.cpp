//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        int visited[n]={0};
        
        
        queue<pair<int,int>>q;
        
                for(int i=0;i<n;i++)
                {
                    if(!visited[i])
                    {   
                        visited[i]=1;
                        q.push({i,-1});
                        while(!q.empty())
        {
            int item=q.front().first;
            int match=q.front().second;
            q.pop();
            for(auto it:adj[item])
            {
                if(!visited[it])
                {
                    visited[it]=1;
                    q.push({it,item});
                }
                else if(it!=match)
                {
                    return true;
                }
            }
        }
            

                    }
                }
            
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
