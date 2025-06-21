class SlidingWindowMaximum {
    int limit;
    deque<pair<int, int>> list;
    public:
    SlidingWindowMaximum(int k) {
        limit = k;
    }

    void insert(int index, int value) {
        while (!list.empty() && list.back().first < value) list.pop_back();
        list.push_back({value, index});
    }

    int get(int index) {
        int boundry = index-limit+1;
        while (list.front().second < boundry) list.pop_front();
        return list.front().first;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        SlidingWindowMaximum ds(k);
        vector<int> vec;

        for (int i=0; i<k; i++) ds.insert(i, nums[i]);
        vec.push_back(ds.get(k-1));

        for(int i=k; i<nums.size(); i++) {
            ds.insert(i, nums[i]);
            vec.push_back(ds.get(i));
        }

        return vec;
    }
};