class Solution {
    public String largestNumber(int[] nums) {
       return Arrays.stream(nums).mapToObj(String::valueOf).sorted((str1, str2) -> {
           String comp1 = str1 + str2;
           String comp2 = str2 + str1;
           return comp2.compareTo(comp1);
       }).reduce("", (x, y) -> x.equals("0") ? "0" : x + y);
       
       
    }
}