class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        
        while (l <= r) {
            int mid = l + (r-l)/2;
            int midElem = nums[mid];
            
            if (midElem == target) {
                return mid;
            }
            
            int leftElem = nums[l];
            int rightElem = nums[r];
           
            if (leftElem == target) { // Similar to check above
                return l;
            } else if (rightElem == target) {
                return r;
            }
            
            if (midElem < rightElem) { // Soft inquiry to the right portion of mid
                if (midElem < target && target <= rightElem) { // Intial inquiry was correct! & this portion is not rotated
                    l = mid + 1;
                } else { // Upon further examination, we'll look into the left portion of mid instead
                    r = mid - 1;
                }
                   
            } else { // Soft inquiry to the left portion of mid
                if (midElem > target && target >= leftElem) { // Inquiry was correct! We'll further investigate the left portion of mid & this portion is not rotated
                    r = mid - 1;
                } else { // Initial inquiry was incorrect, instead we will investigate the right portion of mid
                    l = mid + 1;
                }
            }
        } 
        return -1;
    }
};
