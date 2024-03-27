int kthElement(vector<int> &a, vector<int> &b, int n1, int n2, int k) {
    if (n1 > n2)
        return kthElement(b, a, n2, n1, k);
    int n = n1 + n2;
    int low = max(0, k - n2), high = min(k, n1);

    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = k - mid1;
        int left1 = INT_MIN, left2 = INT_MIN;
        int right1 = INT_MAX, right2 = INT_MAX;

        if (mid1 < n1)
            right1 = a[mid1];
        if (mid2 < n2)
            right2 = b[mid2];
        if (mid1 - 1 >= 0)
            left1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            left2 = b[mid2 - 1];

        if (left1 <= right2 && left2 <= right1) {
            return max(left1, left2);
        } else if (left1 > right2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }
    return 0;
}