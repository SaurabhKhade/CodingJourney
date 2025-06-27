public class Solution {
    public bool PossibleBipartition(int n, int[][] dislikes) {
        var graph = new List<int>[n+1];

        for (int i=0; i<=n; i++) {
            graph[i] = new List<int>();
        }

        foreach (var value in dislikes) {
            graph[value[0]].Add(value[1]);
            graph[value[1]].Add(value[0]);
        }


        var groups = new int[n+1];
        var q = new Queue<int>();

        for (int i=0; i<n; i++) {
            if (groups[i] == 0) {
                groups[i] = 1;
                q.Enqueue(i);

                while (q.Count > 0) {
                    var person = q.Dequeue();
                    int current = groups[person];
                    int next = current == 1 ? 2 : 1;

                    foreach (var other in graph[person]) {
                        if (groups[other] == 0) {
                            groups[other] = next;
                            q.Enqueue(other);
                        } else if (groups[other] == current) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
}