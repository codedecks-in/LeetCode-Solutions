package testing;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//
//Notice that the solution set must not contain duplicate triplets.
//
// 
//
//Example 1:
//
//Input: nums = [-1,0,1,2,-1,-4]
//Output: [[-1,-1,2],[-1,0,1]]
//Example 2:
//
//Input: nums = []
//Output: []
//Example 3:
//
//Input: nums = [0]
//Output: []
// 
//
//Constraints:
//
//0 <= nums.length <= 3000
//-105 <= nums[i] <= 105

/*Runtime: 288 ms
Memory Usage: 44 MB
Difficulty Medium*/

class Threesum {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> a  = new HashSet<>();
        Arrays.sort(nums);
        if(nums.length==0) return new ArrayList<>(a);
        for(int i=0;i<nums.length-2;i++){
            if( i==0 || (nums[i-1]!=nums[i] && i>0)){
            int x=nums[i];
            Map<Integer,Integer> maps=new HashMap<Integer,Integer>();
            int target=0-x;
            for(int j=i+1;j<nums.length;j++){
                if(maps.containsKey(target-nums[j])){
                    a.add(Arrays.asList(x,target-nums[j],nums[j]));
                }else{
                    maps.put(nums[j],j);
                }
            }
            
        }}
        
        return new ArrayList<>(a);
    }
}