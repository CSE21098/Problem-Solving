#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& preorder) {
    int next = 0;
    int last = 0;
    for (int i = 0; i < preorder.size() - 1; ++i) {
        next = preorder[i] - preorder[i + 1];
        last = preorder[i] - preorder[preorder.size() - 1];
        if (next * last < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> preorder = {22, 12, 13, 15, 14};
    cout << solve(preorder) << endl;
    return 0;
}
