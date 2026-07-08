class Solution {
public:
    using ll = long long;

    ll total_hours(vector<int>& piles,int k){
        ll th = 0;
        for(int i=0;i<piles.size();i++){
            th += ceil((double)piles[i]/k);
        }
        return th;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        ll low = 1,high = *max_element(piles.begin(),piles.end());
        ll ans = 0;
        while(low<=high){
            ll mid = low + (high-low)/2;
            ll th = total_hours(piles,mid);
            if(th <= h){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
        
    }
};