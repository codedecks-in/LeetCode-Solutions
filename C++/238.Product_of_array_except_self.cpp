/*
    This code uses prefix and postfix product to evaluate answer.
    We just need to traverse the array twice, once to the left and once to the right.
    Then answer of ith place can be calculated using constant time.

    Time Complexity : O(n)
    Space Complexity : O(n)
*/



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); //Variable for size of the array
        //pre[] stores product of all numbers to the left of ith element
        //post[] stores product of all numbers to the right of ith element
        int pre[n],post[n]; 
        
        //loop to assign values to pre[]
        int mul=1;
        for(int i=0; i<n; i++){
            mul*=nums[i];
            pre[i]=mul;
        }
        
        //loop to assign values to post[]
        mul=1;
        for(int i=n-1; i>=0; i--){
            mul*=nums[i];
            post[i]=mul;
        }
        
        //declare a vector to return
        vector <int> out;
        
        //first element of out is just going to be product of all elements except first one
        out.push_back(post[1]);
        
        //value of out[i] = product of all elements except ith element
        //which is nothing but pre[i-1]*[post[i+1]]
        for(int i=1; i<n-1; i++){
            int p=i-1;
            int s=i+1;
            out.push_back(pre[p]*post[s]);
        }
        
        //last element of out is just going to be product of all elements except last one
        out.push_back(pre[n-2]);
        
        //return the vector
        return out;
    }
};