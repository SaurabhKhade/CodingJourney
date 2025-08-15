

class RangeFreqQuery {
    vector<unordered_map<int, int>> sgt;
    int n;

public:
    RangeFreqQuery(vector<int>& arr) {
        sgt.resize(arr.size() * 4);
        n = arr.size();
        build(0, 0, n-1, arr);
    }

    void build (int i, int low, int high, vector<int>& arr) {
        if (low == high) {
            sgt[i][arr[low]] = 1;
        } else {
            int mid = (low+high)/2;
            build(2*i+1, low, mid, arr);
            build(2*i+2, mid+1, high, arr);

            unordered_map<int, int> map;
            for (auto it = sgt[2*i+1].begin(); it != sgt[2*i+1].end(); it++) {
                map[it->first] += it->second;
            }
            for (auto it = sgt[2*i+2].begin(); it != sgt[2*i+2].end(); it++) {
                map[it->first] += it->second;
            }

            sgt[i] = map;
        }
    }

    int find(int i, int low, int high, int left, int right, int value) {
        if (high < left || low > right) return 0;
        if (low >= left && high <= right) return sgt[i][value];

        int mid = (low+high)/2;
        return find(2*i+1, low, mid, left, right, value) + find(2*i+2, mid+1, high, left, right, value);
    }
    
    int query(int left, int right, int value) {
        // cout<<left<<" "<<right<<endl;
        return find(0, 0, n-1, left, right, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */