public class Solution {
    public int[] DailyTemperatures(int[] temp) {
        var stack = new Stack<(int, int)>();
        int n = temp.Length;

        var result = new int[n];

        for(int i=0; i<n; i++) {
            while (stack.Count > 0 && stack.Peek().Item1 < temp[i]) {
                var top = stack.Pop();
                result[top.Item2] = (i-top.Item2);
            }
            stack.Push((temp[i], i));
        }

        while (stack.Count > 0) {
            var top = stack.Pop();
            result[top.Item2] = 0;
        }

        return result;
    }
}