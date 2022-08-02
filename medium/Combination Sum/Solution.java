class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        backTrack(ans, curr, candidates, 0, target);
        return ans;
    }
    
    private void backTrack(List<List<Integer>> ans, List<Integer> curr, int[] arr, 
                           int start, int res) {
        if (res < 0) {
            return;
        } else if (res == 0) {
            ans.add(new ArrayList<>(curr));
        } else {
            for (int i = start; i < arr.length; ++i) {
                curr.add(arr[i]);
                backTrack(ans, curr, arr, i, res - arr[i]);
                curr.remove(curr.size() - 1);
            }
        }
    }
}