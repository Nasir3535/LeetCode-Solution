class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size()-1;
        vector<int>v;
        for(int i=1;i<=n;i++) v.push_back(i);
        v.push_back(n);
        sort(nums.begin(),nums.end());
        return nums == v;
    }
};