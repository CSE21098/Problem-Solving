int findLCM(int a, int b) {
    return (a * b) / __gcd(a, b);
}

int main() {
    int left = 1, right = INT_MAX, divisorA, divisorB, divisorC, targetCount;
    cin >> divisorA >> divisorB >> divisorC >> targetCount;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        int count = (middle / divisorA) + (middle / divisorB) + (middle / divisorC);

        int lcmAB = findLCM(divisorA, divisorB);
        int lcmBC = findLCM(divisorB, divisorC);
        int lcmAC = findLCM(divisorA, divisorC);
        int lcmABC = findLCM(lcmAB, divisorC);

        count -= (middle / lcmAB) + (middle / lcmBC) + (middle / lcmAC);
        count += (middle / lcmABC);

        if (count == targetCount) {
            cout << middle << endl;
            return 0;
        }
        if (count < targetCount)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return 0;
}