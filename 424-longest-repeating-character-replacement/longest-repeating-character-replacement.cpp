class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> map(26);
        int mxWindow = 0;
        int i=0, j=0, sum = 0, mx = 0;

        for (; j<s.size(); j++) {
            map[s[j]-'A']++;

            sum++;
            mx = mx > map[s[j]-'A'] ? mx : map[s[j]-'A'];

            if((sum-mx) > k) {
                map[s[i]-'A']--;
                i++;
                sum--;

                // while (isWindowReached(map, k)) {
                //     map[s[i]-'A']--;
                //     i++;
                // }

                // sum = 0, mx = 0;

                for (int i:map) {
                    mx = mx > i ? mx : i;
                }
            }

            mxWindow = max(mxWindow, j-i+1);
        }

        return mxWindow;
    }

    bool isWindowReached(vector<int> &map, int limit) {
        int mx = 0;
        int sum = 0;

        for (int i:map) {
            mx = mx > i ? mx : i;
            sum += i;
        }

        return (sum-mx) > limit;
    }
};
