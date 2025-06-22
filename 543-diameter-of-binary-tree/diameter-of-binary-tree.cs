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
    private int diameter = 0;
    public int DiameterOfBinaryTree(TreeNode root) {
        diameter = 0;
        Depth(root);
        return diameter;
    }

    private int Depth(TreeNode root) {
        if (root == null) return 0;

        var left = Depth(root.left);
        var right = Depth(root.right);

        diameter = Math.Max(diameter, left + right);
        return Math.Max(left, right) + 1;
    }
}