class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length()==0) {
            return 0;
        }
        
        HashMap<Character,Integer> map = new HashMap<Character,Integer>();
        int ans = 0;
        int index = 0;
        for (int i=0; i<s.length(); i++) {
            if (map.containsKey(s.charAt(i))) {
                index = Math.max(index, map.get(s.charAt(i)) + 1);
            }
            ans = Math.max(ans, i+1-index);
            map.put(s.charAt(i),i);
        }
        return ans;
    }
}