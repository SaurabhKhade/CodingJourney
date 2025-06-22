public class Solution {
    public int[][] KClosest(int[][] points, int k) {
        var list = new List<int[]>(points);

        list.Sort((a, b) => {
            var dist1 = a[0]*a[0] + a[1]*a[1];
            var dist2 = b[0]*b[0] + b[1]*b[1];

            return dist1.CompareTo(dist2);
        });

        return list.Take(k).ToArray();
    }
}