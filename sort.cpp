#include <iostream>
using namespace std;

// In mảng
void printArr(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// Sắp xếp nổi bọt (bobble sort)
void bobbleSort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (a[j] > a[j+1]) {
        swap(a[j], a[j+1]);
      }
    }
  }
}

// Sắp xếp chọn (selection sort)
void selectionSort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      swap(a[i], a[minIndex]);
    }
  }
}

// Sắp xếp chèn (insertion sort)
void insertionSort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int j = i - 1, current = a[i];
    while (j >= 0 && a[j] > current) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = current;
  }
}

// Sắp xếp đếm phân phối (counting sort)
void countingSort(int a[], int n) {
  // Tìm giá trị lớn nhất trong mảng
  int maxValue = a[0];
  for (int i = 1; i < n; i++) {
    if (maxValue < a[i]) {
      maxValue = a[i];
    }
  }
  // Cấp phát động
  int* count = new int[maxValue+1](); // dấu () khởi tạo tất cả các phần tử  = 0
  int* output = new int[n]; // không khởi tạo giá trị
  // Đếm số lần xuất hiện của mỗi giá trị
  for (int i = 0; i < n; i++) {
    count[a[i]]++;
  }
  // Biến mảng tần suát xuất hiện thành mảng cộng dồn
  for (int i = 1; i <= maxValue; i++) {
    count[i] += count[i-1];
  }
  // Duyệt từ cuối để đảm bảo ổn định và tạo mảng kết quả
  for (int i = n - 1; i >= 0; i--) {
    output[count[a[i]] - 1] = a[i];
    count[a[i]]--;
  }
  // Sao chép vào mảng ban đầu
  for (int i = 0; i < n; i++) {
    a[i] = output[i];
  }
  // Giải phóng bộ nhớ
  delete[] count;
  delete[] output;
}

// Hàm trộn hai mảng con đã sắp xếp
void merge(int a[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  // Tạo mảng tạm
  int x[n1], y[n2];
  //Copy dữ liệu vào mảng tạm
  for (int i = 0; i < n1; i++) {
    x[i] = a[l + i];
  }
  for (int i = 0; i < n2; i++) {
    y[i] = a[m + 1 + i];
  }
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (x[i] < y[j]) {
      a[k] = x[i];
      i++;
    }
    else {
      a[k] = y[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    a[k] = x[i];
    i++;
    k++;
  }
  while (j < n2) {
    a[k] = y[j];
    j++;
    k++;
  }
}

// Sắp xếp trộn (merge sort)
void mergeSort(int a[], int l, int r) {
  if (l >= r) return; // Chia cho đến khi chỉ còn 1 phần từ (l >= r)
  int mid = l + (r - l) / 2;
  mergeSort(a, l, mid);
  mergeSort(a, mid + 1, r);
  merge(a, l, mid, r);
}

// Hàm phân hoạch
int partition(int a[], int l, int r) {
  int i = l - 1, j = r + 1, pivot = a[l];
  while (true) {
    // Tìm phần tử bên trái >= pivot
    do {
      i++;
    }
    while (a[i] < pivot);
    // Tìm phần tử bên phải <= pivot
    do {
      j--;
    }
    while (a[j] > pivot);
    // Nếu hai con trỏ gặp nhau
    if (i >= j) {
      return j;
    }
    // Đổi chỗ hai phần tử
    swap(a[i], a[j]);
  }
}

// Sắp xếp nhanh (quick sort)
void quickSort(int a[], int l, int r) {
  if (l >= r) return;
  int p = partition(a, l, r);
  quickSort(a, l, p);
  quickSort(a, p + 1, r);
}

// Hàm heapify để hiệu chỉnh cây con có gốc tại i thành max-heap
void heapify(int a[], int n, int i) {
  int l = 2 * i + 1, r = 2 * i + 2;
  int largest = i;
  // Nếu nút con trái lớn hơn gốc
  if (l < n && a[l] > a[largest]) {
    largest = l;
  }
  // Nếu nút con phải lớn hơn largest hiện tại
  if (r < n && a[r] > a[largest]) {
    largest = r;
  }
  // Nếu largest không phải là gốc
  if (largest != i) {
    swap(a[i], a[largest]);
    // Đệ quy heapify cây con
    heapify(a, n, largest);
  }
}

// Sắp xếp vun đống (heap sort)
void heapSort(int a[], int n) {
  // Xây dựng max-heap
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(a, n, i);
  }
  // Trích xuất từng phần tử từ heap
  for (int i = n - 1; i >= 0; i--) {
    // Di chuyển gốc hiện tại đến cuối
    swap(a[0], a[i]);
    // Gọi heapify trên heap đã giảm kích thước
    heapify(a, i, 0);
  }
}

int main() {
  const int n = 10;

  cout << "-------- Bobble Sort --------" << endl;
  int a[n] = { 4, 2, 5, 56, 123, 77, 5, 88, 324, 878 };
  printArr(a, n);
  bobbleSort(a, n);
  printArr(a, n);

  cout << "-------- Selection Sort --------" << endl;
  int b[n] = { 4, 2, 5, 56, 123, 77, 5, 88, 324, 878 };
  printArr(b, n);
  selectionSort(b, n);
  printArr(b, n);

  cout << "-------- Insertion Sort --------" << endl;
  int c[n] = { 4, 2, 5, 56, 123, 77, 5, 88, 324, 878 };
  printArr(c, n);
  insertionSort(c, n);
  printArr(c, n);

  cout << "-------- Couting Sort --------" << endl;
  int d[n] = { 4, 2, 7, 4, 4, 1, 6, 9, 7, 3 };
  printArr(d, n);
  countingSort(d, n);
  printArr(d, n);

  cout << "-------- Merge Sort --------" << endl;
  int e[n] = { 4, 2, 7, 4, 4, 1, 6, 9, 7, 3 };
  printArr(e, n);
  mergeSort(e, 0, n - 1);
  printArr(e, n);

  cout << "-------- Quick Sort --------" << endl;
  int f[n] = { 4, 2, 7, 4, 4, 1, 6, 9, 7, 3 };
  printArr(f, n);
  quickSort(f, 0, n - 1);
  printArr(f, n);

  cout << "-------- Heap Sort --------" << endl;
  int g[n] = { 4, 2, 7, 4, 4, 1, 6, 9, 7, 3 };
  printArr(g, n);
  heapSort(g, n);
  printArr(g, n);

  return 0;
}
