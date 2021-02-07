class Solution {
    public boolean detectCapitalUse(String word) {
        

//hello
        int upperCaseCount = 0;
        int lowerCaseCount = 0;
        
        int wordLen = word.length();
        
        int i = 0;
        int firstCharFlag = 0;
        
        for(i=0 ; i<wordLen; i++){
            int ch = word.charAt(i);
            
            if(ch >= 'a' && ch <= 'z'){
                lowerCaseCount++;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                upperCaseCount++;
                
                if(i == 0){
                    firstCharFlag++;
                }
            }
        }
        
        
        if(i == wordLen){
                if(lowerCaseCount == wordLen){
                    return true;
                }
                else if(upperCaseCount == wordLen){
                    return true;
                }
                else if(firstCharFlag == 1 && upperCaseCount == 1 && lowerCaseCount == (wordLen-1)){
                    return true;
                }
                else{
                    return false;
                }
        }
        
        return false;
    }
}
