class Solution {
public:
    bool check(char ch){
        return (ch>= 65 && ch<=90) || (ch>= 97 && ch<=122) || (ch>= 48 && ch<=57);
    }
    bool isPalindrome(string s) {
        int i = 0;
        while(i<s.size()){
            if(check(s[i])) i++;
            else s.erase(i,1);
        }

        int l=0,r = s.size()-1;
        while(l<r){
            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;r--;
        }
        return 1;
    }
};