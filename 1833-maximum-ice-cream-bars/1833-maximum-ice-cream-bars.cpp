class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i;
        for(i=0;i<costs.size();i++){
            if(coins >= costs[i]) coins-=costs[i];
            else return i;
        }
        return i;
    }
};