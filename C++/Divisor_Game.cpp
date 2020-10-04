class Solution {
public:
    bool divisorGame(int N) {
        int count =0;
        for(int i=1;i<N;){
            if(N%i == 0){
                N -=i;
                    count++;
            }
        }
        if(count % 2 == 0)
            return false;
        else
            return true;
    }
};
