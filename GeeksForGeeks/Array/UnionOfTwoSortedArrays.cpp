class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> arr;
        int i=0, j=0;
        
        if (arr1[i] < arr2[j]) {
            arr.push_back(arr1[i]);
            i++;
        } else {
            arr.push_back(arr2[j]);
            j++;
        }
        
        while (i<n && j<m) {
            if (arr1[i] < arr2[j]) {
                if (arr1[i] != arr.back()) arr.push_back(arr1[i]);
                i++;
            } else {
                if (arr2[j] != arr.back()) arr.push_back(arr2[j]);
                j++;
            }
        }
        while (i<n) {
            if (arr1[i] != arr.back()) arr.push_back(arr1[i]);
            i++;
        }
        while (j<m) {
            if (arr2[j] != arr.back()) arr.push_back(arr2[j]);
            j++;
        }
        
        return arr;
    }
};