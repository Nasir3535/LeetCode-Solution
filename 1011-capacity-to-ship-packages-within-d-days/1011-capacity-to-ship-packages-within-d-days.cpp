class Solution {
public:
    bool Possible(vector<int>& weights,int cap,int days){
        int w=0,d = 0;
        for(int i=0;i<weights.size();i++){
            if(weights[i] > cap) return 0;
            if(weights[i]+w > cap){
                d++;
                w = weights[i];
            }
            else w += weights[i];
        }
        if(w>0) d++;
        return d <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1,high = accumulate(weights.begin(),weights.end(),0),ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(Possible(weights,mid,days)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};