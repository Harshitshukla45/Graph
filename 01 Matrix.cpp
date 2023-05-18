class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        
        while(!q.empty())
        {
            int dis=q.front().second;
            int x=q.front().first.first;
            int y=q.front().first.second;
            cout<<dis<<" ";
            q.pop();
            ans[x][y]=dis;
                    if( x-1 >= 0)
                    {
                        if(mat[x-1][y]==1&&!vis[x-1][y])
                        {
                            q.push({{x-1,y},dis+1});
                            vis[x-1][y]=1;
                            
                        }
                    }
                    if(x+1 < n)
                    {
                        if(mat[x+1][y]==1&&!vis[x+1][y])
                        {
                            q.push({{x+1,y},dis+1});
                            vis[x+1][y]=1;
                            
                        }
                    }
                    if(y-1 >= 0)
                    {
                        if(mat[x][y-1]==1&&!vis[x][y-1])
                        {
                            q.push({{x,y-1},dis+1});
                            vis[x][y-1]=1;
                            
                        }
                    }
                    if( y+1 < m )
                    {
                        if(mat[x][y+1]==1&&!vis[x][y+1])
                        {
                            q.push({{x,y+1},dis+1});
                            vis[x][y+1]=1;
                            
                        }
                    }
                


        }
        return ans;
    }
};
