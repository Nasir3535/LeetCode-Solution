class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return 0;
        unordered_map<char,int>hash;
        for(int i = 0;i < s.size();i++){
            hash[s[i]]++;
            hash[t[i]]--;
        }
        for(auto it:hash){
            if(it.second != 0)  return 0;
        }
        return 1;
    }
};