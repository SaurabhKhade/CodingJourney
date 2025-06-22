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
    private int maxSum;
    public int MaxPathSum(TreeNode root) {
        maxSum = root.val;
        Helper(root);
        return maxSum;
    }

    private int Helper(TreeNode root) {
        if (root == null) return 0;

        var left = Math.Max(Helper(root.left), 0);
        var right = Math.Max(Helper(root.right), 0);

        maxSum = Math.Max(maxSum, root.val + left + right);
        return Math.Max(left, right) + root.val;
    }
}