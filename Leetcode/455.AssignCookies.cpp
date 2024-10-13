class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ch = 0;
        for (int i=0; i<s.size() && ch < g.size(); i++) {
            if (g[ch]<=s[i]) ch++;
        }

        return ch;
    }
};