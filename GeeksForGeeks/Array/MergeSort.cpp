class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        vector<int> vec(r-l+1);
        int i=l, j = m+1, n = 0;
        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) {
                vec[n++] = arr[i++];
            } else {
                vec[n++] = arr[j++];
            }
        }
        while (i <= m) {
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
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if (l >= r) return;
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};