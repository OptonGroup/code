#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector <vector <int>> g;
int used[100];
bool tree = true;

void dfs(int i, int from = -1) {
	if ((used[i] == 1 && from != -1 && g[i][from] != 1) || !tree){
		tree = false;
		return;
	}
	else if (used[i] == 1 && from != -1 && g[i][from] == 1) {
		return;
	}
	else {
		used[i] = 1;
	}
	for (int j = 0; j < n; ++j) {
		if (g[i][j])
			dfs(j, i);
	}
}

int main() {
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i) {
		g.push_back(vector<int>());
		int link;
		for (int j = 0; j < n; ++j) {
			cin >> link;
			g[i].push_back(link);
		}
	}

	dfs(0);
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		if (used[i] == 0) {
			ok = false;
			break;
		}
	}

	if (tree && ok) cout << "YES";
	else cout << "NO";
	return 0;
}


// FIXME:
// 3
// 0 1 1
// 1 0 1
// 1 1 0
// Это не дерево, т.к. здесть есть цикл: из 1 в 2, из 2 в 3, из 3 в 1
