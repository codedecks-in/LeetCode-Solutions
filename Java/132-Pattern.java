class Solution {
    public boolean find132pattern(int[] nums) {
        Stack<Integer> st = new Stack<>();
        int thrd =Integer.MIN_VALUE;
        st.push(nums[nums.length-1]);
        for(int i=nums.length-2;i>=0;i--){
            if(nums[i]<thrd){
                return true;
            }
            while(!st.isEmpty() && nums[i]>st.peek()){
                thrd=st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
}
