int Solution::solve(vector<int> &A, int B) {
    int xr = 0, count = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    
    for (int &i:A) {
        xr ^= i;
        count += map[xr ^ B];
        map[xr]++;
    }
    
    return count;
}