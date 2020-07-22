/**
* Binary Tree ZigZag level Order Traversal
* Medium
* 

Example 1:

Given a binary tree, return the zigzag level order traversal of its nodes' values.
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

* Logic : Using Breadth First Search to Solve This Problem.
          Using a boolean to push in front of array and in end of the array and toogle it after every level traversed
* Runtime: 80 ms
* Memory Usage: 37.6 MB
*
*/

var zigzagLevelOrder = function (root) {
  let queue = [],
    result = [],
    zigzag = true;
  if (root == null) return [];
  queue.push(root);
  while (queue.length) {
    let size = queue.length;
    let temp = [];
    while (size--) {
      let pop = queue.shift();
      if (pop && pop.left) queue.push(pop.left);
      if (pop && pop.right) queue.push(pop.right);
      if (zigzag) {
        if (pop) temp.push(pop.val);
      } else {
        if (pop) temp.unshift(pop.val);
      }
    }
    zigzag = !zigzag;
    result.push(temp);
  }

  return result;
};
