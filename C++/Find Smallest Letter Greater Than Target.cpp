class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = (letters.size()-1);
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(letters[mid]>target){
                high=--mid;
            }
            else{
                low=++mid;
            }
        }
        return letters[low % letters.size()];
    }
};
