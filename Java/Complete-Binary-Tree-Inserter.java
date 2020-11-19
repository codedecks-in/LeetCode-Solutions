/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class CBTInserter {
    TreeNode root;
    Queue<TreeNode> q = new LinkedList<TreeNode>(); 
    // This queue is a helper to reduce load on insert function.. 
    public CBTInserter(TreeNode root) {
        this.root = root;
        Queue<TreeNode> temp = new LinkedList(q);
        temp.add(root);
        q.add(root);
        // Prepare a queue for the for our insert function...
        while(!temp.isEmpty()){
            TreeNode t = temp.poll();
            if(t.left!=null){
                temp.add(t.left);
                q.add(t.left);
            }
            if(t.right!=null){
                temp.add(t.right);
                q.add(t.right);
            }
        }
    }
    
    
    public int insert(int v) {
        TreeNode n = new TreeNode(v);
        n.left = n.right = null;
        TreeNode parent = null;
        // Add new node to the queue...
        q.add(n);
        while(true){
            parent = q.peek();
            // If the node's left is null then, insert there.
            if(parent.left==null){
                parent.left = n;
                break;
            }
            // If the node's right is null then, insert there....
            // Now this node can never become parent of new node, so remove it from the queue
            if(parent.right==null){
                parent.right = n;
                q.poll();
                break;
            }
            // else it means the node has left and right children which are not null... so remove it from queue.
            q.poll();
        }
        // Return the parent's value to the caller function...
        return parent.val;
    }
    
    public TreeNode get_root() {
        return root;
    }
}
