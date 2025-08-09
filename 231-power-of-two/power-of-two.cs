public class Solution {
    public bool IsPowerOfTwo(long n) {
        if (n <= 0) return false;
        long temp = Math.Abs(n);

        while (temp > 0) {
            long bit = temp%2;
            if (bit == 1 && temp != 1) return false;
            temp/=2;
        }
        
        return true;
    }
}