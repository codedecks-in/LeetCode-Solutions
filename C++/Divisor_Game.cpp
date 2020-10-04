class Solution {
public:
    bool divisorGame(int N) {
        // initialize count to zero
        int count =0;
        // every time one play a move we will start from zero
        for(int i=1;i<N;){
            if(N%i == 0){
                N -=i;
                    count++;
            }
        }
        // If it's even Bob will win, as bob move in even
        if(count % 2 == 0)
            return false;
        else
            return true;
    }
};
