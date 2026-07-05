class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>time(n+1,1e9);
        time[k]=0;

        vector<vector<pair<int,int>>>adj(n+1);

        for(auto edge:times){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];

            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,k});

        while(!pq.empty()){
            int currTime=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(currTime>time[node])
            continue;

            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgWt=it.second;

                if(currTime+edgWt<time[adjNode]){
                    time[adjNode]=currTime+edgWt;
                    pq.push({time[adjNode],adjNode});
                }
            }
        }

        int ans=-1e9;
        for(int i=1;i<=n;i++){
            if(time[i]==1e9)
            return -1;
            ans=max(ans,time[i]);
        }
        return ans;
    }
};
