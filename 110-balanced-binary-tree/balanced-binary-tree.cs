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
    public bool IsBalanced(TreeNode root) {
        return Depth(root).Item1;
    }
    private (bool, int) Depth(TreeNode root) {
        if (root == null) {
            return (true, 0);
        }

        var left = Depth(root.left);
        var right = Depth(root.right);
        var height = Math.Max(left.Item2, right.Item2)+1;

        return (left.Item1 & right.Item1 & Math.Abs(left.Item2 - right.Item2) <= 1, height);
    }
}