// 420-strong-password-checker.cpp
// Problem: https://leetcode.com/problems/strong-password-checker/
//

class Solution {
public:
    int strongPasswordChecker(string password) {
        int x = password.size();
        bool lower = false;
        bool upper = false;
        bool digit = false;

        for(char i:password){
            if(islower(i)){
                lower = true;
            }
            if (isupper(i)){
                upper = true;
            }
            if(isdigit(i)){
                digit = true;
            }
        }
        
        int miss = !lower + !upper + !digit;
        int change = 0;
        int one = 0;
        int two = 0;

        for (int i =2;i<x;i++){
            if (password[i]==password[i-1] && password[i-1]==password[i-2]){
                int j = i;
                while (j < x && password[j]== password[i-2]){
                    j++;
                }
                int len = j -(i-2);
                change +=len/3;
                if(len % 3 == 0){
                    one++;
                }
                else if(len %3 == 1){
                    two++;
                }
                i = j - 1;
            }
        }

        if (x<6){ //CASE 1: TOO SHORT
            return max(miss,6-x);
        }

        else if(x <=20){ //CASE 2: IDEAL RANGE
            return max(miss,change);
        }

        else{ //REST, CASE 3: TOO LONG
            int del = x -20;
            change = change - min(del,one);
            change = change - min(max(0,del-one), two *2)/2;
            change = change - max(0,del-one-two*2)/3;
            return del + max(miss, change);
        }
    }
};