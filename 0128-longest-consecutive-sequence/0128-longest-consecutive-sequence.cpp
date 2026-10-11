class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int>st(nums.begin(), nums.end());
       
        int longest = 0;
         for(int n : st){
            if(st.count(n-1) == 0){
               int count = 1;
               int current = n;
            while(st.count(current + 1)){
                current++;
                count++;
            }
            longest = max(longest,count);
            }
         }
         return longest;
    }
};