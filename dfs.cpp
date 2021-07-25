#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#define endl '\n'
using namespace std;

vector <vector <int>> go = { { -1, 0 },{ 0, -1 },{ 0, 1 },{ 1, 0 } };
vector <vector <int>> used;
int used_now = 0, cnt = 0;

void dfs(int i, int j) {
	int moves = 0;
	used[i][j] = 1;
	for (int k = 0; k < 4; ++k) {
		int i2 = i + go[k][0], j2 = j + go[k][1];
		if (i2 == 0 || i2 == used.size() - 1 || j2 == 0 || j2 == used[0].size() - 1)
			continue;
		if (used[i2][j2] == 0) {
			used_now++;
			moves += 1;
			dfs(i2, j2);
		}
	}

	if (i==1 && j==1) {
		for (int k = 1; k < used.size(); ++k) {
			for (int f = 1; f < used[0].size(); ++f) {
				if (used[k][f] == 0) {
					dfs(k, f);
					cnt++;
				}
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	string s;
	used.push_back(vector<int>(m + 2, -1));
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		used.push_back(vector<int>(1, -1));
		for (int j = 0; j < m; ++j) {
			if (s[j] == '#')
				used[i].push_back(0);
			else
				used[i].push_back(-1);
		}
		used[i].push_back(-1);
	}
	used.push_back(vector<int>(m + 2, -1));
	if (used[1][1] == 0) {
		cnt++;
		dfs(1, 1);
	}
	else {
		for (int k = 1; k < used.size(); ++k) {
			for (int f = 1; f < used[0].size(); ++f) {
				if (used[k][f] == 0) {
					cnt++;
					dfs(k, f);
					break;
				}
			}
		}
	}
	cout << cnt;

	return 0;
}
