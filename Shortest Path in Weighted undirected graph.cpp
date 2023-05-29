//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int M, vector<vector<int>>&edges) {
        // Code here
        vector<int>vis(n+1,0);
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>dist(n+1,1e9);
        for(auto e : edges){
            adj[e[0]].push_back({e[1],e[2]});
             adj[e[1]].push_back({e[0],e[2]});
        }
        vector<int>parent(n+1,-1);
        set<pair<int,int>>s;
        s.insert({0,1});
        dist[1]=0;
        parent[1]=1;
        while(!s.empty()){
            auto src = *(s.begin());
            auto node = src.second;
            auto dis = src.first;
            s.erase(src);
            if(vis[node])continue;
            vis[node]=1;
            for(auto i : adj[node]){
                auto adjNode = i.first;
                auto adjDist = i.second;
              
                if(dist[node]+adjDist < dist[adjNode]){
                    if(dist[adjNode]!=1e9){
                        s.erase({dist[adjNode],adjNode});
                    }
                    
                    dist[adjNode]=dist[node]+adjDist;
                    s.insert({dist[adjNode],adjNode});
                  
                    parent[adjNode]=node;
                    
                }
            }
        }
       
      
            
        vector<int>ans;
        if(parent[n]==-1)return {-1};
        auto node = n;
        while(parent[node]!=node){
            if(parent[node]==-1)return {-1};
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
