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
int helper1() {
  int n, m;
  cin >> n; cin >> m;
  vector<int> a(n);
  vector<int> b(m);
  for (int i=0; i<n; i++)
    cin >> a[i];
  for (int i=0; i<m; i++)
    cin >> b[i];
  
  a.insert(a.begin(), INT_MAX/2);
  a.push_back(0);
  sort(b.begin(), b.end());
  
  stack<int> Stack;
  vector<vector<int>> inserts(n+2);
  vector<int> b_used(m);
  for (int i=0; i<=n+1; i++)
  {
    while (!Stack.empty() && a[i] <= a[Stack.top()])
    {
      int j = Stack.top();
      Stack.pop();
      int up = a[j];
      int down = a[i];
      int lidx = distance(b.begin(), lower_bound(b.begin(), b.end(), down));
      int ridx = distance(b.begin(), prev(upper_bound(b.begin(), b.end(), up)));
      while (ridx >= lidx && !b_used[ridx])
      {
        b_used[ridx] = 1;
        inserts[j].push_back(b[ridx]);
        ridx--;
      }

      vector<int> tmp;
      while (ridx >= lidx && !b_used[lidx])
      {
        b_used[lidx] = 1;
        tmp.push_back(b[lidx]);
        lidx++;
      }
      for (int k=tmp.size()-1; k>=0; k--)
        inserts[j].push_back(tmp[k]);
    }
    Stack.push(i);
  }

  for (int i=0; i<n+1; i++)
  {
    if (i>0) cout << a[i] << " ";
    for (auto in: inserts[i])
      cout << in << " ";
  }
  cout << endl;
  return 0;
}

int helper2() {
  int n, m;
  cin >> n; cin >> m;
  vector<int> a(n);
  vector<int> b(m);
  for (int i=0; i<n; i++)
    cin >> a[i];
  for (int i=0; i<m; i++)
    cin >> b[i];

  sort(b.rbegin(), b.rend());
  int pa = 0;
  int pb = 0;
  while (pa < n && pb < m)
  {
    if (a[pa] > b[pb])
      cout << a[pa++] << " ";
    else
      cout << b[pb++] << " ";
  }
  while (pa < n)
    cout << a[pa++] << " ";
  while (pb < m)
    cout << b[pb++] << " ";
  cout << endl;
  
  return 0;
}

int main() {
  int cases;
  cin >> cases;
  for (int i=0; i<cases; i++)
    helper2();
  return 0;
}

