#include<utility>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<vector>
#include<map>
#include<queue>

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
  vector<int> arr(n);
  for (int i=0; i<n; i++)
    cin >> arr[i];
  
  int curr = 0;
  vector<int>left(n);
  for (int i=0; i<n; i++)
  {
    curr = max(curr, n-i-1+arr[i]);
    left[i] = curr;
  }

  curr = 0;
  vector<int>right(n);
  for (int i=n-1; i>=0; i--)
  {
    curr = max(curr, i+arr[i]);
    right[i] = curr;
  }

  int answer = INT_MAX;
  for (int i=0; i<n; i++)
  {
    int cost = arr[i];
    if (i > 0) cost = max(cost, left[i-1]);
    if (i < n-1) cost = max(cost, right[i+1]);
    answer = min(answer, cost);
  }
  cout << answer << endl;
  return 0;
}
