class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        int c=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        while(!q.empty())
        {
            int x=q.front().first,y=q.front().second;
            if(x==-1 && y==-1)
            {
                c++;
                cout<<c<<" ";
                q.pop();
                if(q.empty())
                {
                    break;
                }
                else
                {
                    q.push({-1,-1});
                    continue;
                }
            }
            else
            {
                q.pop();

            }
                    
            if( x-1 >= 0)
            {
                if( grid[x-1][y]==1)
                {
                    q.push(make_pair(x-1,y));
                    grid[x-1][y]=2;
                            
                }
            }
            if(x+1 < n)
            {
                if(grid[x+1][y]==1)
                {
                    q.push(make_pair(x+1,y));
                    grid[x+1][y]=2;       
                }
            }
            if(y-1 >= 0)
            {
                if(grid[x][y-1]==1)
                {
                    q.push(make_pair(x,y-1));
                    grid[x][y-1]=2;
                            
                }
            }
            if( y+1 < m )
            {
                if(grid[x][y+1]==1)
                {
                    q.push(make_pair(x,y+1));
                    grid[x][y+1]=2;
                            
                }
            }  
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }

        return c-1;
    }
};
