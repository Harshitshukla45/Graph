class Solution {
public:
    void dfscall(vector<vector<int>> &vis ,vector<vector<char>>& b,int x,int y,int n,int m)
    {
        vis[x][y]=1;
        cout<<"("<<x<<","<<y<<")"<<" ";
                    if( x-1 >= 0)
                    {
                        if(b[x-1][y]=='O'&&!vis[x-1][y])
                        {
                            dfscall(vis,b,x-1,y,n,m);
                            
                        }
                    }
                    if(x+1 < n)
                    {
                        if(b[x+1][y]=='O'&&!vis[x+1][y])
                        {
                            dfscall(vis,b,x+1,y,n,m);
                            
                        }
                    }
                    if(y-1 >= 0)
                    {
                        if(b[x][y-1]=='O'&&!vis[x][y-1])
                        {
                            dfscall(vis,b,x,y-1,n,m);
                            
                        }
                    }
                    if( y+1 < m )
                    {
                        if(b[x][y+1]=='O'&&!vis[x][y+1])
                        {
                            dfscall(vis,b,x,y+1,n,m);
                            
                        }
                    }
                    return;

    }
    void solve(vector<vector<char>>& b) {
        int n=b.size();
        int m=b[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            if(b[i][0]=='O' && !vis[i][0])
            {
                dfscall(vis,b,i,0,n,m);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(b[0][i]=='O'&& !vis[0][i])
            {
                dfscall(vis,b,0,i,n,m);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(b[i][m-1]=='O' && !vis[i][m-1])
            {
                dfscall(vis,b,i,m-1,n,m);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(b[n-1][i]=='O' && !vis[n-1][i])
            {
                dfscall(vis,b,n-1,i,n,m);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && b[i][j]=='O')
                {
                    b[i][j]='X' ;
                }
            }
        }
    }
};
