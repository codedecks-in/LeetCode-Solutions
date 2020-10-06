class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        
        //Easy for Binary search on smaller length array
        //Checking the length and calling the main Function with smaller len array as forst array
        if(nums1.length > nums2.length){
           return findMedianSortedArrays(nums2,nums1);
        }
        
        int len1 = nums1.length;
        int len2 = nums2.length;
         //System.out.println(len1 + " " + len2);
    
        //Doing Binary search on smaller array
        int start = 0;
        int end = len1;
        while(start<=end){
          int partion1 = (start+end)/2;
          int partion2 = ((len1+len2+1)/2 - partion1);
            
            //finding the max and min lenemt is num1 array
            int max1 = (partion1 == 0 ) ? Integer.MIN_VALUE : nums1[partion1-1];
            int min1 = (partion1 == len1) ? Integer.MAX_VALUE : nums1[partion1];
            
            //finding the max and min elemnt of nums2 array
            int max2 = (partion2 == 0 ) ? Integer.MIN_VALUE : nums2[partion2-1];
            //System.out.println(Integer.MIN_VALUE + " "  + Integer.MAX_VALUE);
            int min2 = (partion2 == len2) ? Integer.MAX_VALUE : nums2[partion2];
            
            if(max1 <= min2 && max2 <= min1){ 
                if((len1 + len2 ) %2 == 0){
                    return (double)(Math.max(max1, max2) + Math.min(min1, min2))/2;
                }else{
                    return (double)Math.max(max1,max2);
                }
            }else if( max1 > min2){
              end = partion1 - 1;
            }else{
                start = partion1 + 1;
            }
       }
        return 0;
    }
}
