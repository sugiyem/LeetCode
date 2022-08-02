class Solution {
    public String multiply(String num1, String num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        int[] ans = new int[len1 + len2 + 10]; 
        
        for (int i = len2 - 1; i >= 0; i--) {
            int adds = 0;
            int pos = len2 - i - 1;
            for (int j = len1 - 1; j >= 0; j--) {
                int res = ans[pos] + adds + (num2.charAt(i) - '0') * (num1.charAt(j) - '0');
                ans[pos] = res % 10;
                adds = res / 10;
                pos++;
            }
            while(adds > 0) {
                ans[pos++] = adds % 10;
                adds /= 10;
            }
            
        }
        
        int lastNonZeroIndex = 0;
        for (int i = 0; i < ans.length; ++i) {
            if (ans[i] != 0) {
                lastNonZeroIndex = i;
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for (int i = lastNonZeroIndex; i >= 0; --i) {
            sb.append(ans[i]);
        }
        
        return sb.toString();
    }
}