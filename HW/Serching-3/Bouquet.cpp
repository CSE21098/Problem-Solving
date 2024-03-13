int isSolution(vector<int>& bloomDay, int m, int k, int check) {
    int size = bloomDay.size();
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (bloomDay[i] <= check) {
            count++;
            if (count == k) {
                m--;
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    if (m > 0) return 0;
    return 1;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int start = 1;
    int end = *max_element(bloomDay.begin(), bloomDay.end());
    int mid = start + (end - start) / 2;
    int result = -1;
    while (start <= end) {
        if (isSolution(bloomDay, m, k, mid)) {
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return result;
}