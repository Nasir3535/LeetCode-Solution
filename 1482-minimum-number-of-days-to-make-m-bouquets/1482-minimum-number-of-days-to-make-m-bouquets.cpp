class Solution {
public:
    using ll = long long;
    bool Possible(vector<int>& bloomDay,ll mindays,int m,int k){
        int cnt = 0,number_of_bouqets = 0;
        for(int i = 0; i<bloomDay.size();i++){
            if(bloomDay[i] <= mindays) cnt++;
            else{ 
                number_of_bouqets += cnt/k;
                cnt = 0;
            }
        }
        number_of_bouqets += cnt/k;
        return number_of_bouqets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        ll low=1,high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans =-1;
        while(low <= high){
            ll mid = low+ (high-low)/2;
            if(Possible(bloomDay,mid,m,k)){
                ans = mid;
                high = mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};