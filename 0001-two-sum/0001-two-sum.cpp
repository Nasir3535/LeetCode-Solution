class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int>ans;
       int n = nums.size();

       unordered_map<int,int>mp;
       for(int i=0; i<n ;i++){
            int comp = target-nums[i];
            if(mp.find(comp) != mp.end()){
                ans = {mp[comp],i};
                return ans;
            }
            mp[nums[i]] = i;
       }
       return {};
    }
};