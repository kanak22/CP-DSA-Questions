#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 5;
int a[N], b[N];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  map<int, int> mp;

  sort(b, b + n);
  
  for (int i = 0; i < n; i++) {
    mp[b[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    a[i] = mp[a[i]];
  }
  int L = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] != i) {
      L = i;
      break;
    }
  }
  int R = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] != i) {
      R = i;
      break;
    }
  }
  if (L == -1 || R == -1) {
    cout << "yes" << endl;
    cout << 1 << " " << 1 << endl;
  } else {
    reverse(a + L, a + R + 1);
    int ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i] != i) {
        ok = false;
      }
    }
    if (ok) {
      cout << "yes" << endl;
      cout << L + 1 << " " << R + 1 << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}
