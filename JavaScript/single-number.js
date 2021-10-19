/**
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * Input: [2,2,1] Output: 1
 * 
 * Example 2:
 * 
 * Input: [4,1,2,1,2] Output: 4
 *
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    result= []
    nums.sort()
    
    nums.forEach(element => {
        if (result.indexOf(element) == -1){
            result.push(element)
        }else{
            result.splice(result.indexOf(element),1)
        }
    });

    return result[0]
};



//------- Test cases -----------------
// Input: nums = [2,2,1]
// Output: 1
console.log(`Example 01 = ${singleNumber([2,2,1])} expected Output 1.`)

// Input: nums = [4,1,2,1,2]
// Output: 4
console.log(`Example 02 = ${singleNumber([4,1,2,1,2])} expected Output 4.`)

// Input: nums = [1]
// Output: 1
console.log(`Example 03 = ${singleNumber([1])} expected Output 1.`)
