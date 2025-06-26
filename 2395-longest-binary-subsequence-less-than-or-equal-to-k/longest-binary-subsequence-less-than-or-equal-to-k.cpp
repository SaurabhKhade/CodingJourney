class Solution {
public:
    int longestSubsequence(string s, int k) {
       int num = 0, i = s.size()-1, len = 0;

        while (i >= 0) {
            int bit = s[i] - '0';
            int position = s.size()-i-1;
            if (bit == 1 && position <= 30) {

                // if (position > 30) continue;

                int newNumber = (1 << position) + num;

                if (newNumber <= k) {
                    num = newNumber;
                    len++;
                }
            }
            else if (bit == 0) {
                len++;
            }
            i--;
        }

        return len;
    }

    // int helper(string &s, int k, int ind, int num, vector<unordered_map<int, int>> &dp) {
    //     if (ind == s.size()) return 0;
    //     if (dp[ind].find(num) != dp[ind].end()) return dp[ind][num];

    //     //take
    //     int take = (num<<1) + (s[ind] - '0');
    //     int takeLen = 0;

    //     if (take <= k) {
    //         takeLen = helper(s, k, ind+1, take, dp) + 1;
    //     }

    //     int skipLen = helper(s, k, ind+1, num, dp);

    //     // cout<<ind<<" "<<takeLen<<" "<<skipLen<<endl;

    //     return dp[ind][num] = max(takeLen, skipLen);
    // }
};