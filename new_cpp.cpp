#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;

#pragma region
typedef long long ll;
typedef string str;
template<typename T>using heapmax = priority_queue<T>;
template<typename T>using heapmin = priority_queue<T, vector<T>, greater<T>>;

template<typename T>inline void maximize(T &a, T b) { if (a < b) a = b; }
template<typename T>inline void minimize(T &a, T b) { if (a > b) a = b; }
template<typename T>inline T sqr(T a) { return a*a; }
template<typename T>inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }
template<typename T>inline T lcm(T a, T b) { return a/gcd(a, b)*b; }
template<typename T>inline T pw(T a, T n) { if (n == 1) return a; T t = pw(a, n/2); return (n & 1) ? t*t*a : t*t + 1; }
template<typename T>inline str tostr(T x) { stringstream ss;  ss << x; return ss.str(); }
template<typename T>inline T tonum(str x) { stringstream ss(x); T n; ss >> n; return n; }

template<typename T>inline void gstr(T& s) { char c; while (c = getchar(), c == ' ' || c == '\n' || c == '\t'); s.clear(); s.push_back(c); while (c = getchar(), c != EOF && c != ' ' && c != '\n' && c != '\t') s.push_back(c); }
template<typename T>inline void gline(T& s) { char c; while (c = getchar(), c == '\n'); s.clear(); s.push_back(c); while (c = getchar(), c != EOF && c != '\n') s.push_back(c); }
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
	size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }
};
#pragma endregion



const int	 MAX  = 1 << 30;
const ll	 LMAX = 1ll << 60;
const int    MOD  = 1e9 + 7;
const double PI   = acos(-1);



struct cube { int t, d, r, c; };
const int N = 5e3;

int n;
cube a[N];

int dp[N];
int trace[N];
int ans;



void query() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i].d >> a[i].r >> a[i].c;
		if (a[i].d < a[i].r) swap(a[i].d, a[i].r);
		if (a[i].r < a[i].c) swap(a[i].r, a[i].c);
		a[i].t = i, a[i].s = a[i].r * a[i].c;
	}
	sort (a, a + n, [](cube a, cube b) {
		return a.d > b.d || (a.d == b.d && a.r >= b.r);
	});

	#define print_ans cout << a[ans].t + 1 << ' ' << a[ans].d << ' ' << a[ans].r << ' ' << a[ans].c << '\n'

	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		trace[i] = i, dp[i] = 1;
		for (int j = 0; j < i; ++j)
			if (a[j].r >= a[i].r && dp[i] < dp[j] + 1)
				trace[i] = j, dp[i] = dp[j] + 1;
		if (dp[i] > dp[ans]) ans = i;
	}
	cout << dp[ans] << '\n';
	for (print_ans; ans != trace[ans]; ans = trace[ans], print_ans);

	dp[0] = a[0].c;
	for (int i = 1; i < n; ++i) {
		trace[i] = i, dp[i] = a[i].c;
		for (int j = 0; j < i; ++j)
			if (a[j].r >= a[i].r && dp[i] < dp[j] + 1)
				trace[i] = j, dp[i] = dp[j] + a[i].c;
		if (dp[i] > dp[ans]) ans = i;
	}
	cout << dp[ans] << '\n';
	for (print_ans; ans != trace[ans]; ans = trace[ans], print_ans);
}



int main() {
#ifdef LOCAL
	freopen("m.INP", "r", stdin);
	freopen("m.OUT", "w", stdout);
#endif
	cin.tie(NULL)->sync_with_stdio(false);
	cout << fixed << setprecision(0);
	for (int t = 1; t--; query());

	return 0;
}



/*

-----------------
input:          |

-----------------
output:	        |

-----------------

*/
