class Solution {
  public:
    long long count(int n) {
        int totalPossibleEdges = n * (n-1) / 2;
        long long totalPossibleGraphs = pow(2, totalPossibleEdges);
        return totalPossibleGraphs;
    }
};