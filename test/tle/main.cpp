#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, r[201], p[20001], pre[20001], dp[20001][201], ans = 0;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) {
		return a / b - ((a ^ b) < 0 && a % b);
	}
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({ k, m, 0 }), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
}hull[201];
ll R(ll i) { return abs(r[i] - r[i - 1]); }
ll M1(ll i, ll j) { return 2ll * R(j) - 2ll * p[i]; }
ll M2(ll i, ll j) { return -2ll * R(j) - 2ll * p[i]; }
ll C(ll i, ll j) { return R(j) * R(j) + pre[i]; }
ll C1(ll i, ll j) { return -2ll * R(j) * p[i] + p[i] * p[i] - pre[i] + dp[i][j - 1]; }
ll C2(ll i, ll j) { return 2ll * R(j) * p[i] + p[i] * p[i] - pre[i] + dp[i][j - 1]; }
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> p[i], pre[i] = pre[i - 1] + p[i] * p[i];
	for (int i = 1; i <= m; i++) cin >> r[i];
	for (int i = 1; i <= n - m + 1; i++) dp[i][1] = pre[i - 1];
	for (int j = 2; j <= m; j++) {
		for (int i = j; i <= n; i++) {
			hull[j].add(M1(i - 1, j), C1(i - 1, j));
			hull[j].add(M2(i - 1, j), C2(i - 1, j));
			dp[i][j] = C(i, j) + hull[j].query(p[i]);
		}
	}
	for (int i = m; i <= n; i++) ans = max(ans, dp[i][m] + pre[n] - pre[i]);
	cout << ans << endl;
}
/*
#include <iostream>
using namespace std;
int main(){
	while(1) cout<<"hi\n";
}*/
