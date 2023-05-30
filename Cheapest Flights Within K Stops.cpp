class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int sc, int dst, int k) {
        int v = flights.size();
        queue<pair<int,pair<int,int>>>q;
        vector<int> dist(n);
        for(int i=0;i<n;i++)
        dist[i]=1e9;
        
        q.push({0,{sc,0}});
        while(!q.empty()){

            int node = q.front().second.first;
            int dis = q.front().second.second;
            int stop = q.front().first;
            q.pop();

            if(stop==k+1)
            {   
                continue;
            }

            for(int i=0;i<v;i++)
            {
                if(flights[i][0]==node)
                {
                    int tg = flights[i][1];
                    int val = flights[i][2];
                    if(val+dis < dist[tg])
                    {
                        dist[tg]=val+dis;
                        
                        q.push({stop+1,{tg,dist[tg]}});
                    }
                }
            }

        }
        
        cout<<endl;
        if(dist[dst]==1e9)
        {
            return -1;
        }
        return dist[dst];

    }
};
