class Solution {
    public List<List<Integer>> permute(int[] nums) {
        if (nums.length == 1) {
            return List.of(List.of(nums[0]));
        }
        int len = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        List<List<Integer>> curr = permute(Arrays.copyOfRange(nums, 0, len - 1)).stream()
            .map(x -> {
                List<Integer> k = new ArrayList<>();
                k.add(nums[len - 1]);
                k.addAll(x);
                return k;})
            .collect(Collectors.toList());
        ans.addAll(curr);
        for (int i = 0; i < len - 1; ++i) {
            curr = curr.stream().map(x -> translate(x)).collect(Collectors.toList());
            ans.addAll(curr);
        }
        return ans;
    }
    
    public List<Integer> translate(List<Integer> t) {
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < t.size(); ++i) {
            ans.add(t.get((i + 1) % t.size()));
        }
        return ans;
    }
}