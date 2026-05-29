class Solution {
public:
    int Sum_of_digits(int n){
        int sum=0;
        while(n){
            sum = sum + n%10;
            n = n/10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int x:nums){
            ans = min(ans,Sum_of_digits(x));
        }
        return ans;
    }
};