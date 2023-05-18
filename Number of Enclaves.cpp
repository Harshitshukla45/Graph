class Solution {
public:
void dfscall(vector<vector<int>> &vis ,vector<vector<int>>& b,int x,int y,int n,int m)
    {
        vis[x][y]=1;
        cout<<"("<<x<<","<<y<<")"<<" ";
                    if( x-1 >= 0)
                    {
                        if(b[x-1][y]==1 &&!vis[x-1][y])
                        {
                            dfscall(vis,b,x-1,y,n,m);
                            
                        }
                    }
                    if(x+1 < n)
                    {
                        if(b[x+1][y]==1 &&!vis[x+1][y])
                        {
                            dfscall(vis,b,x+1,y,n,m);
                            
                        }
                    }
                    if(y-1 >= 0)
                    {
                        if(b[x][y-1]==1 &&!vis[x][y-1])
                        {
                            dfscall(vis,b,x,y-1,n,m);
                            
                        }
                    }
                    if( y+1 < m )
                    {
                        if(b[x][y+1]==1 &&!vis[x][y+1])
                        {
                            dfscall(vis,b,x,y+1,n,m);
                            
                        }
                    }
                    return;

    }
    int numEnclaves(vector<vector<int>>& b) {
        int n=b.size();
        int m=b[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            if(b[i][0]==1 && !vis[i][0])
            {
                dfscall(vis,b,i,0,n,m);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(b[0][i]==1 && !vis[0][i])
            {
                dfscall(vis,b,0,i,n,m);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(b[i][m-1]==1  && !vis[i][m-1])
            {
                dfscall(vis,b,i,m-1,n,m);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(b[n-1][i]==1  && !vis[n-1][i])
            {
                dfscall(vis,b,n-1,i,n,m);
            }
        }
        int c=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && b[i][j]==1)
                {
                    c++ ;
                }
            }
        }
        return c;
    }
    
};
