#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <vector>
#include <array>
#include <string>
#include <cstring>
#include <cctype>
#include <queue>
#include <cmath>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <complex>
#include <bitset>
#include <algorithm>
#include <functional>
#include <ctime>
#include <chrono>
#include <random>
#include <fstream>
#define rt return
#define mp make_pair
#define endl '\n'
#define rep(rep_iter, x) for (int rep_iter = 0; rep_iter < x; ++rep_iter)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define probel " "
#define frpn freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef pair<db, db> pdd;
typedef pair<ll, ll> pll;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int INF = 1000000007LL;
const ll LINF = 2LL << 60;
const int SIZE = 5050;
const double PI = 3.14159265358979323846;
const int base = 257;
const int MOD1 = 1000000007, MOD2 = 1072005019;

map <string, ll> prices;
map <string, vector<string>> crafts; // add
map <string, int> used; // add

int get_price(string name){     // add
    if (used[name]) return prices[name];
    used[name] = 1;

    ll ns = 0;
    for (auto u: crafts[name]){
        ll g_price = get_price(u);
        if (g_price == 0){
            ns = 0;
            break;
        }
        ns += g_price;
    }
    if (ns == 0) return prices[name];
    if (prices[name] == 0) return prices[name] = ns;
    return prices[name] = min(prices[name], ns);

}

int main() {
  frpn;
  int n;
  cin >> n;
  string h;
  vector<string> toget;
  for (int i = 0; i < n; ++i) {
    cin >> h;
    toget.pb(h);
  }
  int m;
  cin >> m;
  string s;
  int pr;
  for (int i = 0; i < m; ++i) {
    cin >> s >> pr;
    prices[s] = pr;
  }
  int k;
  int a;
  int ing;
  cin >> k;
  string name;
  string to_craft;
  for (int i = 0; i < k; ++i) {
    cin >> a;
    cin >> to_craft;
    ll cnt = 0;
    for (int j = 0 ; j < a; ++j) {
      cin >> name;
      crafts[to_craft].push_back(name); // change
    }
  }
  ll ans = 0;
  for (auto& el : toget) {      // change
    ll g_price = get_price(el);
    if (g_price == 0){
        cout << -1;
        return 0;
    }
    ans += g_price;
  }
  cout << ans;
}
