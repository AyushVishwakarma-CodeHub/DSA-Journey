class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      unordered_set<int> st(nums1.begin(), nums1.end());
      vector<int>ans;

      for(int n : nums2){
          if(st.count(n)){
            ans.push_back(n);
            st.erase(n);
          }
      }
      return ans;
    }    
    
};