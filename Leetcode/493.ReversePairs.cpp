class Solution {
    int result;
public:
    int reversePairs(vector<int>& nums) {
        result = 0;
        mergeSort(0, nums.size()-1, nums);
        return result;
    }
    void mergeSort(int l, int r, vector<int> &arr) {
        if (l >= r) return;
        
        int mid = (l+r)/2;
        mergeSort(l, mid, arr);
        mergeSort(mid+1, r, arr);
        
        for (int i=l, j = mid+1; i<=mid; i++) {
            while (j <= r && (long)arr[j]*2 < arr[i]) {
                j++;
            }
            result += (j-(mid+1));
        }

        vector<int> vec(r-l+1);
        int i=l, j = mid+1, n = 0;
        
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                vec[n++] = arr[i++];
            } else {
                vec[n++] = arr[j++];
            }
        }
        while (i <= mid) {
            vec[n++] = arr[i++];
        }
        while (j <= r) {
            vec[n++] = arr[j++];
        }
        
        n = 0;
        for (int k=l; k<=r; k++, n++) {
            arr[k] = vec[n];
        }
    }
};
