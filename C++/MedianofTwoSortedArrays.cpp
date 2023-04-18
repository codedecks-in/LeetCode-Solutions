class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Create an empty vector to hold the combined values of nums1 and nums2
        vector<int>v3;

        // Add all values in nums1 to v3
        for(auto x : nums1){
            v3.push_back(x);
        }

        // Add all values in nums2 to v3
        for(auto x : nums2){
            v3.push_back(x);
        }

        // Sort the combined vector
        sort(v3.begin(),v3.end());

        // Check if the size of the vector is even
        if (v3.size() % 2 == 0){

            // Find the middle two elements of the vector using the nth_element function
            nth_element(v3.begin(),
                        v3.begin() + v3.size() / 2,
                        v3.end());
            nth_element(v3.begin(),
                        v3.begin() + (v3.size() - 1) / 2,
                        v3.end());

            // Calculate and return the average of the middle two elements
            return (double)(v3[(v3.size() - 1) / 2]
                            + v3[v3.size() / 2])
                   / 2.0;
        }
  
        // If the size of the vector is odd
        else {

            // Find the middle element of the vector using the nth_element function
            nth_element(v3.begin(),
                        v3.begin() + v3.size() / 2,
                        v3.end());

            // Return the middle element as the median
            return (double)v3[v3.size() / 2];
        }
    }
};
