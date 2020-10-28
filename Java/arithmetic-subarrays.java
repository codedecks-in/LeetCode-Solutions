/** 
 *  Problem Name : Arithmetic Subarrays
 *  Concept Involved : Maths, Interval Count, Array
 * 
 *  Execution Time : 500 ms
 *  Memory Consumed : 40.6 mb
 * 
*/
class Solution {
    public int getValue(int ele){
        if(ele < 0){
            return 100000 - ele;
        }
        return ele;
    }
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        int m = l.length;
        ArrayList<Boolean> res = new ArrayList<>();
        
        for(int i=0; i<m; i++){
            int li = l[i];
            int ri = r[i];
            
            int maxel = Integer.MIN_VALUE;
            int minel = Integer.MAX_VALUE;
            int[] index = new int[200001];
            
            for(int j=li; j<=ri; j++){
                maxel = Math.max(maxel, nums[j]);
                minel = Math.min(minel, nums[j]);
                
                int ele = (nums[j] < 0) ? 100000 - nums[j] : nums[j];
                index[ele]++;
            }
            
            int diff = maxel - minel;
            int subs = ri-li;
            
            if(diff%subs == 0){
                int jump = diff/subs;
                int start = minel;
                while((start+jump) <= maxel && index[getValue(start+jump)] == 1){
                    start += jump;
                }
                if(start < maxel){
                    res.add(false);
                }
                else{
                    res.add(true);
                }
            }
            else{
                res.add(false);
            }
        }
        
        return res;
    }
}