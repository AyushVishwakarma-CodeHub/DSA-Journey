class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        int ones = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            if (s[right] == '1') {
                ones++;
            }

            while (ones > k || (left <= right && s[left] == '0')) {
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }

            if (ones == k) {
                string cur = s.substr(left, right - left + 1);
                if (ans.empty() || cur.length() < ans.length() || (cur.length() == ans.length() && cur < ans)) {
                    ans = cur;
                }
            }
        }

        return ans;
    }
};