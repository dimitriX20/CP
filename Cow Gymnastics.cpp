#include <bits/stdc++.h>
using namespace std;


#define endl "\n" 

const int maxn = 20; 
set<pair<int, int> >ans; 
vector<vector<bool> >flag(maxn, vector<bool>(maxn, true)); 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ifstream fin("gymnastics.in");
	  ofstream fout("gymnastics.out");
    int n, k; 
    fin >> k >> n; 
    vector<vector<int> >v(k, vector<int>(n)); 
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n; j++) {
        fin >> v[i][j];
        v[i][j]--;  
        int idx = v[i][j];  
        for (int kill = j - 1; kill >= 0; kill--) {
          flag[idx][v[i][kill]] = 0;  
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (flag[i][j] && i != j) {
          pair<int,int>cur = make_pair(j, i); 
          ans.insert(cur); 
        }
      }
    }
    fout << ans.size();
    return 0;
}
