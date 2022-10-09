import java.util.ArrayList;
import java.util.List;

public class ReverseOddLevelsOfBinaryTree {
    /**
        Store all the level's data in a list by simply any traversal(pre-order here)
        Then again traverse the tree and when found the odd level,
        change the root data with the last element of the level-list and remove the last item
    */
    public TreeNode reverseOddLevels(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        tra(list, root, 0);
        modify(list, root, 0);
        return root;
    }
    private void modify(List<List<Integer>> res, TreeNode root, int level){
        if(root == null) return;

        // Odd level
        if((level%2) != 0){

            // Modify root data with last item of list, and then remove the last item
            List<Integer> lvlArr = res.get(level);
            root.val = lvlArr.get(lvlArr.size()-1);
            lvlArr.remove(lvlArr.size()-1);
        }

        modify(res,root.left,level+1);
        modify(res,root.right,level+1);
    }

    // generate list with level-order items
    private void tra(List<List<Integer>> res, TreeNode root, int level){
        if(root == null) return;

        if(level >= res.size())
            res.add(new ArrayList<>());

        res.get(level).add(root.val);
        tra(res,root.left,level+1);
        tra(res,root.right,level+1);
    }

    static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;

        public TreeNode() {}
        TreeNode(int val) { this.val = val; }
        public TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
}
