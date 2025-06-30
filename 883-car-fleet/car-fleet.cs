public class Solution {
    public int CarFleet(int target, int[] position, int[] speed) {
        var list = new List<(int, int)>();

        for (int i=0; i<position.Length; i++) {
            list.Add((position[i], speed[i]));
        }

        list.Sort((a, b) => b.Item1.CompareTo(a.Item1));

        int fleets = 0;
        double minTime = 0;
        foreach(var car in list) {
            var time = (double)(target - car.Item1)/car.Item2;

            if (time > minTime) {
                minTime = time;
                fleets++;
            }
        }

        return fleets;
    }
}
