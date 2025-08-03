class SegmentNode {

};

class Solution {
    string construct(string s, vector<int> &order, int n) {
        string ss = s;
        for (int i=0; i<=n; i++) {
            ss[order[i]] = '*';
        }

        return ss;
    }

    bool possible(string s, int k, long total) {
        long subarrays = 0;
        int i = 0, j = 0;

        while (j < s.size()) {
            while (j < s.size() && s[j] != '*') {
                j++;
            }
            subarrays += 1L * (j-i) * (j-i+1) / 2;
            i = ++j;
        }

        // cout<<s<<" "<<subarrays<<" "<<total<<endl;
        
        return (total-subarrays) >= k;
    }
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();
        long total = 1L * n * (n+1)/2;
        if (k > total) return -1;
        int i = 0, j = n-1;
        int res = -1;

        while (i <= j) {
            int mid = (i+j)/2;
            string pattern = construct(s, order, mid);
            if (possible(pattern, k, total)) {
                res = mid;
                j = mid-1;
            } else {
                i = mid+1;
            }
        }
        
        return res;
    }
};
