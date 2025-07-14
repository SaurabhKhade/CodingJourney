public class Solution {
    public int MatchPlayersAndTrainers(int[] players, int[] trainers) {
        int trainer = 0, matches = 0;
        Array.Sort(players);
        Array.Sort(trainers);
        
        foreach (int player in players) {
            while (trainer < trainers.Count() && trainers[trainer] < player) {
                trainer++;
            }
            if (trainer == trainers.Count()) break;
            else {
                matches++;
                trainer++;
            }
        }

        return matches;
    }
}