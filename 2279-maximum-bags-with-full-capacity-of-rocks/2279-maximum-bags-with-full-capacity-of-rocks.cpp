class Solution {
public:
    using ll = long long;
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i=0;i<capacity.size();i++){
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(),capacity.end());

        ll sum = 0,cnt = 0;
        for(int i=0;i<capacity.size();i++){
            if(sum + capacity[i] <= additionalRocks){ 
                sum +=  capacity[i];
                cnt++;
            }
            else return cnt;
        }
        return cnt;
    }
};