class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> map;

        for (int &i:arr) {
            int rem = i % k;
            if (rem < 0) rem += k;
            map[rem]++;
        }

        if (map[0]%2 != 0) return false;
        if (k%2==0 && map[k/2]%2 != 0) return false;

        for (int i=1; i<=k/2; i++) {
            if (map[i] != map[k-i]) return false;
        }

        return true;
    }
};
