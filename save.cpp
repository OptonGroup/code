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
#include <iomanip>  // fixed << setprecision(n)
#define endl '\n'
typedef long long ll;
using namespace std;

struct min_stack {
	vector<int> stack_val, stack_min;

	min_stack() {}

	void push(int n) {
		stack_val.push_back(n);
		int m_v = n;
		if (!stack_min.empty())
			m_v = min(m_v, stack_min.back());
		stack_min.push_back(m_v);
	}

	void pop() {
		stack_val.pop_back();
		stack_min.pop_back();
	}

	int top() {
		return stack_val.back();
	}

	bool empty() {
		return stack_val.empty();
	}

	int min_val() {
		return stack_min.back();
	}

};

struct min_queue {
	min_stack stack_in, stack_out;

	min_queue() {}

	void push(int n) {
		stack_in.push(n);
	}

	void balance() {
		if (stack_out.empty()) {
			while (!stack_in.empty()) {
				stack_out.push(stack_in.top());
				stack_in.pop();
			}
		}
	}

	void pop() {
		balance();
		stack_in.pop();
	}

	int front() {
		return stack_out.top();
	}

	bool empty() {
		return stack_in.empty() && stack_out.empty();
	}

	int min_val() {
		int mi = 1000000000;
		if (!stack_in.empty())
			mi = min(stack_in.min_val(), mi);
		if (!stack_out.empty())
			mi = min(stack_out.min_val(), mi);
		return mi;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	return 0;
}
