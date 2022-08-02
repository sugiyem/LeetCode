class Solution {
    private String[] end = {"", "Thousand", "Million", "Billion"};
    private String[] ones = {"", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine"};
    private String[] teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    private String[] tens = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty",
        "Seventy", "Eighty", "Ninety"};

    public String numberToWords(int num) {
        String ans = "";
        int k = 0;
        while(num > 0) {
            int res = num % 1000;
            ans = helper(res, k) + " " + ans;
            ans = ans.trim();
            k++;
            num /= 1000;
        }
        if (ans.length() == 0) {
            return "Zero";
        }
        return ans.trim();
    }
    
    public String helper(int num, int k) {
        String ans = "";
    
        if (num >= 100) {
            ans = ans + ones[num/100] + " Hundred";
        }
        num = num % 100;
        if (num < 10) {
            ans = ans + " " + ones[num];
        }
        else if (num < 20) {
            ans = ans + " " + teens[num - 10];
        }
        else {
            int a = num % 10;
            int b = num / 10;
            ans = ans + " " + tens[b - 2] + " " + ones[a];
        }
        ans = ans.trim();
        if (ans.length() != 0) {
            ans = ans + " " + end[k];
        }
        return ans.trim();
        
    }
}