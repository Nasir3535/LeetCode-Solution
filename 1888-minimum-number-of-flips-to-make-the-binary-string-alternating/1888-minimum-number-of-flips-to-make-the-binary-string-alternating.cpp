class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string doubled = s + s;
        int len = doubled.size(); 

        string patA = "", patB = "";
        for (int i = 0; i < len; i++) {
            patA += (i % 2 == 0) ? '0' : '1';
            patB += (i % 2 == 0) ? '1' : '0'; 
        }

        int costA = 0, costB = 0;
        for (int i = 0; i < n; i++) {
            if (doubled[i] != patA[i]) costA++;
            if (doubled[i] != patB[i]) costB++;
        }

        int ans = min(costA, costB);

        for (int i = n; i < len; i++) {
            
            if (doubled[i] != patA[i]) costA++;
            if (doubled[i] != patB[i]) costB++;

            if (doubled[i - n] != patA[i - n]) costA--;
            if (doubled[i - n] != patB[i - n]) costB--;

            ans = min({ans, costA, costB});
        }

        return ans;
    }
};