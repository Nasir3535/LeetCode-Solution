class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        int i=0;
        while(i+10 <= s.size()){
            mp[s.substr(i,10)]++;
            i++;
        }
        vector<string>ans;
        for(auto it:mp){
            if(it.second > 1) ans.push_back(it.first);
        }
        return ans;
    }
};