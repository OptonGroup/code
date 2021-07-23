#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> g;
int used[100];
bool tree = true;

void dfs(int i) {
	if (used[i] == 1 || !tree) {
		tree = false;
		return;
	}
	used[i] = 1;
	for (int j = 0; j < g[i].size(); ++j) {
		if (g[i][j]) 
			dfs(j);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> g[i][j];
		}
	}

	dfs(0);
	cout << tree;
	return 0;
}
