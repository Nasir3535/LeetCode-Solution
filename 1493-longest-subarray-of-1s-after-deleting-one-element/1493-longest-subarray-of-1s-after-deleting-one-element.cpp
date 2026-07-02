class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt =0,len=0,n=nums.size(),max_len=0;

        for(int l=0,r=0;r<n;r++){
            if(nums[r] == 0) cnt++;
            while(cnt > 1){
                if(nums[l] == 0) cnt--;
                l++;
            }
            len = r-l+1-(cnt <= 2);
            max_len = max(max_len,len);
        }
        return max_len;
    }
};