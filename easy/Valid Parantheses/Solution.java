class Solution {
    public boolean isValid(String s) {
        Stack<Character> status = new Stack<Character>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                status.push('(');
            }
            else if (s.charAt(i) == '{') {
                status.push('{');
            }
            else if (s.charAt(i) == '[') {
                status.push('[');
            }
            else if (s.charAt(i) == ')') {
                if (status.empty()) {
                    return false;
                }
                if (status.pop() != '(') {
                    return false;
                }
            }
            else if (s.charAt(i) == '}') {
                if (status.empty()) {
                    return false;
                }
                if (status.pop() != '{') {
                    return false;
                }
            }
            else if (s.charAt(i) == ']') {
                if (status.empty()) {
                    return false;
                }
                if (status.pop() != '[') {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return status.empty();
    }
    
}