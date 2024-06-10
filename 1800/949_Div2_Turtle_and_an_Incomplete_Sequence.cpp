#include<utility>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<chrono>

template <
    class result_t   = std::chrono::milliseconds,
    class clock_t    = std::chrono::steady_clock,
    class duration_t = std::chrono::milliseconds
>
auto since(std::chrono::time_point<clock_t, duration_t> const& start)
{
    return std::chrono::duration_cast<result_t>(clock_t::now() - start);
}

using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

const int MOD = 1000000007;

// ========== Math Trick ==========
vector<int>Eratosthenes(int n)
{
    vector<int>q(n+1,0);
    vector<int>primes;
    for (int i=2; i<=sqrt(n); i++)
    {
        if (q[i]==1) continue;
        int j=i*2;
        while (j<=n)
        {
            q[j]=1;
            j+=i;
        }
    }        
    for (int i=2; i<=n; i++)
    {
        if (q[i]==0)
            primes.push_back(i);                
    }
    return primes;
}

ll gcd(ll a, ll b) {
  return b==0?a:gcd(b,a%b);
}

ll lcm(ll a, ll b) {
  return a*b/gcd(a, b);
}

int fpow(int a, int b, int m) {
  a %= m;
  int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}


// ========== Main Function ==========
int validation(int l, int r, ll lca, vector<ll>& nums) {
  if (r-l == 1) return 1;

  int lstep = 0;
  ll lnum = nums[l];
  while (lnum != lca) {
    lnum >>= 1;
    lstep++;
  }

  int rstep = 0;
  ll rnum = nums[r];
  while (rnum != lca) {
    rnum >>= 1;
    rstep++;
  }

  int diff = (r-l) - (lstep+rstep);
  if (diff < 0 || diff % 2) return 0;

  int p1 = l+1;
  lnum = nums[l];
  while (lnum != lca) {
    lnum >>= 1;
    nums[p1] = lnum;
    p1++;
  }

  int p2 = r-1;
  rnum = nums[r];
  while (rnum != lca) {
    rnum >>= 1;
    nums[p2] = rnum;
    p2--;
  }

  int t = 2;
  while (p1 <= p2) {
    nums[p1] = lca * t;
    p1++;
    if (t == 2) t = 1;
    else t = 2;
  }
  return 1;

}

ll fetchLCA(ll p, ll q) {
  vector<ll> path1;
  while (p) {
    path1.push_back(p);
    p /= 2;
  }
  vector<ll> path2;
  while (q) {
    path2.push_back(q);
    q /= 2;
  }
  reverse(path1.begin(), path1.end());
  reverse(path2.begin(), path2.end());

  int pp = path1.size()-1;
  int qp = path2.size()-1;
  while (pp >= 0 && qp >= 0) {
    if (path1[pp] > path2[qp]) pp--;
    else if (path1[pp] < path2[qp]) qp--;
    else return path1[pp];
  }
  return 1;
  
}


void helper() {
  int n;
  cin >> n;
  vector<ll> nums(n, 0);
  for (int i=0; i<n; i++)
    cin >> nums[i];

  int r = 0;
  while (r < n && nums[r] == -1) r++;
  if (r == n) nums[n-1] = 1;

  int flag = 1;
  for (int i = r-1; i >= 0; i--) {
    if (i == n-1) continue;
    if (flag) {
      nums[i] = nums[i+1] * 2;
      flag = 0;
    } else {
      nums[i] = nums[i+1] / 2;
      flag = 1;
    }
  }
  
  int l = r;
  while (l < n) {
    r++;
    while (r < n && nums[r] == -1) r++;
    if (r == n) break;
    
    ll lca = fetchLCA(nums[l], nums[r]);
    if (!validation(l, r, lca, nums)) {
      cout << -1 << endl;
      return;
    }
    l = r;
  }

  flag = 1;
  for (int i = l+1; i < n; i++) {
    if (flag) {
      nums[i] = nums[i-1] * 2;
      flag = 0;
    } else {
      nums[i] = nums[i-1] / 2;
      flag = 1;
    }
  }

  for (int i = 1; i < n; i++) {
    if (nums[i] != nums[i-1]/2 &&
        nums[i] != nums[i-1]*2 &&
        nums[i] != nums[i-1]*2+1) {
          cout << -1 << endl;
          return;
        }
  }

  for (int i = 0; i < n; i++)
    cout << nums[i] << " ";
  cout << endl;
}


int main() {
  int c;
  cin >> c;
  for (int i=0; i<c; i++) {
    helper();
  }
  return 0;
}
