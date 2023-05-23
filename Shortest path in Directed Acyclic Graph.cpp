//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void findTopoSort(int node, vector < int > & vis, stack < int > & st, vector < pair<int,int> > adj[]) {
    vis[node] = 1;

    for (auto it: adj[node]) {
      if (!vis[it.first]) {
        findTopoSort(it.first, vis, st, adj);
      }
    }
    st.push(node);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        stack < int > st;
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
      vector < int > vis(N, 0);
      for (int i = 0; i < N; i++) {
        if (vis[i] == 0) {
          findTopoSort(i, vis, st, adj);
        }
      }
      
      vector < int > topo(N,1e9);
      topo[0]=0;
      while (!st.empty()) {
        int x=st.top();
        st.pop();
        for(auto it:adj[x])
        {
            int v= it.first;
            int wt=it.second;
            if(topo[x]+wt < topo[v])
            {
                topo[v]=topo[x]+wt ;
            }
        }
        
      }
      
        for(int i=0;i<N;i++)
        {
            if(topo[i]==1e9)
            {
                topo[i]=-1;
            }
        }
      
      return topo;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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
