public class Solution {
    public bool CheckDivisibility(int n) {
        int sum = 0, product = 1, temp = n;
        while (temp > 0) {
            sum += (temp%10);
            product *= (temp%10);
            temp /= 10;
        }

        return n%(sum+product) == 0;
    }
}