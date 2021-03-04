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

// PROBLEM:
// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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

// traversal of the tree is recursive to ensure travel down
// both the right and left children nodes 
var traversal = (root, depth) => {
    let current = root;
    let right;
    let left;
    if(!current) {
        return null;
    // this checks if the current node is a leaf node
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