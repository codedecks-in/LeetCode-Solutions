class Solution {
    public int minOperations(String[] logs) {
        int minOp = 0;
        
        for(int i=0; i<logs.length; i++){
            if(minOp >0 && logs[i].equals("../")){
                minOp--;
            }
            else if(logs[i].contains("/") && !logs[i].contains("./")){
                minOp++;
            }
        }
        return minOp;
    }
}
