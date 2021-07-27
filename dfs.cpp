#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <string>
#define endl '\n'
using namespace std;

int n;
vector <int> nums;
vector <int> out;

int dp(int num) {
	if (nums[num - 1] != -1) {
		return nums[num - 1];
	}

	if (num % 2 != 0) {
		nums[num - 1] = dp(num - 1) + 1;
	}
	else {
		nums[num - 1] = dp(num / 2) + 1;
	}
	if (num % 3 == 0) {
		nums[num - 1] = min(dp(num / 3) + 1, nums[num - 1]);
	}
	return nums[num - 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	nums.resize(n * 2, -1);
	nums[0] = 0;
	int ans = dp(n);
	vector <int> out;
	while (n != 1) {
		if (((nums[n/3-1] < nums[n/2-1])||(nums[n / 3 - 1] < nums[n-1])) && n%3 == 0 && nums[n/3-1] != -1) {
			out.push_back(3);
			n /= 3;
		}
		else if ((nums[n / 2 - 1] < nums[n - 1])&&n%2==0 && nums[n/2-1] != -1) {
			out.push_back(2);
			n /= 2;
		}
		else {
			out.push_back(1);
			n -= 1;
		}
	}
	for (int i = out.size()-1; i >= 0; --i) {
		cout << out[i];
	}


	return 0;
}
