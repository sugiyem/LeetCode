class Solution {
    public String longestPalindrome(String s) {
        int len = s.length();
        int range = 0;
        int min = 0;
        int max = 0;
        boolean[][] dp = new boolean[len][len];
        for(int i=0; i<len; i++){
            for(int j=0; j<len-i; j++){
                if(i==0){
                    dp[j][j] = true;
                    if(i+1>range){
                        range=i+1;
                        min=j;
                        max=j+i;
                    }
                }
                else if(i==1){
                    if(s.charAt(j)==s.charAt(j+1)){
                        dp[j][j+1] = true;
                        if(i+1>range){
                            range=i+1;
                            min=j;
                            max=j+i;
                        }
                    }
                }
                else{
                    if(s.charAt(j)==s.charAt(j+i) && dp[j+1][j+i-1]){
                        dp[j][j+i] = true;
                        if(i+1>range){
                            range=i+1;
                            min=j;
                            max=j+i;
                        }
                    }
                }
            }
        }
        return s.substring(min, max+1);
    }
}