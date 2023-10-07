class Solution {
public:
    int trap(vector<int>& h) {
        int total = 0, l = 0, r = h.size() - 1,
            left_max = h[l], right_max = h[r];
        
        while(l + 1 < r)
        {
            if (h[l] <= h[r])
            {
                ++l;
                total += max(0, left_max - h[l]);
                left_max = max(left_max, h[l]);
            } else {
                --r;
                total += max(0, right_max - h[r]);
                right_max = max(right_max, h[r]);
            }
        }

        return total;    
    }
};

/*Complexity
Time complexity:O(n) Space complexity:O(1)
*/