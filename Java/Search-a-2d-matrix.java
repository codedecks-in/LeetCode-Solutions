class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        
        if(matrix.length == 0 || matrix[0].length == 0){
            return false;
        }
        
        if(matrix[matrix.length-1][matrix[0].length-1] < target){
            return false;
        }
        
        for(int i=0; i<matrix.length; i++){
            for(int j=0; j<matrix[i].length; j++){
                
                if(matrix[i][j] > target){
                    return false;
                }
                else if(matrix[i][j] == target){
                    return true;
                }
                else{
                    continue;
                }
            }
        }
        
        return false;
    }
}
