class DisjointSet {
    public int Components {get; private set;}
    private int[] parents;
    private int[] size;

    public DisjointSet(int n) {
        Components = n;
        parents = new int[n];
        size = new int[n];

        for (int i=0; i<n; i++) {
            parents[i] = i;
            size[i] = 1;
        }
    }

    public int FindRoot(int num) {
        if (parents[num] == num) return num;
        return parents[num] = FindRoot(parents[num]);
    }

    public void Union(int a, int b) {
        var x = Math.Min(a, b);
        var y = Math.Max(a, b);

        var rootX = FindRoot(x);
        var rootY = FindRoot(y);

        if (rootX == rootY) return;

        if (size[rootX] > size[rootY]) {
            size[rootX] += size[rootY];
            parents[rootY] = rootX;
        } else {
            size[rootY] += size[rootX];
            parents[rootX] = rootY;
        }

        Components--;
    }
}

public class Solution {
    public int MinCost(int n, int[][] edges, int k) {
        var comparer = Comparer<int[]>.Create((a, b) => {
            if (a[2] == b[2]) return a[0].CompareTo(b[0]);
            return a[2].CompareTo(b[2]);
        });

        Array.Sort(edges, comparer);
        var set = new DisjointSet(n);
        int i=0;
        int mx = 0;

        while (set.Components > k && i < edges.Length) {
            set.Union(edges[i][0], edges[i][1]);
            mx = Math.Max(mx, edges[i][2]);
            i++;
        }

        if (set.Components == k) return mx;
        return -1;
    }
}
