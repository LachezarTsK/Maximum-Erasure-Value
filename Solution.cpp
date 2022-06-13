
#include <array>
#include <vector>
using namespace std;

class Solution {
    
    inline static const array<int, 2> INPUT_VALUES_RANGE{ 1, static_cast<int> (pow(10, 4))};

public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool> visited(INPUT_VALUES_RANGE[1] + 1);
        int maxSum = 0;
        int currentSum = 0;
        int tail = 0;

        for (int head = 0; head < nums.size(); ++head) {

            currentSum += nums[head];
            while (visited[nums[head]] && tail < head) {
                currentSum -= nums[tail];
                visited[nums[tail]] = false;
                ++tail;
            }

            visited[nums[head]] = true;
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};
