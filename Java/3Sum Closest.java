//16. 3Sum Closest

class Solution {
    public int threeSumClosest(int[] arr, int target) {
        Arrays.sort(arr);
        int n = arr.length;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n-2 && min!=0; i++) {
            int low = i+1;
            int high = n-1;
            while(low<high){
                int sum = arr[i]+arr[low]+arr[high];
                if(Math.abs(target - sum) < Math.abs(min)){
                    min = target-sum;
                }
                if(sum<target){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
        return target-min;
        //System.out.println(target- min);
    }
}
