class Solution {
public:
    int maximumSwap(int num) {
        string num_str = to_string(num);
        vector<int> lastIndex(10, -1);
        int n = num_str.size();

        for (int i=0; i<n; i++) {
            lastIndex[num_str[i]-'0'] = i;
        }

        for (int i=0; i<n; i++) {
            int digit = num_str[i] - '0';
            for (int j=9; j>digit; j--) {
                if (lastIndex[j] != -1 && lastIndex[j] > i) {
                    swap(num_str[i], num_str[lastIndex[j]]);
                    return stoi(num_str);
                }
            }
        }
        
        return num;
    }
};