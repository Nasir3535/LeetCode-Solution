class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<int>seen;
        int l=0,len=0;
        for(int r=0;r<n;r++){
            while(seen.count(s[r])){
                seen.erase(s[l]);
                l++;
            }
            len = max(len,r-l+1);
            seen.insert(s[r]);
        }
        return len;
    }
};