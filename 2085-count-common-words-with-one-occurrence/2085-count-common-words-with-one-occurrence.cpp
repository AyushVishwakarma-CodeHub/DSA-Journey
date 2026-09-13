class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> count1;
        unordered_map<string, int> count2;

        for (const string& w : words1) {
            count1[w]++;
        }

        for (const string& w : words2) {
            count2[w]++;
        }

        int ans = 0;
        for (const auto& [word, freq] : count1) {
            if (freq == 1 && count2[word] == 1) {
                ans++;
            }
        }

        return ans;
    }
};