
/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumUniqueSubarray = function (nums) {
    const INPUT_VALUES_RANGE = [1, Math.pow(10, 4)];
    const visited = new Array(INPUT_VALUES_RANGE[1] + 1).fill(false);
    let maxSum = 0;
    let currentSum = 0;
    let tail = 0;

    for (let head = 0; head < nums.length; ++head) {

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
};
