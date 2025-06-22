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
    public bool IsValidBST(TreeNode root) {
        return Helper(root).Item1;
    }

    private Tuple<bool, int?, int?> Helper(TreeNode root) {
        if (root == null) return new Tuple<bool, int?, int?>(true, null, null);

        var left = Helper(root.left);
        var right = Helper(root.right);

        // Console.WriteLine(root.val.ToString());
        // Console.WriteLine($"Left: {left.Item1}\t{left.Item2}\t{left.Item3}\t");
        // Console.WriteLine($"Right: {right.Item1}\t{right.Item2}\t{right.Item3}\t");
        // Console.WriteLine();

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