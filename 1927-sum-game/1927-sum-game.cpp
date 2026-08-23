class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sum_diff = 0;
        int q_diff = 0;

        for(int i = 0; i<n; i++){
            int sign  = (i<n/2) ? 1 : -1;
            if(num[i] == '?'){
                q_diff += sign;
            }else{
                sum_diff += sign * (num[i] - '0');
            }
        }
        return (sum_diff *2 + q_diff * 9) != 0;
    }
};