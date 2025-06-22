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

        var left = Helper(root.left);
        var right = Helper(root.right);

        maxSum = Max(maxSum, root.val, left + root.val, right+root.val, left+right+root.val);
        return Math.Max(left + root.val, Math.Max(right + root.val, root.val));
    }

    private int Max(int a, int b, int c, int d, int e) {
        return Math.Max(
            a, Math.Max(
                b, Math.Max(
                    c, Math.Max(
                        d, e
                    )
                )
            )
        );
    }
}