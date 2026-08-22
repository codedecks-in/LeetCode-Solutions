class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        
        ArrayList<Integer> result = new ArrayList<>();
        
        for (int i=0; i<nums1.length; i++){
            result.add(nums1[i]);
        }
        
        for (int i=0; i<nums2.length; i++) {
            result.add(nums2[i]);
        }
        
        Collections.sort(result);
        
        int start=0;
        int end = result.size() - 1;
        
        
        while(end>start) {
            if (start == end) {
                break;
            }
            start++;
            end--;
        } 

        return (double) (result.get(start) + result.get(end))/2;
    }
} 