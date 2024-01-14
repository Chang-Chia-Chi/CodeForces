#include <utility>
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
int helper() {
  int n;
  cin >> n;
  vector<ll> arr(n);
  for (int i=0; i<n; i++)
    cin >> arr[i];
  
  map<ll, int> pows;
  ll curr = 1;
  for (int i=0; i<32; i++)
  {
    pows[curr] = i;
    curr *= 2;
  }

  ll p1 = 0;
  ll answer = 0;
  for (int i=1; i<n; i++)
  {
    if (arr[i-1] > arr[i])
    {
      ll t = arr[i-1]/arr[i] + (arr[i-1]%arr[i] > 0);
      auto it = pows.lower_bound(t);
      p1 += it->second;
    }
    else if (arr[i-1] < arr[i])
    {
      ll t = arr[i]/arr[i-1];
      auto it = pows.upper_bound(t);
      p1 = max(0, (int)p1-(it->second - 1));
    }
    answer += p1;
  }
  cout << answer << endl;
  return 0;
}

int main() {
  int n;
  cin >> n;
  for (int i=0; i<n; i++)
    helper();
  return 0;
}
