class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long cs = 0,ms=0;
        int l=0;
        unordered_set<int>seen;
        for(int r=0;r<nums.size();r++){
            cs += nums[r];
            while(seen.count(nums[r]) || seen.size()>=k){ 
                cs -= nums[l];
                seen.erase(nums[l]);
                l++;
            }
            if(k == r-l+1) ms = max(ms,cs);
            seen.insert(nums[r]);
        }
        return ms;
    }
};