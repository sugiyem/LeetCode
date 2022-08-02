class Solution {
public:
    string countAndSay(int n) {
        string currAns = "1";
        for (int i = 1; i < n; i++) {
            string nextAns = "";
            for (int j = 0; j < currAns.size(); j++) {
                int count = 1;
                while (j < currAns.size() - 1 && currAns[j] == currAns[j + 1]) {
                    count++;
                    j++;
                }
                nextAns += to_string(count) + currAns[j];
            }
            currAns = nextAns;
        }
        return currAns;
    }
};