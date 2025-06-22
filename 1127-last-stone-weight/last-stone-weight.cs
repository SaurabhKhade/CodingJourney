public class Solution {
    public int LastStoneWeight(int[] stones) {
        var pq = new PriorityQueue<int, int>();

        foreach (var w in stones) {
            pq.Enqueue(w, -w);
        }

        while (pq.Count > 1) {
            var a = pq.Dequeue();
            var b = pq.Dequeue();

            if (a != b) {
                pq.Enqueue(a-b, b-a);
            }
        }

        return pq.Count == 1 ? pq.Peek() : 0;
    }
}