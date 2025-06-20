class Solution {
public:
    int maxDistance(string str, int k) {
        int n=0, w=0, s=0, e=0, mx=0;

        for (const char &chr: str) {
            if (chr == 'N') n++;
            else if (chr == 'W') w++;
            else if (chr == 'S') s++;
            else e++;

            int dist = abs(n-s) + abs(w-e);
            int changes = min(k, min(n,s) + min(w,e));

            mx = max(mx, dist + changes*2);
        }

        return mx;
    }
};


