bool check(vector<int> &nums,int mid, int maxOperations) {
        int count = 0;
        for (int num : nums) {
            if (num > mid) {
                count += (num / mid) - (num % mid == 0);
            }
        }
        return count <= maxOperations;
    }

int minimumSize(vector<int> &nums, int maxOperations) {
    int low = 1;
    int high = INT_MAX;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (check(nums,mid, maxOperations)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}