class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n < m) return "";
        
        int len = INT_MAX, cnt = 0,stIndex=-1;;
        vector<int>hash(256);
        for(char ch:t) hash[ch]++;

        for(int l=0,r=0; r<n; r++){
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            while(cnt == m){
                if(r-l+1 < len){
                    len = r-l+1;
                    stIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
        }
        return (stIndex == -1)?"":s.substr(stIndex,len);
    }
};