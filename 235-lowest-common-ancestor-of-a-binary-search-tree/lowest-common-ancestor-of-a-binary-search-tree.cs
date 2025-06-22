/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return Helper(root, Math.Min(p.val, q.val), Math.Max(p.val, q.val));
    }

    private TreeNode Helper(TreeNode root, int p, int q) {
        if (p <= root.val && q >= root.val) return root;
        return Helper(p < root.val ? root.left : root.right, p, q);
    }
}