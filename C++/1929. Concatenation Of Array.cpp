class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> answer; // TO STORE FINAL RESULT
        
        // LOOP THROUGH THE VECTOR ONCE AND STORES THE ELEMENTS IN RESULT VECTOR
        for(int i = 0; i < nums.size(); i++){
            answer.push_back(nums[i]);
        }
        
        // LOOP THROUGH THE VECTOR AGAIN AND STORES THE ELEMENTS IN RESULT VECTOR ONCE MORE 
        for(int i = 0; i < nums.size(); i++){
            answer.push_back(nums[i]);
        }
        
        // FINALLY answer CONTAINS THE CONCATENATED ARRAY        
        return answer;
    }
};
/* EX: nums = {1, 2, 1}
   wHILE LOOPING THROUGH nums ONCE answer = {1, 2, 1}
   AGAIN TRAVERSING IT MAKES THE answer = {1, 2, 1, 1, 2, 1}
   WHICH IS OUR REQUIRED ANSWER
   
   ANALYSIS-:
       FOR LOOPING TWICE TIME COMPLEXITY IS O(N) + O(N) WHICH IS ASYMPTOTICALLY O(N)
       SINCE NO EXTRA SPACE IS USED, HENCE SPACE COMPLEXITY = O(1)
*/
