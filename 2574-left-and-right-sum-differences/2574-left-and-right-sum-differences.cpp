class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int lsum = 0;
        int rsum = accumulate(nums.begin(),nums.end(),0);

        for(int i=0;i<nums.size();i++){
            rsum -= nums[i];
            ans[i] = abs(lsum-rsum);
            lsum += nums[i];
        }
        return ans;
    }
};