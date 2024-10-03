class Solution {
  public:
    long long int result = 0;
    long long int inversionCount(vector<long long> &arr) {
        result = 0;
        mergeSort(0, arr.size()-1, arr);
        return result;
    }
    
    void mergeSort(int i, int j, vector<long long> &arr) {
        if (i >= j) return;
        
        int mid = (i+j)/2;
        mergeSort(i, mid, arr);
        mergeSort(mid+1, j, arr);
        vector<int> vec(j-i+1);
        int l=i, m = mid+1, n = 0, adder = 0;
        
        while (l <= mid && m <= j) {
            if (arr[l] <= arr[m]) {
                vec[n++] = arr[l++];
                result += adder;
            } else {
                vec[n++] = arr[m++];
                adder++;
            }
        }
        while (l <= mid) {
            vec[n++] = arr[l++];
            result += adder;
        }
        while (m <= j) {
            vec[n++] = arr[m++];
        }
        
        n = 0;
        for (int k=i; k<=j; k++, n++) {
            arr[k] = vec[n];
        }
    }
};