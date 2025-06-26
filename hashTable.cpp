#include <iostream>
using namespace std;

const int tableSize = 17;

struct Node {
  string key;
  int value;
  Node* next;
};

Node* table[tableSize] = { NULL };

int hashFunction(const string &key) {
  unsigned int hash = 0;
  for (char c : key) {
    hash = hash * 31 + c;
  }
  return hash % tableSize;
}

Node* makeNode(const string &key, int value) {
  Node* newNode = new Node();
  newNode->key = key;
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void insert(const string &key, int value) {
  int index = hashFunction(key);
  Node* newNode = makeNode(key, value);
  // Nếu bucket trống
  if (table[index] == NULL) {
    table[index] = newNode;
    return;
  }
  // Kiểm tra xem key đã tồn tại chưa
  Node* tmp = table[index];
  while (tmp != NULL) {
    if (tmp->key == key) {
      tmp->value = value; // Cập nhật giá trị nếu key tồn tại
      delete newNode; // Giải phóng bộ nhớ vì không dùng đến
      return;
    }
    if (tmp->next == NULL) break;
    tmp = tmp->next;
  }
  tmp->next = newNode; // Thêm vào cuối danh sách
}

int get(const string &key) {
  int index = hashFunction(key);
  Node* tmp = table[index];
  while (tmp != NULL) {
    if (tmp->key == key) {
      return tmp->value;
    }
    tmp = tmp->next;
  }
  return -1; // Không tìm thấy
}

void removeKey(const string &key) {
  int index = hashFunction(key);
  Node* tmp = table[index];
  Node* prev = NULL;
  while (tmp != NULL) {
    if (tmp->key == key) {
      if (prev == NULL) {
        table[index] = tmp->next; // Xóa phần tử đầu danh sách
      }
      else {
        prev->next = tmp->next; // Xóa phần tử giữa hoặc cuối danh sách
      }
      delete tmp;
      return;
    }
    prev = tmp;
    tmp = tmp->next;
  }
}

void printTable() {
  for (int i = 0; i < tableSize; i++) {
    cout << "Bucket " << i << ": ";
    Node* tmp = table[i];
    while (tmp != NULL) {
      cout << "[" << tmp->key << ": " << tmp->value << "]";
      tmp = tmp->next;
    }
    cout << endl;
  }
  cout << "----------------------------------" << endl;
}

void cleanup() {
  for (int i = 0; i < tableSize; i++) {
    Node* current = table[i];
    while (current != NULL) {
      Node* tmp = current;
      current = current->next;
      delete tmp;
    }
    table[i] = NULL;
  }
}

int main() {
  // Thêm các phần tử
  insert("apple", 10);
  insert("orange", 30);
  insert("apricot", 96);
  insert("almond", 120);
  insert("berry", 51);
  insert("cherry", 80);
  insert("mango", 90);
  insert("watermelon", 60);
  insert("blueberry", 7754);
  insert("pear", 50);
  insert("avocado", 110);
  insert("lychee", 130);
  insert("banana", 666);
  insert("chile", 888);
  insert("potato", 1087);
  insert("lemon", 3333);
  printTable();

  // Xóa phần tử
  removeKey("mango");
  removeKey("apricot");
  printTable();

  // Lấy giá trị
  string key = "blueberry";
  cout << "Value of " << key << ": " << get(key) << endl;

  // Dọn dẹp bộ nhớ trước khi kết thúc
  cleanup();
  return 0;
}
