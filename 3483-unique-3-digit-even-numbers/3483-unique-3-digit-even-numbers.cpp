class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};

      
        for (int digit : digits) {
            freq[digit]++;
        }

        int count = 0;

    
        for (int last = 0; last <= 8; last += 2) {
            if (freq[last] == 0)
                continue;

            freq[last]--;

         
            for (int first = 1; first <= 9; first++) {
                if (freq[first] == 0)
                    continue;

                freq[first]--;

                
                for (int middle = 0; middle <= 9; middle++) {
                    if (freq[middle] > 0) {
                        count++;
                    }
                }

                freq[first]++;
            }

            freq[last]++;
        }

        return count;
    }
};