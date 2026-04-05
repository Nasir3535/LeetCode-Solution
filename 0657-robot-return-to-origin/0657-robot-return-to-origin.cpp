class Solution {
public:
    bool judgeCircle(string moves){
        int ver = 0;
        int hor = 0;
        for(char ch:moves){
            if(ch == 'U') ver++;
            if(ch == 'D') ver--;
            if(ch == 'L') hor--;
            if(ch == 'R') hor++;
        }
        return (ver == 0 && hor == 0);
    }
};