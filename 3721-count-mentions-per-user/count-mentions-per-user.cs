public class Solution {
    public int[] CountMentions(int numberOfUsers, IList<IList<string>> events) {
        var mentions = new int[numberOfUsers];
        var offlineTill = new int[numberOfUsers];
        var allMentions = 0;

        events = events.OrderBy((x) => int.Parse(x[1])).ThenByDescending(y => y[0]).ToList();

        foreach (var ev in events) {
            var timestamp = int.Parse(ev[1]);
            Console.WriteLine(timestamp);
            if (ev[0] == "OFFLINE") {
                var user = int.Parse(ev[2]);
                offlineTill[user] = timestamp + 60;
            }
            else {
                if (ev[2].Equals("HERE")) {
                    for (var i=0; i<numberOfUsers; i++) {
                        if (offlineTill[i] <= timestamp) {
                            mentions[i]++;
                        }
                    }
                }
                else if (ev[2].Equals("ALL")) {
                    allMentions++;
                }
                else {
                    foreach (var id in ev[2].Split(' ')) {
                        var user = int.Parse(id.Substring(2));
                        mentions[user]++;
                    }
                }
            }
        }

        for (var i=0; i<numberOfUsers; i++) {
            mentions[i] += allMentions;
        }

        return mentions;
    }
}