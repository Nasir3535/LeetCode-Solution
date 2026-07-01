class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0,max_sum=0;
        int i=0;
        while(i < k){
            ans += cardPoints[i];
            i++;
        }
        i = k-1,max_sum = ans;
        int j=cardPoints.size()-1;
        while(i>=0){
            ans += (-cardPoints[i] + cardPoints[j]);
            i--; j--;
            max_sum = max(max_sum,ans);
        }
        return max_sum;
    }
};