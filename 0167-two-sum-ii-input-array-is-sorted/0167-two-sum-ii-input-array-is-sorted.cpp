class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0; i<numbers.size(); i++){
            int first = numbers[i];
            int second = target - first;

            if(mp.find(second) != mp.end()){
                ans.push_back(mp[second] + 1);
                ans.push_back(i+1);
                break;
            }
            mp[first] = i;
        }
        return ans;
    }
};