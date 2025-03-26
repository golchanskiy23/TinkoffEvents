#include <bits/stdc++.h>

using ull = unsigned long long;
using vpp = std::vector<std::pair<ull,ull>>;
using int64 = long long;

const int MAX_EXP = 100;
const int MOD = 998244353;

std::string func1(){
    std::string s; std::cin >> s;
    bool flag = false;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'R') flag = true;
        if(s[i] == 'M' && !flag){
            return "No";
        }
    }
    return "Yes";
}

void func2(){
    int n;
    std::cin >> n;
    
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<long long> flowers;
    for (int i = 0; i <= MAX_EXP; ++i) {
        flowers.push_back(1LL << i); 
    }
    
    std::vector<long long> possible_sums;
    for (int i = 0; i <= MAX_EXP - 3; ++i) {
        for (int j = i + 1; j <= MAX_EXP - 2; ++j) {
            for (int k = j + 1; k <= MAX_EXP; ++k) {
                possible_sums.push_back(flowers[i] + flowers[j] + flowers[k]);
            }
        }
    }

    std::sort(possible_sums.begin(), possible_sums.end());

    for (int i = 0; i < n; ++i) {
        long long budget = a[i];
        if(budget < 7){
            std::cout << -1 << '\n';
            continue;
        }
        
        auto it = std::lower_bound(possible_sums.begin(), possible_sums.end(), budget + 1);
        
        if (it == possible_sums.begin()) {
            std::cout << -1 << '\n';
        } else {
            --it;
            std::cout << *it << '\n';
        }
    }

}

void func3(){
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    int a1 = a[0];
    int a2 = a[1];

    std::vector<int> corrections;
    
    for(int i = 2; i < n; ++i){
        int curr = a[i], f=2*1000000000,s=2*1000000000;
        if(curr < a1) f = a1-curr;
        if(curr > a2) s = curr-a2;
        corrections.push_back(std::min(f,s));
    }
    
    long long ans = 0;
    for(int i = 0; i < k; ++i){
        if(corrections[i] == 2*1000000000) continue;
        ans += corrections[i];
    }
    std::cout << ans;
}

void func4(){
    ull n,x,y,z, t; std::cin >> n >> x >> y >> z;
    std::vector<ull> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> t;
        v[i] = t;
    }
    
    vpp v1(n), v2(n), v3(n);
    for(int i = 0; i < n; ++i){
        v1[i] = std::make_pair(x-v[i]%x, i);
        v2[i] = std::make_pair(y-v[i]%y, i);
        v3[i] = std::make_pair(z-v[i]%z, i);
    }
    
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    std::sort(v3.begin(), v3.end());
    
    std::set<std::pair<ull,ull>> s;
    s.insert(v1[0]);
    s.insert(v2[0]);
    s.insert(v3[0]);
    
    ull ans = 0;
    for(auto& a : s){
        ans += a.first;
    }
    std::cout << ans;
}

void func5(){
    int n;
    int64 s;
    std::cin >> n >> s;

    std::vector<int64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int64 result = 0;

    for (int l = 0; l < n; l++) {
        int64 sum = 0;
        int cuts = 0;

        for (int r = l; r < n; r++) {
            sum += a[r];
            if (sum > s) {
                cuts = (sum + s - 1) / s - 1;
            }

            result += cuts + 1;
        }
    }
    std::cout << result << '\n';
}

struct Point {
    int x, y;
};

bool isCollinear(Point a, Point b, Point c) {
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) == 0;
}

void func6(){
    int n;
    std::cin >> n;

    std::vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    std::sort(points.begin(), points.end(), [](Point a, Point b) {
        return std::make_pair(a.x, a.y) < std::make_pair(b.x, b.y);
    });

    bool used[n];
    for(int i = 0; i < n; ++i) used[i] = false;
    int maxTriples = 0;

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        for (int j = i + 1; j < n; j++) {
            if (used[j]) continue;
            for (int k = j + 1; k < n; k++) {
                if (used[k]) continue;
                if (!isCollinear(points[i], points[j], points[k])) {
                    used[i] = used[j] = used[k] = true;
                    maxTriples++;
                    break;
                }
            }
            if (used[i]) break;
        }
    }

    std::cout << maxTriples << '\n';
}

void func7(){}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    func7();
}