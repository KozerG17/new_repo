#include <bits/stdc++.h>
using namespace std;


const int N = 5e3;

string s; int n;
int dp[N + 1];


int calc(int i) {
	if (i >= n - 1)
		return 1;
	if (dp[i] == 0) {
		if (s[i + 1] == '0') return dp[i] = calc(i + 2);
		if (i + 2 < n && s[i + 2] == '0') return dp[i] = calc(i + 1);
		if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
			cerr << i + 1 << ' ' << i + 2 << ' ' << calc(i + 1) + calc(i + 2) << '\n';
			dp[i] = calc(i + 1) + calc(i + 2);
			cerr << '0' << '\n';
		}
		else {
			cerr << i + 1 << ' ' << calc(i + 1) << '\n';
			dp[i] = calc(i + 1);
			cerr << '0' << '\n';
		}
		return dp[i];
	}
}


int main() {
	while (cin >> s, s != "0") {
		n = s.size();

		memset(dp, 0, sizeof(dp));
		// cout << calc(0);
		for (int i = 0; i < n; ++i)
			cerr << calc(i) << ' ';
		cout << calc(0);
		cout << '\n';
	}
}
