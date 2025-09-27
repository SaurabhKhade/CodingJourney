class Solution {
public:
    string fractionToDecimal(long num, long den) {
        string whole = to_string(num/den);
        if (num % den == 0) return whole;

        bool neg = false;

        if (num < 0) {
            neg = !neg;
            num *= -1;
        }

        if (den < 0) {
            neg = !neg;
            den *= -1;
        }

        whole = to_string(num/den);

        num %= den;
        whole += '.';
        string decimal;

        unordered_map<long, int> map;

        while (num != 0) {
            num *= 10;

            if (map.find(num) != map.end()) {
                string nonRepeat = decimal.substr(0, map[num]);
                string repeat = decimal.substr(map[num], decimal.size()-map[num]);
                decimal = nonRepeat + '(' + repeat + ')';
                break;
            }

            map[num] = decimal.size();

            decimal += (num/den + '0');
            num %= den;
        }

        return (neg ? "-" : "") + whole + decimal;
    }
};


// 0.
// 1
// 10
// 40