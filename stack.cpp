#include <iostream>
using namespace std;

const int MAX = 100; // Kích thước tối đa của stack
int bin[MAX]; // Mảng lưu trữ
int top = -1; // Chỉ số đỉnh stack, ban đầu stack rỗng, chỉ số đỉnh = -1

// Kiểm tra stack rỗng
bool isEmpty() {
  return top == -1;
}

// Kiểm tra stack đầy
bool isFull() {
  return top == MAX - 1;
}

// Thêm phần tử vào đỉnh stack
void push(int value) {
  if (isFull()) {
    cout << "Stack overflow!" << endl;
    return;
  }
  bin[++top] = value; // Tăng top lên 1 trước khi sử dụng giá trị
}

// Lấy và xóa phần tử từ đỉnh stack
int pop() {
  if (isEmpty()) {
    cout << "Stack underflow!" << endl;
    return -1;
  }
  return bin[top--]; // Giảm top đi 1 sau khi sử dụng giá trị
}

// Xem phần tử đỉnh stack không xóa
int peek() {
  if (isEmpty()) {
    cout << "Stack is empty!" << endl;
    return -1;
  }
  return bin[top];
}

// In stack từ đỉnh xuống đáy
void print() {
  for (int i = top; i >= 0; i--) {
    cout << bin[i] << " ";
  }
  cout << endl;
}

int main() {
  cout << "Stack Full: " << boolalpha << isFull() << endl;
  cout << "Stack Empty: " << boolalpha << isEmpty() << endl;
  push(33);
  push(45);
  push(7);
  print();
  cout << "Stack Peek: " << peek() << endl;
  print();
  cout << "Stack Peek And Remove Peek: " << pop() << endl;
  print();
  cout << "Stack Peek And Remove Peek: " << pop() << endl;
  cout << "Stack Peek And Remove Peek: " << pop() << endl;
  cout << "Stack Empty: " << boolalpha << isEmpty() << endl;

  return 0;
}
