class Solution {
public:
    int mySqrt(int x) {
        function<long long(long long, long long)> search;
        search = [&](long long left, long long right) -> long long {
            if (left == right) return left;
            long long mid = (left + right + 1) / 2;
            if (mid * mid <= x) {
                return search(mid, right);
            } else {
                return search(left, mid - 1);
            }
        };
        return search(0, x);
    }
};
