public class FirstMissingPositive {
    public static void main(String[] args) {
        int[] arr = {1, 2, 0};
        int[] arr1 = {1};
        System.out.println(firstMissingPositive(arr));
    }
    public static int firstMissingPositive(int[] nums) {
        CyclicSort(nums);
        for(int i=0;i<nums.length;i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return nums.length+1;
    }
    public static void CyclicSort(int nums[]){
        int i = 0;
        while(i < nums.length){
            if(nums[i] > 0 && nums[i] < nums.length){
                int correct = nums[i] - 1;
                if(nums[i] != nums[correct]){
                    swap(nums,i,correct);
                }
                else{
                    i++;
                }
            }
            else{
                i++;
            }
        }
    }
    public static void swap(int nums[], int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
