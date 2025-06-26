#include <iostream>
using namespace std;

// Tìm kiếm phần tử bằng thuật toán nhị phân, nếu có trả về true, không tìm thấy trả về false
bool binarySearch(int a[], int n, int target) {
  int l = 0, r = n - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (target == a[mid]) {
      return true;
    }
    else if (target > a[mid]) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  return false;
}

// Tìm vị trí đầu tiên của phần tử trong mảng đã sắp xếp, không tìm thấy trả về - 1
int firstPositionSearch(int a[], int n, int target) {
  int l = 0, r = n - 1, res = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (target == a[mid]) {
      res = mid;
      r = mid - 1;
    }
    else if (target > a[mid]) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  return res;
}

// 3. Tìm vị trí cuối cùng của phần tử trong mảng đã sắp xếp, không tìm thấy trả về - 1
int lastPositionSearch(int a[], int n, int target) {
  int l = 0, r = n - 1, res = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] == target) {
      res = mid;
      l = mid + 1;
    }
    else if (target > a[mid]) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  return res;
}

// In số lần xuất hiện của phần tử trong mảng đã sắp xếp, không có thì in ra 0
int frequencyOfAppearance(int a[], int n, int target) {
  int l = firstPositionSearch(a, n, target);
  int r = lastPositionSearch(a, n, target);
  if (l != -1) {
    return r - l + 1;
  }
  return 0;
}

// Tìm vị trí đầu tiên của một phần tử > x trong mảng đã sắp xếp
int firstPositionBiggerX(int a[], int n, int x) {
  int l = 0, r = n - 1, res = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] > x) {
      res = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  return res;
}

// Tìm vị trí đầu tiên của một phần tử < x trong mảng đã sắp xếp
int firstPositionSmallerX(int a[], int n, int x) {
  int l = 0, r = n - 1, res = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] < x) {
      res = mid;
      r = mid - 1;
    }
    else {
      r = mid - 1;
    }
  }
  return res;
}

// Tìm vị trí cuối cùng của một phần tử > x trong mảng đã sắp xếp
int lastPositionBiggerX(int a[], int n, int x) {
  int l = 0, r = n - 1, res = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] > x) {
      res = mid;
      l = mid + 1;
    }
    else {
      l = mid + 1;
    }
  }
  return res;
}

// Tìm vị trí cuối cùng của một phần tử < x trong mảng đã sắp xếp
int lastPositionSmallerX(int a[], int n, int x) {
  int l = 0, r = n - 1, res = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] < x) {
      res = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  return res;
}

int main() {
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  cout << boolalpha << binarySearch(a, 10, 3) << endl;

  int b[10] = {1, 1, 2, 2, 3, 3, 9, 10, 54, 59};
  cout << firstPositionSearch(b, 10, 3) << endl;

  int c[10] = {1, 2, 2, 4, 4, 4, 6, 7, 8, 9};
  cout << lastPositionSearch(c, 10, 4) << endl;

  int d[10] = {1, 2, 2, 3, 3, 3, 3, 3, 8, 9};
  cout << frequencyOfAppearance(d, 10, 3) << endl;

  int e[10] = {1, 2, 2, 3, 3, 3, 3, 4, 7, 9};
  cout << firstPositionBiggerX(e, 10, 2) << endl;

  int f[10] = {4, 5, 5, 6, 6, 6, 6, 7, 8, 9};
  cout << firstPositionSmallerX(f, 10, 6) << endl;

  int g[10] = {1, 1, 1, 3, 3, 3, 3, 3, 3, 11};
  cout << lastPositionBiggerX(g, 10, 2) << endl;

  int h[10] = {1, 2, 2, 3, 3, 3, 3, 4, 7, 11};
  cout << lastPositionSmallerX(h, 10, 4) << endl;

  return 0;
}
