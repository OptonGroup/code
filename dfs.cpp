#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int num;
	cin >> num;
	int n, k;
	for (int i = 0; i < num; ++i) {
		cin >> n >> k;
		vector <int> m(n);
		vector <int> cnt(200000, 0);
		for (int j = 0; j < n; ++j) {
			cin >> m[j];
			cnt[m[j] - 1]++;
		}
		int c = 0;
		for (int j = 0; j < 200000; ++j) {
			if (cnt[j] > k) {
				cnt[j] = -cnt[j];
			}
			if (cnt[j] <= k && cnt[j] > 0)
				c += cnt[j];
		}

		int color = 1;
		for (int j = 0; j < n; ++j) {
			if (abs(cnt[m[j]-1]) > k) {   //FIXME
				cout << 0 << " ";
				cnt[m[j] - 1]--;
			}
			else if (cnt[m[j]-1] < 0) {
				if (c >= k) {
					cout << color % k << " ";
					cnt[m[j]-1] += 1;
					color++;
				}
				else
					cout << 0 << " ";
				
			}
			else {
				cout << cnt[m[j] - 1] << " ";
				cnt[m[j] - 1]--;
			}
		}

	}

	return 0;
}
