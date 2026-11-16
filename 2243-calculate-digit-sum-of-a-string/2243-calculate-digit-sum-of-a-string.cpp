class Solution {
public:
    string sumofdigits(string s,int k){
        string newString = "";
        int sm=0;
        for(int i=0;i<s.size();i++){
            if(i>0 && i%k==0){ 
                newString += to_string(sm);
                sm = 0;
            }
            sm += (s[i]-'0');
        }
        newString += to_string(sm);
        return newString;
    }
    string digitSum(string s, int k) {
        while(s.size() > k){
            s = sumofdigits(s,k);
        }
        return s;
    }
};