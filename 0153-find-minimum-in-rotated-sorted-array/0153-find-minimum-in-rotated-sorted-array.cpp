class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1,ans=INT_MAX;
        if(nums[l]<nums[h]) return nums[0];
        while(l<=h){
            if(nums[l]<nums[h]) ans=min(ans,nums[l]);
            int mid=l+(h-l)/2;
            ans=min(ans,nums[mid]);
            if(nums[l]<=nums[mid]) l=mid+1;
            else h=mid;
            ans=min(ans,nums[mid]);
        }
        return ans;
    }
};