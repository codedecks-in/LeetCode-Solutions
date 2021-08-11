// 1877. Minimize Maximum Pair Sum in Array

class Solution {
    public int minPairSum(int[] arr) {
        int n = arr.length;
        int max = Integer.MIN_VALUE;
        Arrays.sort(arr);
        int low = 0;
        int high = arr.length-1;
        while(low<high){
            max = Math.max(max, arr[high]+ arr[low]);
            low++;
            high--;
        }
        //System.out.println(max);
        return max;
    }
}
