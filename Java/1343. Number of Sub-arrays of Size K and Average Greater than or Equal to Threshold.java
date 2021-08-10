// Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold...

class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        List<Integer> list = new ArrayList<>();
        int n = arr.length;
        int current_sum = 0;
        for (int i = 0; i < k; i++) {
            current_sum = current_sum+arr[i];
        }
        int count = 0;
        if((current_sum/(float)k)>=threshold){
            count++;
        }
        list.add(current_sum);
        for (int i = k; i < n; i++) {
            current_sum = current_sum+arr[i] - arr[i-k];
            if((current_sum/(float)k)>=threshold){
                count++;
            }
        }
        return count;
        //System.out.println(count);
    }
}
