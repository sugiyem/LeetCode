class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int start = 0, end = products.size() - 1, searchLen = searchWord.length();
        vector<vector<string>> ans(searchLen);
        sort(products.begin(), products.end());   
        
        for (int i = 0; i < searchLen; i++) {
            while (start <= end && 
                   (i >= products[start].length() || products[start][i] < searchWord[i])) {
                start++;
            }
            while (start <= end && 
                   (i >= products[end].length() || products[end][i] > searchWord[i])) {
                end--;
            }

            
            for (int j = start; j < min(start + 3, end + 1); j++) {
                ans[i].push_back(products[j]);
            }
        }
        
        return ans;
    }
};