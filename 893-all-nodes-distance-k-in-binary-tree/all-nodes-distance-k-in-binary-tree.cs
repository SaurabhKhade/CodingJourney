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
    public IList<int> DistanceK(TreeNode root, TreeNode target, int k) {
        var parents = new Dictionary<int, TreeNode>();
        var visited = new Dictionary<int, bool>();
        Traverse(root, parents, visited);

        var result = new List<int>();
        var queue = new Queue<(TreeNode node, int dist)>();
        queue.Enqueue((target, 0));
        visited[target.val] = true;

        while (queue.Count > 0) {
            var front = queue.Dequeue();
            if (front.dist == k) result.Add(front.node.val);

            if (front.node.left != null && !visited[front.node.left.val]) {
                visited[front.node.left.val] = true;
                queue.Enqueue((front.node.left, front.dist+1));
            }
            if (front.node.right != null && !visited[front.node.right.val]) {
                visited[front.node.right.val] = true;
                queue.Enqueue((front.node.right, front.dist+1));
            }
            if (parents.ContainsKey(front.node.val) && !visited[parents[front.node.val].val]) {
                visited[parents[front.node.val].val] = true;
                queue.Enqueue((parents[front.node.val], front.dist+1));
            }
        }

        return result;
    }

    void Traverse(TreeNode root, IDictionary<int, TreeNode> parents, IDictionary<int, bool> visited) {
        if (root == null) return;
        visited[root.val] = false;
        if (root.left != null) {
            parents[root.left.val] = root;
            Traverse(root.left, parents, visited);
        }
        if (root.right != null) {
            parents[root.right.val] = root;
            Traverse(root.right, parents, visited);
        }
    }
}