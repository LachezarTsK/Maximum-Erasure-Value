
public class Solution {

    private static final int[] INPUT_VALUES_RANGE = {1, (int) Math.pow(10, 4)};

    public int maximumUniqueSubarray(int[] nums) {
        boolean[] visited = new boolean[INPUT_VALUES_RANGE[1] + 1];
        int maxSum = 0;
        int currentSum = 0;
        int tail = 0;

        for (int head = 0; head < nums.length; ++head) {

            currentSum += nums[head];
            while (visited[nums[head]] && tail < head) {
                currentSum -= nums[tail];
                visited[nums[tail]] = false;
                ++tail;
            }

            visited[nums[head]] = true;
            maxSum = Math.max(maxSum, currentSum);
        }
        return maxSum;
    }
}
