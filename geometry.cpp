#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using ld=long double;
ll inf=10010010010010010;
ll mod=998244353;
const double EPS = 0.0001;
struct point{
  double x, y;
  point(){
  }
  point(double x, double y): x(x), y(y){
  }
  point operator +(point P){
    return point(x + P.x, y + P.y);
  }
  point operator -(point P){
    return point(x - P.x, y - P.y);
  }
  point operator *(double k){
    return point(x * k, y * k);
  }
  point operator /(double k){
    return point(x / k, y / k);
  }
};
point rotate90(point P){
  return point(P.y, -P.x);
}
point midpoint(point P, point Q){
  return (P + Q) / 2;
}
double abs(point P){
  return sqrt(P.x * P.x + P.y * P.y);
}
double dist(point P, point Q){
  return abs(Q - P);
}
double dot(point P, point Q){
  return P.x * Q.x + P.y * Q.y;
}
double cross(point P, point Q){
  return P.x * Q.y - P.y * Q.x;
}
double is_collinear(point P, point Q, point R){
  return abs(cross(Q - P, R - P)) < EPS;
}
struct line{
  point A, B;
  line(point A, point B): A(A), B(B){
  }
};
point vec(line L){
  return L.B - L.A;
}
line perpendicular_bisector(point P, point Q){
  point A = midpoint(P, Q);
  point B = A + rotate90(Q - P);
  return line(A, B);
}
point line_intersection(line L1, line L2){
  return L1.A + vec(L1) * cross(L2.A - L1.A, vec(L2)) / cross(vec(L1), vec(L2));
}
point circumcenter(point A, point B, point C){
  return line_intersection(perpendicular_bisector(A, B), perpendicular_bisector(A, C));
}
double point_line_distance(point P, line L){
  return abs(cross(P - L.A, vec(L))) / abs(vec(L));
}
struct circle{
  point C;
  double r;
  circle(){
  }
  circle(point C, double r): C(C), r(r){
  }
};
bool in_circle(point P, circle C){
  return dist(P, C.C) <= C.r + EPS;
}
pair<point, point> circle_intersection(circle C1, circle C2){
  double d = dist(C1.C, C2.C);
  double x = (C1.r * C1.r - C2.r * C2.r + d * d) / (2 * d);
  point A = C1.C + (C2.C - C1.C) / d * x;
  double y = sqrt(C1.r * C1.r - x * x);
  point B = rotate90(C2.C - C1.C) / d * y;
  return make_pair(A + B, A - B);
}
int main(){
    ll n;
    cin >> n;
    vector<point>p(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    vector<point>c;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i+1; j< n; j++)
        {
            c.push_back(midpoint(p[i],p[j]));
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i+1; j < n; j++)
        {
            for (ll k = j+1; k < n; k++)
            {
                c.push_back(circumcenter(p[i],p[j],p[k]));
            }
        }
    }
    double ans=inf;
    for (ll i = 0; i < c.size(); i++)
    {
        double dis=0;
        for (ll j = 0; j < n; j++)
        {
            dis=max(dis,dist(c[i],p[j]));
        }
        ans=min(ans,dis);
    }
    cout << setprecision(14) << ans << endl;
}