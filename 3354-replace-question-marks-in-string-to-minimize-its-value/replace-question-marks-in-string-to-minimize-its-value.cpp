typedef pair<int, char> pic;

class Solution {
public:
    string minimizeStringValue(string s) {
        array<int, 26> freq;
        int cnt = 0;

        for (int i=0; i<s.size(); i++) {
            if (s[i] != '?') {
                freq[s[i]-'a']++;
            }
            else {
                cnt++;
            }
        }

        priority_queue<pic, vector<pic>, greater<pic>> pq;

        for(int i=0; i<26; i++) {
            pq.push({freq[i], 'a' + i});
        }

        vector<char> reps(cnt);

        for (int i=0; i<cnt; i++) {
            auto [n, c] = pq.top();
            pq.pop();
            reps[i] = c;
            pq.push({n+1, c});
        }

        sort(reps.begin(), reps.end());

        for (int i=0, j=0; i<s.size(); i++) {
            if (s[i] == '?') {
                s[i] = reps[j++];
            }
        }

        return s;
    }
};
