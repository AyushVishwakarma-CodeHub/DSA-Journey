class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int size = nums.size();
        for(int n : nums){
            m[n]++;
            if(m[n] > size/2){
                return n;
            }
            
        }
        return -1;
    }
};