vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    unordered_set<int> AA(A.begin(), A.end());
    unordered_set<int> BB(B.begin(), B.end());
    unordered_set<int> CC(C.begin(), C.end());
    unordered_map<int,int> map;

    for (auto &i:AA) {
      map[i]++;
    }
    for (auto &i:BB) {
      map[i]++;
    }
    for (auto &i:CC) {
      map[i]++;
    }

    vector<int> result;
    
    for (auto &[key,value]:map) {
        if (value > 1) result.push_back(key);
    }
    
    sort(result.begin(), result.end());
    return result;
}