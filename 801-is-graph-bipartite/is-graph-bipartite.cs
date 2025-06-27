public class Solution {
    public bool IsBipartite(int[][] graph) {
        int n = graph.Count();
        int[] colors = new int[n];
        var q = new Queue<int>();

        for (int i=0; i<n; i++) {
            if (colors[i] == 0) {
                colors[i] = 1;

                q.Enqueue(i);

                while (q.Count > 0) {
                    int node = q.Dequeue();
                    int current = colors[node];
                    int next = current == 1 ? 2 : 1;

                    foreach (var link in graph[node]) {
                        if (colors[link] == 0) {
                            colors[link] = next;
                            q.Enqueue(link);
                        } else if (colors[link] == current) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
}