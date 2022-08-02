class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLen = haystack.length(), needleLen = needle.length();
        
        for (int i = 0; i <= haystackLen - needleLen; i++) {
            for (int j = 0; j <= needleLen; j++) {
                if (j == needleLen) {
                    return i;
                }
                
                if (needle[j] != haystack[i + j]) {
                    break;
                }
            }
        }
        
        return -1;
    }
};