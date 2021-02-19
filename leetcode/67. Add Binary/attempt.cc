class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (a.length() > b.length()) {
            swap(a, b);
        }
        string c;
        int carry;
        auto one_bit_add = [&](int result) {
            int last_c = result % 2;
            carry = result / 2;
            c += to_string(last_c);
        }
        for (size_t i = 0; i < a.length(); ++i) {
            int last_a = a[i] - '0';
            int last_b = b[i] - '0';
            one_bit_add(carry + last_a + last_b);
        }
        for (size_t i = a.length(); i < b.length(); ++i) {
            int last_b = b[i] - '0';
            one_bit_add(carry + last_b);
        }
        if (carry) {
            c += '1';
        }
        reverse(c.begin(), c.end());
        return c;
    }
};
