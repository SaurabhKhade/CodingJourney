class Solution {
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int> vec;
        vec.push_back(arr[n-1]);
        int mx = arr[n-1];

        for (int i=n-2; i>=0; i--) {
            if (arr[i] >= mx) {
                vec.push_back(arr[i]);
                mx = arr[i];
            }
        }
        
        reverse(vec.begin(), vec.end());
        return vec;
    }
};