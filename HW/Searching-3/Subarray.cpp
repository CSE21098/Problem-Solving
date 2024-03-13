bool poss(vector<int> &arr,int mid, int X) {
    int sum = 0;
    for (int i = 0; i < mid; i++) {
        sum += arr[i];
    }
    if (sum > X)
        return false;
    for (int i = mid; i < arr.size(); i++) {
        sum += arr[i] - arr[i - mid];
        if (sum > X)
            return false;
    }
    return true;
}

int findMaxElements(vector<int> &arr, int X) {
    int low = 0;
    int high = arr.size();
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (poss(arr,mid, X)){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}
