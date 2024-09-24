class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, bool> map;
        int maxPrefix = 0;
        
        for (int &i: arr1) {
            while (i) {
                map[i] = true;
                i /= 10;
            }
        }

        for (int &i: arr2) {
            while (i) {
                if (map[i]) {
                    maxPrefix = max(maxPrefix, i);
                    break;
                }

                i/=10;
            }
        }

        int len = 0;
        while (maxPrefix) {
            len++;
            maxPrefix /= 10;
        }

        return len;
    }
};