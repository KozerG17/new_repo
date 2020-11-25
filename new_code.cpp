#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;

#pragma region
typedef long long ll;
typedef string str;
typedef double db;
template<typename T>using heapmax = priority_queue<T>;
template<typename T>using heapmin = priority_queue<T, vector<T>, greater<T>>;

template<typename T>void maximize(T &a, T b) { if (a < b) a = b; }
template<typename T>void minimize(T &a, T b) { if (a > b) a = b; }
template<typename T>T sqr(T a) { return a*a; }
template<typename T>T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }
template<typename T>T lcm(T a, T b) { return a/gcd(a, b)*b; }
template<typename T>T pw(T a, T n) { if (n == 1) return a; T t = pw(a, n/2); return (n & 1) ? t*t*a : t*t + 1; }
template<typename T>ll htoi(T x) { return 9 * (x >> 6) + (x & 017); }

template<typename T>void gstr(T& s) { char c; while (c = getchar(), c == ' ' || c == '\n' || c == '\t'); s.clear(); s.push_back(c); while (c = getchar(), c != EOF && c != ' ' && c != '\n' && c != '\t') s.push_back(c); }
template<typename T>void gline(T& s) { char c; while (c = getchar(), c == '\n'); s.clear(); s.push_back(c); while (c = getchar(), c != EOF && c != '\n') s.push_back(c); }
template<typename T>inline void gN(T& n) { char c; while (c = getchar(), c != '-' && (c < '0' || c > '9')); bool sign(c == '-'); if (sign) c = getchar(); n = c - '0'; while (c = getchar(), c >= '0' && c <= '9' ) n = 10*n + c - '0'; if (sign) n = -n; }
ll    gll() { ll x;	 return 	   cin >> x, x; }
int	 gint() { int x; return 	   cin >> x, x; }
str  gstr() { str x; return        cin >> x, x; }
str gline() { str x; return getline(cin, x), x; }

vector<str> split(const str& s, char c) { vector<str> v; stringstream ss(s); str x; while (getline(ss, x, c)) v.emplace_back(x); return move(v); }
template<typename T, typename... Args> inline str arrStr(T arr, int n) { stringstream s; s << "["; for(int i = 0; i < n - 1; i++) s << arr[i] << ","; s << arr[n - 1] << "]"; return s.str(); }
#define EVARS(args...) {__evars_begin(__LINE__); __evars(split(#args, ',').begin(), args);}
inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
template<typename T> inline void __evars_out_var(vector<T> val) { cerr << arrStr(val, val.size()); }
template<typename T> inline void __evars_out_var(T* val) { cerr << arrStr(val, 10); }
template<typename T> inline void __evars_out_var(T val) { cerr << val; }
inline void __evars(vector<str>::iterator it) { cerr << endl; }
template<typename T, typename... Args> inline void __evars(vector<str>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << "="; __evars_out_var(a); cerr << "; "; __evars(++it, args...); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
	size_t operator()(uint64_t x) const { return splitmix64(x + rng()); }
};
#pragma endregion



const int	 MAX  = 2e9;
const ll	 LMAX = 9e18;
const int    MOD  = 1e9 + 7;
const double PI   = acos(-1);







void query(int nTest) {
	
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("m.INP", "r", stdin);
	freopen("m.OUT", "w", stdout);
#endif
	cin.tie(NULL)->sync_with_stdio(false);
	cout << fixed << setprecision(0);

	for (int t, i = (cin >> t, 1); i <= t; query(i++));

	return 0;
}



/*

-----------------
input:          |

-----------------
output:	        |

-----------------

*/
