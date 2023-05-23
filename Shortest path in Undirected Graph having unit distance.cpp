//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int find_distance(vector<int>&parent,int src,int des)
  {
      int flag=1;
      int count=0;
    //   ans.push_back(des);
      while(src!=des)
      {
           if(des==-1)
       { 
          flag=0;
          break;
           
       }
          des=parent[des];
        //   ans.push_back(des);
       
       
        count++;
        
      }
      if(flag==0)
      return -1;
      else
      return count;
  }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // creating an undirected graph at first;
        vector<int>ans;
        int visited[N]={0};
        vector<int>parent(N,0);
        vector<int>adj[N];
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        q.push(src);
        parent[src]=-1;
        visited[src]=1;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            for(auto j : adj[front])
            {
                if(!visited[j])
             {   
                 parent[j]=front;
                 visited[j]=true;
                 q.push(j);
                 
             }
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(visited[i])
            {
                ans.push_back(find_distance(parent,src,i));
            }
            else
            {
                ans.push_back(-1);
            }
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }

 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
