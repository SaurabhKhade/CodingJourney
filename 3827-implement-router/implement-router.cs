public class Router
{
    HashSet<string> hashSet;
    Queue<int[]> queue;
    IDictionary<int, IList<int>> scheduled;
    IDictionary<int, int> received;
    int limit;

    public Router(int memoryLimit)
    {
        limit = memoryLimit;
        queue = new Queue<int[]>();
        hashSet = new HashSet<string>();
        scheduled = new Dictionary<int, IList<int>>();
        received = new Dictionary<int, int>();
    }

    public bool AddPacket(int source, int destination, int timestamp)
    {
        var key = source + "-" + destination + "-" + timestamp;
        var packet = new int[] { source, destination, timestamp };
        if (hashSet.Contains(key)) return false;
        hashSet.Add(key);
        queue.Enqueue(packet);
        limit--;

        if (scheduled.ContainsKey(destination))
        {
            scheduled[destination].Add(timestamp);
        }
        else
        {
            received[destination] = 0;
            scheduled[destination] = new List<int> { timestamp };
        }

        if (limit < 0)
        {
            limit = 0;
            var oldest = queue.Dequeue();
            received[oldest[1]]++;
            hashSet.Remove(oldest[0] + "-" + oldest[1] + "-" + oldest[2]);
        }

        return true;
    }

    public int[] ForwardPacket()
    {
        if (queue.Count == 0) return new int[] { };

        limit++;
        var packet = queue.Dequeue();
        received[packet[1]]++;
        hashSet.Remove(packet[0] + "-" + packet[1] + "-" + packet[2]);
        return packet;
    }

    public int GetCount(int destination, int startTime, int endTime)
    {
        if (!scheduled.ContainsKey(destination)) return 0;

        var list = scheduled[destination];
        int n = list.Count;

        
        // Console.WriteLine($"{received[destination]} {n-1} {string.Join(',', list)}");

        if (received[destination] == n || list[0] > endTime || list[n-1] < startTime) return 0;

        var firstPacketIndex = GTE(list, startTime, received[destination], n-1);
        var lastPacketIndex = LTE(list, endTime, received[destination], n-1);

        int count = lastPacketIndex - firstPacketIndex + 1;

        // Console.WriteLine($"{firstPacketIndex} {lastPacketIndex}");

        return Math.Max(count, 0);
    }

    private int LTE(IList<int> list, int time, int left, int right)
    {
        int index = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int element = list[mid];

            // if (element == time) return mid;
            if (element <= time)
            {
                left = mid + 1;
                index = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        return index;
    }

    private int GTE(IList<int> list, int time, int left, int right)
    {
        int index = right;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int element = list[mid];

            // if (element == time) return mid;
            if (element < time)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
                index = mid;
            }
        }

        return index;
    }
}

/**
 * Your Router object will be instantiated and called as such:
 * Router obj = new Router(memoryLimit);
 * bool param_1 = obj.AddPacket(source,destination,timestamp);
 * int[] param_2 = obj.ForwardPacket();
 * int param_3 = obj.GetCount(destination,startTime,endTime);
 */