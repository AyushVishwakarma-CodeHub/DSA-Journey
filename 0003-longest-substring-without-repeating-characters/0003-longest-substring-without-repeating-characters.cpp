class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int> charMap(256 , -1);

        int maxlenght = 0;
        int left = 0;

        for (int right = 0; right<s.size(); right++){
            if (charMap[s[right]] >= left ){
                left = charMap[s[right]]+1;
            }
            charMap[s[right]]=right;
            
            maxlenght = max (maxlenght , right - left +1);   
        }
            return maxlenght;
        
    }
};