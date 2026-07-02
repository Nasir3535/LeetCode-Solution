class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt =0,len=0,n=nums.size();

        for(int l=0,r=0;r<n;r++){
            if(nums[r] == 0) cnt++;
            while(cnt > 1){
                if(nums[l] == 0) cnt--;
                l++;
            }
            len = max(len,r-l);
        }
        return len;
    }
};