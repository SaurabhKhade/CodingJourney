public class Solution {
    public string MinimizeStringValue(string s) {
        var sb = new StringBuilder(s);
        var freq = new int[26];
        var cnt = 0;

        for (int i=0; i<s.Length; i++) {
            if (s[i] != '?') {
                freq[((int)s[i]) - 97]++;
            }
            else {
                cnt++;
            }
        }

        var pq = new PriorityQueue<int, (int, int)>();

        for(int i=0; i<26; i++) {
            pq.Enqueue(i, (freq[i], i));
        }

        var reps = new char[cnt];

        for (int i=0; i<cnt; i++) {
            var top = pq.Dequeue();
            reps[i] = (char)(top+97);
            freq[top]++;
            pq.Enqueue(top, (freq[top], top));
        }

        Array.Sort(reps);

        for (int i=0,j=0; i<s.Length; i++) {
            if (sb[i] == '?') {
                sb[i] = reps[j++];
            }
        }

        return sb.ToString();
    }

    // private string minimumString(int[] freq, int cnt) {
    //     // var cmp = new Comparator<(int, int)>.Create((x , y) => {
    //     //     if (x.Item1 == y.Item1) return x.Item2.CompareTo(y.Item2);
    //     //     return x.Item1.CompareTo(y.Item1);
    //     // });
    //     var chars = new char[cnt];
    //     var pq = new PriorityQueue<int, (int, int)>();

    //     for(int i=0; i<26; i++) {
    //         pq.Enqueue(i, (freq[i], i));
    //     }

    //     for (int i=0; i<cnt; i++) {
    //         var top = pq.Dequeue();
    //         Console.WriteLine($"{top} => {freq[top]} => {(char)(top+97)}");
    //         chars[i] = (char)(top+97);
    //         freq[top]++;
    //         pq.Enqueue(top, (freq[top], top));
    //     }

    //     Array.Sort(chars);

    //     return new String(chars);
    // }
}
