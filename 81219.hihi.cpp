#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, w1, w2, h1, h2;
    if (!(cin >> n >> w1 >> w2 >> h1 >> h2)) return 0;
    
    long long A1 = w1 * w1;
    long long A2 = w2 * w2;
    long long V1_max = A1 * h1;
    long long V2_max = A2 * h2;
    long long total_V_max = V1_max + V2_max;
    
    long long current_v = 0;
    int current_h = 0;
    int max_dh = 0;
    
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        int prev_h = current_h;
        
        current_v += v;
        if (current_v > total_V_max) current_v = total_V_max; // 處理滿溢 [1]
        
        // 計算新高度
        if (current_v <= V1_max) {
            current_h = current_v / A1;
        } else {
            current_h = h1 + (current_v - V1_max) / A2;
        }
        
        max_dh = max(max_dh, current_h - prev_h);
    }
    
    cout << max_dh << endl;
    return 0;
}