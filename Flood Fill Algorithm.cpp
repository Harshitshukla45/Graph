class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){       
        int n=image.size();
        int m= image[0].size();
        int nvis=image[sr][sc];
        if(nvis==color)
        {
            return image;
        }
        stack<pair<int,int>>st;
        st.push({sr,sc});
        while(!st.empty())
        {
                  int x=st.top().first,y=st.top().second;
                    st.pop();
                    image[x][y]=color;
                    cout<<image[x][y]<<" ";
                    if( x-1 >= 0)
                    {
                        if( image[x-1][y]==nvis)
                        {
                            st.push(make_pair(x-1,y));
                            
                        }
                    }
                    if(x+1 < n)
                    {
                        if(image[x+1][y]==nvis)
                        {
                            st.push(make_pair(x+1,y));
                            
                        }
                    }
                    if(y-1 >= 0)
                    {
                        if(image[x][y-1]==nvis)
                        {
                            st.push(make_pair(x,y-1));
                            
                        }
                    }
                    if( y+1 < m )
                    {
                        if(image[x][y+1]==nvis)
                        {
                            st.push(make_pair(x,y+1));
                            
                        }
                    }
                
        }

        return image;
    }
};
