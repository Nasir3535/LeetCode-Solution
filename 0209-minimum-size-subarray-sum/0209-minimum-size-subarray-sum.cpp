class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = 1e6;
        int sum = 0;
        for(int l=0,r=0;r<nums.size();r++){
            if(nums[r] >= target) return 1;
            sum += nums[r];
            while(sum >= target){
                len = min(len,r-l+1);
                sum -= nums[l];
                l++;
            }
        }
        return (len!=1e6)?len:0;
    }
};