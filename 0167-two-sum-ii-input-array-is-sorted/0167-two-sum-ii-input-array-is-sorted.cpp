class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int l=0,r=numbers.size()-1;
        while(l<r){
            int sum = numbers[l]+numbers[r];
            if(sum == target){
                ans = {l+1,r+1};
                return ans;
            }
            if(sum < target) l++;
            else r--;
        }
        return {};
    }
};