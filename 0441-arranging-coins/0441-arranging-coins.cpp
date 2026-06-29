class Solution {
public:
    int arrangeCoins(int n) {
        long long l=0,h=n,ans=INT_MIN;
        while(l <= h){
            long long mid = l+(h-l)/2;
            if((double)(mid*(mid+1))/2 <= n){
                ans = mid;
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return ans;
    }
};