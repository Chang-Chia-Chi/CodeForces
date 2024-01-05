#include <utility>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<stack>

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
int cmp(PLL& p1, PLL& p2) {
  if (p1.first == p2.first)
    return p1.second < p2.second;
  return p1.first < p2.first;
}

int helper() {
  ll n, c;
  cin >> n;
  cin >> c;
  vector<ll> arr(n);
  for (ll i=0; i<n; i++)
    cin >> arr[i];
  
  ll curr = arr[0];
  vector<PLL> smaller;
  for (ll i=1; i<n; i++)
  {
    if (arr[i] >= c*(i+1))
      curr += arr[i];
    else
      smaller.push_back({c*(i+1)-arr[i], i});
  }

  sort(smaller.begin(), smaller.end(), cmp);
  for (ll i=0; i<smaller.size(); i++)
  {
    curr += arr[smaller[i].second];
    if (curr < (smaller[i].second+1) * c)
    {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}

int main() {
  int cases;
  cin >> cases;
  for (int i=0; i<cases; i++)
    helper();
  return 0;
}
