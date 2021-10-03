//https://leetcode.com/contest/weekly-contest-247/problems/cyclically-rotating-a-grid/

// Very nice problem!

class Solution {
    public int[][] rotateGrid(int[][] a, int K) {
        int n = a.length, m = a[0].length;
        for(int T = 0, D = n-1, L = 0, R = m-1;L <= R && T <= D;T++,D--,L++,R--){
            int pe = 2*(n-1-T*2) + 2*(m-1-T*2);
            int lk = K % pe;
            for(int t = 0;t < lk;t++){
                int temp = a[T][L];
                for(int s = L+1;s <= R;s++){
                    a[T][s-1] = a[T][s];
                }
                for(int s = T+1;s <= D;s++){
                    a[s-1][R] = a[s][R];
                }
                for(int s = R-1;s >= L;s--){
                    a[D][s+1] = a[D][s];
                }
                for(int s = D-1;s >= T+1;s--){
                    a[s+1][L] = a[s][L];
                }
                a[T+1][L] = temp;
            }
        }
        return a;
    }
}
