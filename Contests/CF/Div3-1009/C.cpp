//created by orabi 
#include <bits/stdc++.h>
using namespace std;
 
bool isPowerOfTwo(int x) {
	return x && !(x & (x - 1));
}
 
int main() {
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		if (isPowerOfTwo(x)) {
			cout << "-1\n";
			continue;
		}
		if (isPowerOfTwo(x + 1)) {
			cout << "-1\n";
			continue;
		}
		unsigned int ux = x;
		int highest = 31 - __builtin_clz(ux);
		int masker = 1 << highest;
		int y = masker - 1;
		cout << y << '\n';
	}
	return 0;
}