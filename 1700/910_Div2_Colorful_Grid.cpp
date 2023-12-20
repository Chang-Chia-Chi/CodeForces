#include <utility>
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
int helper() {
  int n, m, k;
  cin >> n;
  cin >> m;
  cin >> k;
  if ((n-1 + m-1)%2 != k%2)
  {
    cout << "NO" << endl;
    return 0;
  }
  if (n-1 + m-1 > k)
  {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  vector<vector<string>> rows(n, vector<string>(m-1));
  vector<vector<string>> cols(n-1, vector<string>(m));
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m-1; j++)
    {
      if (j%2 == 0) rows[i][j] = "B";
      else rows[i][j] = "R";
    }
  }

  if ((k-(n+m-2)) % 4 == 0)
  {
    if ((n+m-2)%2 == 0)
    {
      rows[n-1][m-2] = "B";
      rows[n-2][m-2] = "B";
    }
    else
    {
      rows[n-1][m-2] = "R";
      rows[n-2][m-2] = "R";
    }

    for (int i=0; i<n-1; i++)
    {
      string color = "B";
      if ((m+i)%2 == 0) color = "R";
      for (int j=0; j<m; j++)
        cols[i][j] = color;
    }
  }
  else
  {
    if ((n+m-2)%2 == 0)
    {
      rows[n-1][m-2] = "R";
      rows[n-2][m-2] = "R";
    }
    else
    {
      rows[n-1][m-2] = "B";
      rows[n-2][m-2] = "B";
    }

    for (int i=0; i<n-2; i++)
    {
      string color = "B";
      if ((m+i)%2 == 0) color = "R";
      for (int j=0; j<m; j++)
        cols[i][j] = color;
    }
    for (int j=0; j<m; j++)
      cols[n-2][j] = cols[n-3][j];
  }

  for (int i=0; i<n; i++)
  {
    string row = rows[i][0];
    for (int j=1; j<m-1; j++)
      row += " " + rows[i][j];
    cout << row << endl;
  }
  for (int i=0; i<n-1; i++)
  {
    string col = cols[i][0];
    for (int j=1; j<m; j++)
      col += " " + cols[i][j];
    cout << col << endl;
  }
  return 0;
}


int main() {
  int cases;
  cin >> cases;
  for (int i=0; i<cases; i++)
    helper();
  return 0;
}
