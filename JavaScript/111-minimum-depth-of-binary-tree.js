/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */

 // test cases:
 // [3,9,20,null,null,15,7] -- output: 2
// [2,null,3,null,4,null,5,null,6] -- output: 5
// [0] -- output: 1
// []  -- output: 0


var minDepth = function(root) {
    if(root) {
        return traversal(root, 1);
    } else { return 0 }
};

var traversal = (root, depth) => {
    let current = root;
    let right;
    let left;
    if(!current) {
        return null;
    } if (!current.right && !current.left) {
        return depth;
    }
        right = traversal(current.right, depth+1)
        left = traversal(current.left, depth+1)
    if(!right) {
        return left;
    } else if(!left) {
        return right;
    } else {
        if(right < left) {
        return right
    } else { 
    return left 
    }   
    }
}