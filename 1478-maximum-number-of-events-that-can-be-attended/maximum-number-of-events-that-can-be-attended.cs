public class Solution {
    public int MaxEvents(int[][] events) {
        var comparer = Comparer<int[]>.Create((x, y) => {
            return x[0].CompareTo(y[0]);
        });
        Array.Sort(events, comparer);

        int day = 1;
        int i = 0;
        int meetings = 0;
        var pq = new PriorityQueue<int, int>();

        while (i < events.Length || pq.Count > 0) {
            while (i < events.Length && events[i][0] == day) {
                // Console.WriteLine($"{day} => [{events[i][0]},{events[i][1]}]");
                pq.Enqueue(events[i][1], events[i][1]);
                i++;
            }
            while (pq.Count > 0 && pq.Peek() < day) {
                // Console.WriteLine($"{day} => Peek: {pq.Peek()}");
                pq.Dequeue();
            }
            if (pq.Count > 0) {
                pq.Dequeue();
                meetings++;
            }
            day++;
        }

        return meetings;
    }
}

