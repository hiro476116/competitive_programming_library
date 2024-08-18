#include <algorithm>
#include <climits>
#include <cstdio>
#include <set>
#include <utility>

struct nekoset {
private:
  std::set<std::pair<int, int>> s;

public:
  nekoset() {
    s.emplace(INT_MIN, INT_MIN);
    s.emplace(INT_MAX, INT_MAX);
  }

  bool contains(int x) const {
    auto it = std::prev(s.lower_bound(std::make_pair(x+1, x+1)));
    auto [l, u] = *it;
    return l <= x && x <= u;
  }

  bool insert(int x) {
    auto nit = s.lower_bound(std::make_pair(x+1, x+1));
    auto it = std::prev(nit);
    auto [l, u] = *it;
    auto [nl, nu] = *nit;
    if (l <= x && x <= u) return false;
    if (u == x-1) {
      if (nl == x+1) {
        s.erase(it);
        s.erase(nit);
        s.emplace(l, nu);
      } else {
        s.erase(it);
        s.emplace(l, x);
      }
    } else {
      if (nl == x+1) {
        s.erase(nit);
        s.emplace(x, nu);
      } else {
        s.emplace(x, x);
      }
    }
    return true;
  }

  int mex(int x = 0) const {
    auto [l, u] = *std::prev(s.lower_bound(std::make_pair(x+1, x+1)));
    if (l <= x && x <= u) {
      return u+1;
    } else {
      return x;
    }
  }
};

int main() {
  int n;
  scanf("%d", &n);

  nekoset s;
  for (int i = 0; i < n; ++i) {
    int p;
    scanf("%d", &p);
    s.insert(p);
    printf("%d\n", s.mex());
  }
}
