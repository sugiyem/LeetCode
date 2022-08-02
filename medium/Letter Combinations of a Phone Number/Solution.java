class Solution {
    public List<String> letterCombinations(String digits) {
        if (digits == null || digits.length() == 0) {
            return new ArrayList<>();
        }
        
        char[][] phoneMap = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'},
                             {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                             {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        List<String> ans = new ArrayList<>();
        backTrack(ans, digits, phoneMap, 0, new StringBuilder());
        return ans;
    }
    
    private void backTrack(List<String> ans, String str, char[][] phoneMap, int start,
                          StringBuilder sb) {
        if (start == str.length()) {
            ans.add(sb.toString());
            return;
        }
        
        int index = str.charAt(start) - '0';
        for (int i = 0; i < phoneMap[index].length; ++i) {
            sb.append(phoneMap[index][i]);
            backTrack(ans, str, phoneMap, start + 1, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}