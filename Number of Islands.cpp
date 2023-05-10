class Solution {
public:
    int numIslands(vector<vector<char>>&avg ) {
        int n=avg.size();
        int m=avg[0].size();
        int c=0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++)
        { 
            for(int j=0;j<m;j++)
            {   
                if(avg[i][j]=='1'  && !vis[i][j])
                {
                    st.push(make_pair(i,j));
                while(!st.empty())
                {
                    int x=st.top().first,y=st.top().second;
                    st.pop();
                    vis[x][y]=1;
                    if( x-1 >= 0)
                    {
                        if( avg[x-1][y]=='1'&& !vis[x-1][y])
                        {
                            st.push(make_pair(x-1,y));
                            
                        }
                    }
                    if(x+1 < n)
                    {
                        if(avg[x+1][y]=='1' && !vis[x+1][y])
                        {
                            st.push(make_pair(x+1,y));
                            
                        }
                    }
                    if(y-1 >= 0)
                    {
                        if(avg[x][y-1]=='1' && !vis[x][y-1])
                        {
                            st.push(make_pair(x,y-1));
                            
                        }
                    }
                    if( y+1 < m )
                    {
                        if(avg[x][y+1]=='1' && !vis[x][y+1])
                        {
                            st.push(make_pair(x,y+1));
                            
                        }
                    }
                }
                c++;
                    
                }
                
                
            }
        }
        return c;
    }
};
