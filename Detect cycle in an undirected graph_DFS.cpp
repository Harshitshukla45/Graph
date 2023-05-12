class Solution {
  public:


bool DFS(int node, int parent,unordered_map<int,bool> &vis,
    vector<int> adj[]){
        vis[node] = 1;
        // parent[node] = parentnode;
        for(auto neighbour:adj[node]){
            if(!vis[neighbour]){
                bool present = DFS(neighbour,node,vis,adj);
                if(present) return 1;
            }
            else if(neighbour!=parent) return 1;
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,bool> vis;
        
        for(int i =0;i<V;i++){
            if(!vis[i]){
                // bool present = DFS(i,-1,vis,adj);
                // if(present) return 1;
                bool present = BFS(i,adj,vis);
                if(present) return 1;
            }
        }
        return 0;
    }
};
