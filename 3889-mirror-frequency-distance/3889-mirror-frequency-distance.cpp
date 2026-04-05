#3889
class Solution {
public:
    char Mirror(char ch){  
    if (ch >= 'a' && ch <= 'z')     return 'z' - (ch - 'a'); 
    else if(ch >='A' && ch <= 'Z')  return 'Z' - (ch - 'A');
    else        return '9' - (ch - '0'); 
}

    int mirrorFrequency(string s) {
        int ans = 0;

    unordered_map<char,int>freq;
    for(char ch:s) freq[ch]++;

    unordered_set<char>seen;
    for(char ch : s){
        char m = Mirror(ch);
        if(seen.count(ch) || seen.count(m)) continue;
        seen.insert(ch);
        int f1 = freq[ch];
        int f2 = freq[m];

        ans += abs(f1-f2);
    }
    return ans;
    }
};