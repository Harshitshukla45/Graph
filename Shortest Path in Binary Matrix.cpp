class Solution {
public:
bool visit[101][101];
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // base conditions
        if(grid[n-1][m-1]==1 || grid[0][0]==1){
            return -1;
        }

        queue<vector<int>>Q;
        Q.push({0,0,1});
        visit[0][0] = true;
        int ans = 1;
//  to traverse in all 8 directions right , left , top , bottome , and 4 diagonal positions
            int direction[8][8] = {{0,1},{1,0},{-1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}};


        while(!Q.empty()){
            vector<int>front = Q.front();
            Q.pop();
            // distance of path  from start to end  
            ans = max(ans , front[2]);

            // another stopping conditions 
            if(front[0]==n-1 && front[1]==m-1){
                break;
            }
            // traverse in all 8 directions
            for(int i =0 ; i<8 ; i++){
                int x = front[0] + direction[i][0];
                int y = front[1] + direction[i][1];
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y]==1 || visit[x][y]== true){
            continue;
        }
        if(grid[x][y]==0){
            Q.push({x,y,1+front[2]});
        visit[x][y] = true;
        
        }
            }

        }

        // check if last cell is visited or not 
if(visit[n-1][m-1]==false){
    return -1;
}


return ans;
    }
};
