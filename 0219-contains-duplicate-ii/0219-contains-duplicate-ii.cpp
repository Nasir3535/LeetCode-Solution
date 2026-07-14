class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>seen;

        for(int l=0,r=0;r<nums.size();r++){ 
            if(r-l > k){
                seen.erase(nums[l]);
                l++;
            }
            if(seen.count(nums[r])) return 1;
            seen.insert(nums[r]);
        }
        return 0;
    }
};