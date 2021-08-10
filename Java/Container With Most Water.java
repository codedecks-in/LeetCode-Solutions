//Container With Most Water
class Solution {
    public int maxArea(int[] arr) {
        int n = arr.length;
        int max = 0;
        
        int l = 0;
        int h = n-1;
        while(l<h){
            max = Math.max(max, (Math.min(arr[l],arr[h]))*(h-l));
            if(arr[l]<arr[h]){
                l++;
            }
            else{
                h--;
            }
        }
        return max;
        
    
}
}
