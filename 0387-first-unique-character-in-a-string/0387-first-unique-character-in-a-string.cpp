class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>freq;
        for(char ch:s) freq[ch]++;
        
        int i = 0;
        for(auto& ch:s){
            if(freq[ch] == 1)   return i;
            i++;
        }
        return -1;
    }
};