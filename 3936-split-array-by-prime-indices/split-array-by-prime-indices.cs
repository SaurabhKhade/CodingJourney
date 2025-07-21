public class Solution {
    public long SplitArray(int[] nums) {
        if (nums.Length == 1) {
            return Math.Abs(nums[0]);
        }

        var isPrime = Sieve(nums.Length);
        long sum = 0;

        for (int i=0; i<nums.Length; i++) {
                // Console.WriteLine(isPrime[i]);
            if (isPrime[i]) {
                sum += nums[i];
                // Console.WriteLine(nums[i]);
            }
            else {
                sum -= nums[i];
                // Console.WriteLine(-nums[i]);
            }
        }

        return Math.Abs(sum);
    }

    bool[] Sieve(int n) {
        var isPrime = new bool[n];
        Array.Fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int i=2; i<n; i++) {
            if (isPrime[i]) {
                for(int j = 2; j*i<n; j++) {
                    isPrime[j*i] = false;
                }
            }
        }

        return isPrime;
    }
}