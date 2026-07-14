class Solution {
public:
    bool Allzero(vector<int>hash){// Means it is Anagram
        for(int x:hash) if(x!=0) return 0;
        return 1;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int>hash(26);
        vector<int>ans;
        if(p.size() > s.size()) return ans;

        for(char ch:p)  hash[ch-'a']++;

        for(int r=0;r<p.size();r++)  hash[s[r]-'a']--;
        if(Allzero(hash)) ans.push_back(0);

        for(int l=0,r=p.size();r<s.size();r++,l++){
            hash[s[r]-'a']--;
            hash[s[l]-'a']++;
            if(Allzero(hash)) ans.push_back(l+1);
        }
        return ans;
    }
};