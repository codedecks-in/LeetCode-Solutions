public List<List<Integer>> permute(int[] nums) {
    List<List<Integer>> result = new ArrayList<>();
    helper(0, nums, result);
    return result;
}
 
private void helper(int start, int[] nums, List<List<Integer>> result)
{
    if(start==nums.length-1){
        ArrayList<Integer> list = new ArrayList<>(); //if starting value(say n) is the last value , this will make a new list with the values and the new starting value is n
        for(int num: nums)
        {
            list.add(num);
        }
        result.add(list);
        return;
    }
 
    for(int i=start; i<nums.length; i++)      //a loop to keep on swapping as many times as there are values in the list 
    {
        swap(nums, i, start);
        helper(start+1, nums, result);
        swap(nums, i, start);
    }
}
 
private void swap(int[] nums, int i, int j)
{
    int temp = nums[i];      //temp temporarily holds the value of nums so that i & j values can be exchanged
    nums[i] = nums[j];
    nums[j] = temp;
}
