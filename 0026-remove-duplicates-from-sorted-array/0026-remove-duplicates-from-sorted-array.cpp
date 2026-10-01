class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>ans(nums.begin(),nums.end());
        nums.assign(ans.begin(),ans.end());
        return nums.size();
    }
};