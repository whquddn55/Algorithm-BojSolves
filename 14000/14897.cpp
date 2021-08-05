#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
    os << pai.first << ' ' << pai.second;
    return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
    is >> pai.first >> pai.second;
    return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

// region FASTIO
/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-05-06
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation for cin, cout.
 */
constexpr int SZ = 1 << 18;

class INPUT {
private:
   char read_buf[SZ];
   int read_idx, next_idx;
   bool __END_FLAG__, __GETLINE_FLAG__;
public:
   explicit operator bool() { return !__END_FLAG__; }
   bool IsBlank(char c) { return c == ' ' || c == '\n'; }
   bool IsEnd(char c) { return c == '\0'; }
   char _ReadChar() {
      if (read_idx == next_idx) {
         next_idx = fread(read_buf, sizeof(char), SZ, stdin);
         if (next_idx == 0) return 0;
         read_idx = 0;
      }
      return read_buf[read_idx++];
   }
   char ReadChar() {
      char ret = _ReadChar();
      for (; IsBlank(ret); ret = _ReadChar());
      return ret;
   }
   template<typename T> T ReadInt() {
      T ret = 0;
      char cur = _ReadChar();
      bool flag = 0;
      for (; IsBlank(cur); cur = _ReadChar());
      if (cur == '-') flag = 1, cur = _ReadChar();
      for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
      if (IsEnd(cur)) __END_FLAG__ = 1;
      return flag ? -ret : ret;
   }
   string ReadString() {
      string ret;
      char cur = _ReadChar();
      for (; IsBlank(cur); cur = _ReadChar());
      for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
      if (IsEnd(cur)) __END_FLAG__ = 1;
      return ret;
   }
   double ReadDouble() {
      string ret = ReadString();
      return stod(ret);
   }
   string getline() {
      string ret;
      char cur = _ReadChar();
      for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
      if (__GETLINE_FLAG__) __END_FLAG__ = 1;
      if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
      return ret;
   }
   friend INPUT &getline(INPUT &in, string &s) {
      s = in.getline();
      return in;
   }
} _in;

class OUTPUT {
private:
   char write_buf[SZ];
   int write_idx;
public:
   ~OUTPUT() { Flush(); }
   explicit operator bool() { return 1; }
   void Flush() {
      fwrite(write_buf, sizeof(char), write_idx, stdout);
      write_idx = 0;
   }
   void WriteChar(char c) {
      if (write_idx == SZ) Flush();
      write_buf[write_idx++] = c;
   }
   template<typename T> int GetSize(T n) {
      int ret = 1;
      for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
      return ret;
   }
   template<typename T> void WriteInt(T n) {
      int sz = GetSize(n);
      if (write_idx + sz >= SZ) Flush();
      if (n < 0) write_buf[write_idx++] = '-', n = -n;
      for (int i = sz; i-- > 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
      write_idx += sz;
   }
   void WriteString(string s) { for (auto &c : s) WriteChar(c); }
   void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT &operator>>(INPUT &in, char &i) {
   i = in.ReadChar();
   return in;
}
INPUT &operator>>(INPUT &in, string &i) {
   i = in.ReadString();
   return in;
}
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>> * = nullptr>
INPUT &operator>>(INPUT &in, T &i) {
   if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
   else if constexpr (is_integral_v<T>) i = in.ReadInt<T>();
   return in;
}

OUTPUT &operator<<(OUTPUT &out, char i) {
   out.WriteChar(i);
   return out;
}
OUTPUT &operator<<(OUTPUT &out, string i) {
   out.WriteString(i);
   return out;
}
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>> * = nullptr>
OUTPUT &operator<<(OUTPUT &out, T i) {
   if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
   else if constexpr (is_integral_v<T>) out.WriteInt<T>(i);
   return out;
}

/* macros */
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
#define fastio 1

#define INF (INT_MAX / 2)
#define MAX_N 1000005
#define MOD 1000000007

int n, q;
int arr[MAX_N];
pii query[MAX_N];
int idx[MAX_N];

vector<int> mapper;
int in[MAX_N];
int ans[MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		mapper.push_back(arr[i]);
	}

	sort(mapper.begin(), mapper.end());
	mapper.erase(unique(mapper.begin(), mapper.end()), mapper.end());
	for (int i = 0; i < n; ++i) 
		arr[i] = lower_bound(mapper.begin(), mapper.end(), arr[i]) - mapper.begin();

	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> query[i].first >> query[i].second;
		query[i].first--;
		query[i].second--;
		idx[i] = i;
	}

	sort(idx, idx + q, [](int a, int b) -> bool {
		return pii(query[a].first / sqrt(q), query[a].second) < pii(query[b].first / sqrt(q), query[b].second);
	});

	int l = query[idx[0]].first, r  = query[idx[0]].second;
	int cnt = 0;
	for (int i = l; i <= r; ++i) {
		if (!in[arr[i]]) 
			++cnt;
		++in[arr[i]];
	}
	ans[idx[0]] = cnt;
	for (int i = 1; i < q; ++i) {
		pii t = query[idx[i]];

		for (int i = l; i < t.first; ++i) {
			if (in[arr[i]] == 1) 
				--cnt;
			--in[arr[i]];
		}
		for (int i = t.first; i < l; ++i) {
			if (!in[arr[i]]) 
				++cnt;
			++in[arr[i]];
		}

		for (int i = r + 1; i <= t.second; ++i) {
			if (!in[arr[i]]) 
				++cnt;
			++in[arr[i]];
		}
		for (int i = t.second + 1; i <= r; ++i) {
			if (in[arr[i]] == 1) 
				--cnt;
			--in[arr[i]];
		}
		l = t.first;
		r = t.second;
		ans[idx[i]] = cnt;
	}

	for(int i = 0; i < q; ++i)
		cout << ans[i] << '\n';
	

	return 0;
}
