// MXCODE
//
// ||\\  //||    CCCCC   OOOO    DDDDD    EEEEEE
// || \\// ||   CC      O    O   D    D   E
// ||  XX  ||   C       O    O   D    D   EEEEEE
// || //\\ ||   CC      O    O   D    D   E
// ||//  \\||    CCCCC   OOOO    DDDDD    EEEEEE
//


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <string>
#include <iomanip>
#define endl '\n'
typedef long long ll;
using namespace std;

ll n, cnt = 0;
vector <ll> v;

void funct(vector <int> used, vector <int> take) {
	if (take.size() == 3) {
		cnt += v[take[0]] * v[take[1]] * v[take[2]];
		cnt %= 1000000007;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			used[i] = 1;
			take.push_back(i);
			funct(used, take);
			used[i] = 0;
			take.pop_back();
			funct(used, take);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	funct(vector <int>(n), vector <int>());
	cout << cnt;

	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
