/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public void Flatten(TreeNode root) {
        Helper(root);
    }

    TreeNode Helper(TreeNode root) {
        if (root == null) return root;

        var left = Helper(root.left);
        var right = Helper(root.right);

        root.left = null;

        if (left != null) {
            root.right = left;
            while (left.right != null) left = left.right;
            left.right = right;
        }
        else {
            root.right = right;
        }

        return root;
    }
}