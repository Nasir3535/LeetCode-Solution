class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string>seen;
        int i=0;
        while(i <= n-k){
            seen.insert(s.substr(i,k));
            i++;
        }
        return seen.size() == pow(2,k);
    }
};