class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();

        if(n==1) return 1;

        vector<pair<int,int>>vec;

        for(int i=0;i<n;i++)
        {
            vec.push_back({position[i],speed[i]});
        }

        sort(vec.begin(),vec.end(),[](const auto &a,const auto &b){
            return a.first>b.first;
        });

        vector<double>time_rem(n);

        for(int i=0;i<n;i++){
            time_rem[i]=((double)(target-vec[i].first))/vec[i].second;
        }
        double max_time=time_rem[0];
        int cnt_fleet=1;
        for(int i=1;i<n;i++){
            if(time_rem[i]>max_time){
                max_time=time_rem[i];
                cnt_fleet++;
            }
        }
        return cnt_fleet;


    }
};
