class Solution {
public:
    int longestBalanced(string s) {
        vector<int> vec(26);
        int maxi = 0;

        for (int i=0; i<s.size(); i++) {
            for (int j=i; j<s.size(); j++) {
                vec[s[j]-'a']++;
                int mxf = 0;
                int equal = true;
                for (int i=0; i<26; i++) {
                    if (vec[i] != 0 && mxf != 0 && vec[i] != mxf) {
                        equal = false;
                        break;
                    }
                    mxf = max(mxf, vec[i]);
                }

                if (equal) {
                    maxi = max(maxi, j-i+1);
                }
            }
            vec = vector<int>(26);
        }

        return maxi;
    }
};