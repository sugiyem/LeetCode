class Solution {
    public String intToRoman(int num) {
        String rome1 = "IXCM";
        String rome2 = "VLD";
        String ans = "";
        int x = 0;
        while(num > 0) {
            int res = num % 10;
            if (res <= 3) {
                for (int i = 0; i < res; i++) {
                    ans = rome1.charAt(x) + ans;
                }
            }
            else if (res == 4) {
                ans = rome2.charAt(x) + ans;
                ans = rome1.charAt(x) + ans;
            }
            else if (res <= 8) {
                for (int i = 0; i < res - 5; i++) {
                    ans = rome1.charAt(x) + ans;
                }
                ans = rome2.charAt(x) + ans;
            }
            else if (res == 9) {
                ans = rome1.substring(x, x + 2) + ans;
            }
            x++;
            num /= 10;
        }
        return ans;
        
    }
}