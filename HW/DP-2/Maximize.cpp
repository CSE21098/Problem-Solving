#include <bits/stdc++.h> 
using namespace std; 

int maximizeExpr(int a[], int n, int x, int y, int z) 
{ 
	int L[n]; 
	L[0] = x * a[0]; 
	for (int i = 1; i < n; i++) 
		L[i] = max(L[i - 1], x * a[i]); 

	int R[n]; 
	R[n - 1] = z * a[n - 1]; 
	for (int i = n - 2; i >= 0; i--) 
		R[i] = max(R[i + 1], z * a[i]); 

	int ans = INT_MIN; 
	for (int i = 0; i < n; i++) 
		ans = max(ans, L[i] + y * a[i] + R[i]); 

	return ans; 
} 
	
int main() 
{ 
	int a[] = {-1, -2, -3, -4, -5}; 
	int n = sizeof(a) / sizeof(a[0]); 
	int x = 1, y = 2 , z = -3; 
	cout << maximizeExpr(a, n, x, y, z) << endl; 
	return 0; 
} 
