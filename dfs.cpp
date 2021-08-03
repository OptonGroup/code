#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <string>
#define endl '\n'
using namespace std;

struct bags_struct{
    int time, type_, day;
	bags_struct() {}
	bags_struct(int time_, int type__, int day_) {
		time = time_;
		type_ = type__;
		day = day_;
	}
	bool operator<(const bags_struct & b) const{
		if (day != b.day)
			return day < b.day;
		if (time != b.time)
			return time < b.time;
		if (type_ != b.type_)
			return type_ < b.type_;
    }
}

; int main() {
	int n;
	cin >> n;
	vector<bags_struct> bags;
	for (int i = 0; i < n; ++i) {
		int h, m, s;
		cin >> h >> m >> s;
		int t_s = h * 3600 + m * 60 + s;
		cin >> h >> m >> s;
		int t_e = h * 3600 + m * 60 + s;
		int day = 0;
		if (t_s >= t_e) {
			bags.push_back(bags_struct({ t_s, 0, 0 }));
			bags.push_back(bags_struct({ 86400, 1, 0 }));
			day++;
		}

		bags.push_back(bags_struct({ 0, 0, day }));
		bags.push_back(bags_struct({ t_e, 1, day }));
	}

	int cnt = 0;
	int time = 0;
	int last_time = 0;
	sort(bags.begin(), bags.end());
 	for (auto & i : bags) {
		if (i.type_ == 0) {
			cnt++;
		}
		else if (i.type_ == 1) {
			cnt--;
			if (cnt == n-1) {
				time += i.time - last_time;
			}
		}
		last_time = i.time;
	}
	cout << time;
	return 0;
}
