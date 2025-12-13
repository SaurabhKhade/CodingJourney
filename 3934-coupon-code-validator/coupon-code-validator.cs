public class Solution {
    public IList<string> ValidateCoupons(string[] code, string[] businessLine, bool[] isActive) {
        var allowedCategories = new HashSet<string> {"electronics", "grocery", "pharmacy", "restaurant"};

        bool isValidCoupon(int index) {
            return isActive[index]
                   && allowedCategories.Contains(businessLine[index])
                   && !string.IsNullOrEmpty(code[index])
                   && code[index].All(chr => chr == '_' || (chr >= '0' && chr <= '9') || (chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'));
        }

        return Enumerable
            .Range(0, code.Length)
            .Where(isValidCoupon)
            .OrderBy(index => businessLine[index])
            .ThenBy(index => code[index], StringComparer.Ordinal)
            .Select(index => code[index])
            .ToList();
    }
}