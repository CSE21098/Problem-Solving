int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int left = 0, right = 1e9;
    k--;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        int count = 0;

        for (int i = 0; i < n; i++)
            count += upper_bound(mat[i], mat[i] + n, middle) - mat[i];

        if (count <= k)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return left;
}