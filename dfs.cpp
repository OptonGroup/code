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


struct Event(){
    int x, type_, index;
    Event(){}
    Event(int x, int type_, int index){
        x(x) = x; type_(type) = type_; index(index) = index;
    }
    bool operator<(const Event, & b) const{
        if (x != b.x)
            return x < b.x;
        if (type_ != b.type_)
            return type_ < b.type_;
        return index < b.index;
    }
}

int n, m;
cin >> n >> m;
vector<Event> events;
for (int i = 0; i < n; ++i){
    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    events.push_back(Event({a, 0, i}))
    events.push_back(Event({b, 2, i}))
}

vector <int> ans(m,0);
for(int i = 0; i < m; ++i){
    cin >> a;
    events.push_back(Event({a, 0, i}));
}

int cnt = 0;
sort(events.begin(), events.end())
for (auto & i: events){
    if (i.type_ == 0){
        cont++;   
    }
    else if (i.type_ == 1){
        cont--;   
    }
    
}
