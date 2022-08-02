class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> curr = new Stack<>();
        int ans = 0;
        int last = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                curr.push(i);
            } else {
                if (!curr.isEmpty()) {
                    curr.pop();
                    if (curr.isEmpty()) {
                        ans = Math.max(ans, i - last);
                    } else {
                        ans = Math.max(ans, i - curr.peek());
                    }
                } else {
                    last = i;
                }
            }
        }
        return ans;
    }
}