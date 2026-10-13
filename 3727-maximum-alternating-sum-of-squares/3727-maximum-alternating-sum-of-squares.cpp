class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int &x:nums){
            if(x<0) x = -x;
        }
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        long long ans=0;
        int mid = ceil(nums.size()/2.0);
        for(int i=0;i<n;i++){
            if(i<mid) ans += (nums[i]*nums[i]);
            else ans -= (nums[i]*nums[i]);
        }
        return ans;
    }
};