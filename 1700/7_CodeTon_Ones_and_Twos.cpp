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
int helper() {
  int n, q;
  cin >> n;
  cin >> q;
  
  set<int> ones;
  vector<int> nums(n);
  int total = 0;
  int num;
  for (int i=0; i<n; i++)
  {
    cin >> num;
    nums[i] = num;
    total += num;
    if (num == 1) ones.insert(i);
  }

  int op, qnum, idx, cval;
  for (int i=0; i<q; i++)
  {
    cin >> op;
    if (op == 1)
    {
      cin >> qnum;
      if (qnum > total) cout << "NO" << endl;
      else if ((total-qnum)%2 == 0) cout << "YES" << endl;
      else
      {
        if (ones.size() == 0) cout << "NO" << endl;
        else
        {
          int left = total - (1+2 * *ones.begin());
          int right = total - (1+2*(n-*ones.rbegin()-1));
          if (max(left, right) >= qnum) cout << "YES" << endl;
          else cout << "NO" << endl;
        }
      }
    }
    else
    {
      cin >> idx;
      cin >> cval;
      total += cval-nums[idx-1];
      nums[idx-1] = cval;
      if (cval == 1) ones.insert(idx-1);
      else ones.erase(idx-1);
    }
  }

  return 0;
}

int main() {
  int cases;
  cin >> cases;
  for (int i=0; i<cases; i++) helper();
  return 0;
}

