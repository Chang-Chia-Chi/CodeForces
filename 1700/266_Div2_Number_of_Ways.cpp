#include <utility>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<vector>
#include<map>

using namespace std;
using ll = long long;
using PII = pair<int, int>;

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
int main() {
  int n;
  cin >> n;
  
  ll arrSum = 0;
  vector<ll> arr(n, 0);
  for (int i=0; i<n; i++)
  {
    cin >> arr[i];
    arrSum += arr[i];
  }
  if (n<3 || arrSum%3)
  {
    cout << 0 << endl;
    return 0;
  }
  
  ll sufsum = 0;
  ll sufcnt = 0;
  vector<ll> suffix(n, 0);
  for (int i=n-1; i>=0; i--)
  {
    sufsum += arr[i];
    if (sufsum == arrSum/3)
      sufcnt++;
    suffix[i] = sufcnt;
  }


  ll answer = 0;
  ll presum = 0;
  for (int i=0; i+2<n; i++)
  {
    presum += arr[i];
    if (presum == arrSum/3)
      answer += suffix[i+2];
  }
  cout << answer << endl;
  return 0;
}
