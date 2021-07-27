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

int dp(int num){
    if (nums[num-1] != -1){
        return nums[num-1];
    }
    
    if (num%2 != 0){
        nums[num-1] = dp(num-1)+1;
    } else{
        nums[num-1] = dp(num/2)+1;
    }
    if (num%3 == 0){
        nums[num-1] = min(dp(num/3)+1, nums[num-1]);
    }
    return nums[num-1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
    cin >> n;
    nums.resize(n*2, -1);
    nums[0] = 0;
    int ans = dp(n);
    while (n != 1){
        if ((nums[n-1] == nums[n/3-1]+1) && (n%3 == 0)){
            cout << 3;
            n /= 3;
        } else if((nums[n-1] == nums[n/2-1]+1) && (n%2 == 0)){
            cout<<2;
            n/=2;
        } else{
            cout << 1;
            n-=1;
        }
    }
    

	return 0;
}
