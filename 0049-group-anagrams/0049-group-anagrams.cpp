class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>group;
        for(string word:strs){
            string key = word;
            sort(key.begin(),key.end());
            group[key].push_back(word);
        }
        
        vector<vector<string>>ans;

        for(auto& [k,v]:group){
            ans.push_back(v);
        }

        return ans;
    }
};