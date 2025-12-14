public class Solution {
    public bool IsHappy(int n) {
        int slow = n, fast = Next(n);
        while (slow != fast) {
            slow = Next(slow);
            fast = Next(Next(fast));
        }

        return fast == 1;
    }

    int Next(int n) {
        int m = 0;
        while (n > 0) {
            int digit = n%10;
            m += digit * digit;
            n /= 10;
        }

        return m;
    }
}