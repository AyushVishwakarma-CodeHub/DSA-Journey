class Solution {
public:
    int countCommas(int n) {
        int totalCommas = 0;

        for(int i = 1; i <= n; ++i){
            string s = to_string(i);
            int len = s.length();

            totalCommas += (len - 1)/3;
        }
        return totalCommas;
    }
};