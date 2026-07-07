class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return 0;
        vector<int>freq(26),windfreq(26);
        for(char ch:s1) freq[ch-'a']++;
        for(int i=0;i<s1.size();i++) windfreq[s2[i]-'a']++;
        
        if(windfreq == freq) return 1;
        for(int l=0,r=s1.size();r<s2.size();l++,r++){
            windfreq[s2[r]-'a']++;
            windfreq[s2[l]-'a']--;
            if(freq == windfreq) return 1;
        }
        return 0;

    }
};