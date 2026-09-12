class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;

        for (string email : emails) {
            string clean = "";
            int i = 0;

           
            while (email[i] != '@') {
                if (email[i] == '+') {
                 
                    while (email[i] != '@') {
                        i++;
                    }
                    break;
                }
                if (email[i] != '.') {
                    clean += email[i];
                }
                i++;
            }
            clean += email.substr(i);
            unique.insert(clean);
        }

        return unique.size();
    }
};