//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   
	public:
	int findupar(int node,vector<int> &parent)
	{
	    if(node==parent[node]) 
	    {
	        return node;
	    }
	    parent[node]=findupar(parent[node],parent);
	}
	void unionbyrank(int x,int y,vector<int> &rank,vector<int> &parent)
	{
	    int upx = findupar(x,parent);
	    int upy = findupar(y,parent);
	    if(upx==upy)
	    {
	        return;
	    }
	    if(rank[upx]>rank[upy])
	    {
	        parent[upy]=upx;
	    }
	    else if(rank[upx]<rank[upy])
	    {
	        parent[upx]=upy;
	    }
	    else{
	        parent[upx]=upy;
	        rank[upx]++;
	    }
	    
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Disjoint-set
        vector<int>rank(V+1,0);
	    vector<int>parent(V+1);
	    for(int i=0;i<=V;i++)
	    {
	        parent[i]=i;
	    }
	    
	    
        int mst=0;
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                edges.push_back({it[1],{i,it[0]}});
            }
        }
        sort(edges.begin(),edges.end());
        for(auto it:edges)
        {
            int w=it.first;
            int f=it.second.first;
            int t=it.second.second;
            if(findupar(f,parent)!=findupar(t,parent))
            {
                mst += w;
                unionbyrank(f,t,rank,parent);
            }
            
        }
        return mst;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
