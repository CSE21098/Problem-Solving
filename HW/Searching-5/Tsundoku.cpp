int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];

    for (int j = 1; j < m; j++)
        b[j] += b[j - 1];

    int s = 0, ans = 0, i = 0;
    for (i = 0; i < n; i++) {
        int left = p - s, cnt = 0;
        if (left >= 0) {
            cnt += i;
            if (left >= b[0])
                cnt += (upper_bound(b.begin(), b.end(), left) - b.begin());
            ans = max(ans, cnt);
            s += a[i];
        } else {
            break;
        }
    }

    int left = p - s, cnt = n;
    if (left >= 0) {
        if (left >= b[0])
            cnt += (upper_bound(b.begin(), b.end(), left) - b.begin());
        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}