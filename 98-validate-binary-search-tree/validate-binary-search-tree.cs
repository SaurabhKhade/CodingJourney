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
    bool isValid = true;
    int? prev = null;

    public bool IsValidBST(TreeNode root) {
        if (root == null) return true;
        if (!isValid) return false;

        IsValidBST(root.left);

        Console.WriteLine(root.val);

        if (!isValid || (prev != null && root.val <= prev.Value)) {
            isValid = false;
            return false;
        }

        prev = root.val;

        return IsValidBST(root.right);
    }

    private Tuple<bool, int?, int?> Helper(TreeNode root) {
        if (root == null) return new Tuple<bool, int?, int?>(true, null, null);

        var left = Helper(root.left);
        var right = Helper(root.right);

        if (
            !left.Item1 ||
            !right.Item1 ||
            (left.Item3 != null && left.Item3 >= root.val) ||
            (right.Item2 != null && right.Item2 <= root.val))
            return new Tuple<bool, int?, int?>(false, null, null);

        var min = left.Item2 != null ? left.Item2 : root.val;
        var max = right.Item3 != null ? right.Item3 : root.val;

        return new Tuple<bool, int?, int?>(true, min, max);
    }
}