/*Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

Time - O(N)
Space - O(1)

*/

public List<Integer> rightSideView(TreeNode root) {
        
        List<Integer> list = new ArrayList<>();
        if(root == null) {return list; }
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int temp = 0;
        while(!q.isEmpty()){
            int qsize = q.size();
            for(int i=0; i<qsize; i++){
                TreeNode child = q.poll();
                temp = child.val;
                if(child.left != null){
                    q.offer(child.left);
                }
                if(child.right != null){
                    q.offer(child.right); 
                }
            }
            list.add(temp);
        }
        return list;
    