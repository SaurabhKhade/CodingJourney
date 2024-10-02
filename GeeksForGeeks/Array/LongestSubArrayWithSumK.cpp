class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    {
        int sum = 0, mx = 0;
        unordered_map<int, int> map;
        
        for (int i=0; i<N; i++) {
            sum += A[i];

            if (sum == K) {
                mx = max(mx, i+1);
            }

            if (map.find(sum-K) != map.end()) {
                mx = max(mx, i-map[sum-K]);
            }
            
            if (map.find(sum) == map.end()) {
                map[sum] = i;
            }
        }
        
        return mx;
    } 
};