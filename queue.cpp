#include <iostream>
using namespace std;

const int MAX = 100; // Kích thước tối đa của queue
int row[MAX];// Mảng lưu trữ
int front = 0; // Chỉ số đầu queue
int rear = -1; // Chỉ số cuối queue
int elements = 0; // Số phần tử hiện có

// Kiểm tra queue rỗng
bool isEmpty() {
  return elements == 0;
}

// Kiểm tra queue đầy
bool isFull() {
  return elements == MAX;
}

// Thêm phần tử vào cuối queue
void enqueue(int value) {
  if (isFull()) {
    cout << "Queue overflow!" << endl;
    return;
  }
  rear = (rear + 1) % MAX; // Vòng quanh mảng
  row[rear] = value;
  elements++; // tăng số lượng phần tử trong queue
}

// Lấy và xóa phần tử đầu queue
int dequeue() {
  if (isEmpty()) {
    cout << "Queue underflow!" << endl;
    return -1;
  }
  int value = row[front];
  front = (front + 1) % MAX; // Vòng quanh mảng
  elements--; // giảm số lượng phần tử
  return value;
}

// Xem phần tử đầu queue không xóa
int getFront() {
  if (isEmpty()) {
    cout << "Queue is empty!" << endl;
    return -1;
  }
  return row[front];
}

// In queue từ front đến rear
void print() {
  cout << "Queue (front to rear): ";
  int current = front;
  for (int i = 0; i < elements; i++) {
    cout << row[current] << " ";
    current = (current + 1) % MAX;
  }
  cout << endl;
}

int main() {
  cout << "Queue Full: " << boolalpha << isFull() << endl;
  cout << "Queue Empty: " << boolalpha << isEmpty() << endl;
  enqueue(12);
  enqueue(55);
  enqueue(73);
  print();
  cout << "Queue Front: " << getFront() << endl;
  cout << "Queue Front And Remove Front: " << dequeue() << endl;
  print();

  return 0;
}
