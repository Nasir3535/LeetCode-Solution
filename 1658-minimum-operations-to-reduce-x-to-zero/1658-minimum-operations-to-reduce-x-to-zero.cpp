class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(),nums.end(),0) - x;
        if(target < 0) return -1;
        if(target == 0) return nums.size();

        int l = 0,len = 0;
        int cs = 0;
        for(int r=0;r<nums.size();r++){
            cs += nums[r];
            while(cs > target){
                cs -= nums[l];
                l++;
            }
            if(cs == target) len = max(len,r-l+1);
        }
        
        return (len>0)? (nums.size()-len): -1;
        
    }
};