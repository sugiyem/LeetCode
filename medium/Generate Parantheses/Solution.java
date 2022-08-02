class Solution {
    public List<String> generateParenthesis(int n) {
        // ....() or ...))
        // f(x, y) = f(x, y - 1),
        return generate(n, n).stream().parallel()
            .map(str -> str.toString()).collect(Collectors.toList());
    }
    
    private List<StringBuilder> generate(int x, int y) {
        List<StringBuilder> ans = new ArrayList<>();
        if (x < y) {
            return ans;
        }
        if (y == 0) {
            StringBuilder k = new StringBuilder();
            for (int i = 0; i < x; ++i) {
                k = k.append("(");
            }
            ans.add(k);
            return ans;
        }
        
        List<StringBuilder> ans1 = generate(x, y - 1)
            .stream().parallel().map(str -> str.append(")"))
            .collect(Collectors.toList());
        List<StringBuilder> ans2 = generate(x - 1, y)
            .stream().parallel().map(str -> str.append("("))
            .collect(Collectors.toList());
        
        ans.addAll(ans1);
        ans.addAll(ans2);
        return ans;
        
    }
}