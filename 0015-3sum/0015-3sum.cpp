class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>>seen;

        sort(nums.begin(),nums.end());

        for(int i = 0 ;i < nums.size(); i++){
            int comp = (-1)*nums[i];
            int l = i+1 ;
            int r = nums.size()-1;

            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum == comp){
                    vector<int>temp={nums[i],nums[l],nums[r]};
                    seen.insert(temp);
                    l++;
                }
                else if( sum > comp) r--;
                else l++;
            }
            
        }
        
        return vector<vector<int>>(seen.begin(),seen.end());

    }
};