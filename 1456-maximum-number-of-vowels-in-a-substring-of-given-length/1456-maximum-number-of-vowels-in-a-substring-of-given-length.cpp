class Solution {
public:
    bool vowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int maxVowels(string s, int k) {
        int l=0,len=0;
        int cnt=0,ans=0;
        for(int r=0;r<k;r++){
            if(vowel(s[r])) cnt++;
            ans=cnt; 
        }

        for(int r=k;r<s.size();r++){
            if(vowel(s[r])) cnt++;
            if(vowel(s[l])) cnt--;
            ans = max(ans,cnt);
            l++;
        }
        return ans;
    }
};