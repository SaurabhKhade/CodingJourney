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
    public int AmountOfTime(TreeNode root, int start) {
        var parents = new Dictionary<int, TreeNode>();
        var visited = new Dictionary<int, bool>();
        
        var q1 = new Queue<TreeNode>();
        q1.Enqueue(root);

        TreeNode startNode = null;

        while (q1.Any()) {
            var front = q1.Dequeue();
            visited.Add(front.val, false);
            if (front.left != null) {
                parents.Add(front.left.val, front);
                q1.Enqueue(front.left);
            }
            if (front.right != null) {
                parents.Add(front.right.val, front);
                q1.Enqueue(front.right);
            }
            if (front.val == start) {
                startNode = front;
            }
        }

        var time = 0;
        var q = new Queue<(TreeNode, int)>();
        q.Enqueue((startNode, 0));
        visited[start] = true;

        while (q.Any()) {
            var (front, dist) = q.Dequeue();
            time = dist;

            if (front.left != null && !visited[front.left.val]) {
                visited[front.left.val] = true;
                q.Enqueue((front.left, dist+1));
            }
            if (front.right != null && !visited[front.right.val]) {
                visited[front.right.val] = true;
                q.Enqueue((front.right, dist+1));
            }
            if (parents.ContainsKey(front.val) && !visited[parents[front.val].val]) {
                visited[parents[front.val].val] = true;
                q.Enqueue((parents[front.val], dist+1));
            }
        }

        return time;
    }
}