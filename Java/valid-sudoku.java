/** 
 *  Problem Name : Valid Sudoku
 *  Concept Involved : 2D Array, Frequency Count
 * 
 *  Execution Time : 2 ms
 *  Memory Consumed : 38.8 mb
 * 
 *  Solution : We have been given with a Sudoku
 *  Puzzle, we have to determine whether the puzzle
 *  is valid or not.
 *  In order to check the validity every row and column
 *  of sudoku must have numbers from 0 to 9 and in a non
 *  repeating fashion and same for in every 3x3 block.
 *  I have used array based indexing to compute the 
 *  frequency of elements in every rows, columns and blocks
 *  and checking its validity afterwards.
 *  If every check is passed then we return True at the end.
*/
class Solution {
    public boolean isValid(ArrayList<Integer> arr){
        int[] fre = new int[10];
        for(int ele : arr){
            fre[ele]++;
            if(fre[ele] > 1){
                return false;
            }
        }
        return true;
    }
    public boolean isValidSudoku(char[][] board) {
        for(int i=0; i<9; i++){
            ArrayList<Integer> row = new ArrayList<>();
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    row.add(num);
                }
            }
            if(!isValid(row)){
                return false;
            }
        }
        
        for(int i=0; i<9; i++){
            ArrayList<Integer> col = new ArrayList<>();
            for(int j=0; j<9; j++){
                if(board[j][i] != '.'){
                    int num = board[j][i] - '0';
                    col.add(num);
                }
            }
            if(!isValid(col)){
                return false;
            }
        }
        
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                ArrayList<Integer> block = new ArrayList<>();
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(board[k][l] != '.'){
                            int num = board[k][l] - '0';
                            block.add(num);
                        }
                    }
                }
                if(!isValid(block)){
                    return false;
                }
            }
        }
        
        return true;
    }
}