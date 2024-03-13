bool isPossible(vector<int> &boards, int k, int mid) {
    int pairCount = 1;
    int boardSum = 0;

    for (int i = 0; i < boards.size(); i++) {
        if (boardSum + boards[i] <= mid) {
            boardSum += boards[i];
        } else {
            pairCount++;
            if (pairCount > k || boards[i] > mid) {
                return false;
            }
            boardSum = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int totalSum = 0;
    int ans = -1;
    for (int i = 0; i < boards.size(); i++) {
        totalSum += boards[i];
    }

    int start = 0;
    int end = totalSum;
    int mid = start - (end - start) / 2;

    while (start <= end) {
        if (isPossible(boards, k, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}