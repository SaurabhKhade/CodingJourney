public class SlidingWindowMaximum {
    private int limit;
    private readonly LinkedList<(int, int)> list;

    public SlidingWindowMaximum(int limit) {
        this.limit = limit;
        list = new LinkedList<(int, int)>();
    }

    public void Insert(int index, int value) {
        while (list.Count > 0 && list.Last.Value.Item1 < value) {
            list.RemoveLast();
        }

        list.AddLast((value, index));
    }

    public int Get(int index) {
        var boundry = index-limit+1;
        while (list.First.Value.Item2 < boundry) list.RemoveFirst();
        return list.First.Value.Item1;
    }
}

public class Solution {
    public int[] MaxSlidingWindow(int[] nums, int k) {
        var maximum = new SlidingWindowMaximum(k);
        int[] result = new int[nums.Count()-k+1];

        for (int i=0; i<k; i++) {
            maximum.Insert(i, nums[i]);
        }
        result[0] = maximum.Get(k-1);

        for (int i=k; i<nums.Count(); i++) {
            maximum.Insert(i, nums[i]);
            result[i-k+1] = maximum.Get(i);
        }

        return result;
    }
}
