/*
1/ Chuyển danh sách cạnh sang ma trận kề
Input:
n, m (số đỉnh, số cạnh)
5 9
Danh sách cạnh: 
1 2 
1 3 
1 4 
2 3 
2 4 
2 5 
3 4 
3 5 
4 5
Output: 
0 1 1 1 0
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
0 1 1 1 0
*/
// #include <iostream>
// using namespace std;
// int main() {
//   int n, m, a[1001][1001];
//   cin >> n >> m;
//   for (int i = 0; i < m; i++) {
//     int x, y;
//     cin >> x >> y;
//     a[x][y] = a[y][x] = 1;
//   }
//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j<= n; j++) {
//       cout << a[i][j] << " ";
//     }
//     cout << endl;
//   }
//   return 0;
// }

/*
2/ Chuyển danh sách cạnh sang danh sách kề
Input:
n, m (số đỉnh, số cạnh)
5 9
Danh sách cạnh: 
1 2 
1 3 
1 4 
2 3 
2 4 
2 5 
3 4 
3 5 
4 5
Output: 
1 : 2 3 4
2 : 1 3 4 5
3 : 1 2 4 5
4 : 1 2 3 5
5 : 2 3 4
*/
// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//   int n, m;
//   cin >> n >> m;
//   vector <int> v[1001];
//   for (int i = 0; i < m; i++) {
//     int x, y;
//     cin >> x >> y;
//     v[x].push_back(y);
//     v[y].push_back(x);
//   }
//   for (int i = 1; i <= n; i++) {
//     cout << i << " : ";
//     for (int x: v[i]) {
//       cout << x << " ";
//     }
//     cout << endl;
//   }
//   return 0;
// }

/*
3/ Chuyển ma trận kề sang danh sách cạnh
Input:
n (số đỉnh)
5
Ma trận: 
0 1 1 1 0 
1 0 1 1 1 
1 1 0 1 1
1 1 1 0 1
0 1 1 1 0
Output: 
1 2
1 3
1 4
2 3
2 4
2 5
3 4
3 5
4 5
*/
// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//   int n;
//   cin >> n;
//   int a[1001][1001];
//   vector<pair<int, int>> v;
//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= n; j++) {
//       cin >> a[i][j];
//     }
//   }
//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= n; j++) {
//       if (a[i][j] == 1 && i < j) {
//         v.push_back({i, j});
//       }
//     }
//   }
//   for (auto it: v) {
//     cout << it.first << " " << it.second << endl;
//   }
//   return 0;
// }

/*
4/ Chuyển ma trận kề sang danh sách kề
Input:
n (số đỉnh)
5
Ma trận: 
0 1 1 1 0 
1 0 1 1 1 
1 1 0 1 1
1 1 1 0 1
0 1 1 1 0
Output: 
1 : 2 3 4
2 : 1 3 4 5
3 : 1 2 4 5
4 : 1 2 3 5
5 : 2 3 4
*/
// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//   int n;
//   cin >> n;
//   int a[1001][1001];
//   vector<int> v[1001];
//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= n; j++) {
//       cin >> a[i][j];
//     }
//   }
//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= n; j++) {
//       if (a[i][j] == 1) {
//         v[i].push_back(j);
//       }
//     }
//   }
//   for (int i = 1; i <= n; i++) {
//     cout << i << " : ";
//     for (int x: v[i]) {
//       cout << x << " ";
//     }
//     cout << endl;
//   }
//   return 0;
// }

/*
5/ Chuyển danh sách kề sang ma trận kề
Input:
n (số đỉnh)
5
Danh sách kề: 
2 3 4
1 3 4 5 
1 2 4 5
1 2 3 5
2 3 4
Output: 
0 1 1 1 0 
1 0 1 1 1 
1 1 0 1 1
1 1 1 0 1
0 1 1 1 0
*/
// #include <iostream>
// #include <sstream>
// using namespace std;
// int main() {
//   int n;
//   cin >> n;
//   cin.ignore();
//   int a[1001][1001];
//   for (int i = 1; i <= n; i++) {
//     string s, num;
//     getline(cin, s);
//     stringstream ss(s);
//     while (ss >> num) {
//       a[i][stoi(num)] = 1;
//     }
//   }
//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= n; j++) {
//       cout << a[i][j] << " ";
//     }
//     cout << endl;
//   }
//   return 0;
// }

/*
6/ Chuyển danh sách kề sang danh sách cạnh
Input:
n (số đỉnh)
5
Danh sách kề: 
2 3 4
1 3 4 5 
1 2 4 5
1 2 3 5
2 3 4
Output: 
1 2
1 3
1 4
2 3
2 4
2 5
3 4
3 5
4 5
*/
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  cin.ignore();
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    string s, num;
    getline(cin, s);
    stringstream ss(s);
    while (ss >> num) {
      if (stoi(num) > i) {
        v.push_back({i, stoi(num)});
      }
    }
  }
  for (auto it : v) {
    cout << it.first << " " << it.second << endl;
  }
  return 0;
}