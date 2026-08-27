#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        vector<int> temp_count = count;
        int max_prefix = 0;
        while (max_prefix < n) {
            int idx = target[max_prefix] - 'a';
            if (temp_count[idx] > 0) {
                temp_count[idx]--;
                max_prefix++;
            } else {
                break;
            }
        }

        for (int i = max_prefix; i >= 0; i--) {

            vector<int> rem = count;
            for (int j = 0; j < i; j++) {
                rem[target[j] - 'a']--;
            }

            if (i < n) {
                for (int c = target[i] - 'a' + 1; c < 26; c++) {
                    if (rem[c] > 0) {
                        string ans = target.substr(0, i);
                        ans += (char)('a' + c);
                        rem[c]--;

                        for (int k = 0; k < 26; k++) {
                            ans.append(rem[k], (char)('a' + k));
                        }
                        return ans;
                    }
                }
            }
        }

        return "";
    }
};