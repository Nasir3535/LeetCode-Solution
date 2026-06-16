class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0,sum=0;
        for(int r=0;r<k;r++) sum+=nums[r];

        double max_sum=sum;
        for(int r=k;r<nums.size();r++){
            sum += nums[r]-nums[l];
            if(sum>max_sum) max_sum = sum;
            l++;
        }
        return max_sum/(k*1.0f);
    }
};