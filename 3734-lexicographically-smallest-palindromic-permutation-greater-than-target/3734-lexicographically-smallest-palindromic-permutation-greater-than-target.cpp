class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        int m = n / 2;
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        int odd = 0;
        char mid = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd++;
                mid = 'a' + i;
            }
        }
        if (odd > 1 || (n % 2 == 0 && odd != 0)) return "";

        vector<int> half(26, 0);
        for (int i = 0; i < 26; ++i) half[i] = count[i] / 2;

        auto make_palindrome = [&](const string& half_str) {
            string res = half_str;
            if (n % 2 != 0) res += mid;
            for (int i = m - 1; i >= 0; --i) res += half_str[i];
            return res;
        };

        vector<int> cur = half;
        bool ok = true;
        for (int i = 0; i < m; ++i) {
            if (--cur[target[i] - 'a'] < 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            string pal = make_palindrome(target.substr(0, m));
            if (pal > target) return pal;
        }

        for (int k = m - 1; k >= 0; --k) {
            vector<int> rem = half;
            bool valid = true;
            for (int i = 0; i < k; ++i) {
                if (--rem[target[i] - 'a'] < 0) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;

            for (int c = target[k] - 'a' + 1; c < 26; ++c) {
                if (rem[c] > 0) {
                    string prefix = target.substr(0, k);
                    prefix += (char)('a' + c);
                    rem[c]--;

                    for (int i = 0; i < 26; ++i) {
                        while (rem[i]-- > 0) prefix += (char)('a' + i);
                    }
                    return make_palindrome(prefix);
                }
            }
        }

        return "";
    }
};