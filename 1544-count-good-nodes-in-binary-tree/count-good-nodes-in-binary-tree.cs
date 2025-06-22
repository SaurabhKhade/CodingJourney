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
    private int goodNodes;
    public int GoodNodes(TreeNode root) {
        goodNodes = 0;
        Helper(root, root.val);
        return goodNodes;
    }

    public void Helper(TreeNode root, int max) {
        if (root == null) return;

        if (root.val >= max) goodNodes++;

        Helper(root.left, Math.Max(max, root.val));
        Helper(root.right, Math.Max(max, root.val));
    }
}