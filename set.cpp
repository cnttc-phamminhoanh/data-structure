#include <iostream>
using namespace std;

const int tableSize = 17;

struct Node {
  string key;
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

Node* makeNode(const string &key) {
  Node* newNode = new Node();
  newNode->key = key;
  newNode->next = NULL;
  return newNode;
}

void insert(const string &key) {
  int index = hashFunction(key);
  // Kiểm tra xem key đã tồn tại chưa
  Node* tmp = table[index];
  while (tmp != NULL) {
    if (tmp->key == key) {
      return; // Đã tồn tại, không thêm nữa
    }
    tmp = tmp->next;
  }
  // Thêm vào đầu bucket
  Node* newNode = makeNode(key);
  newNode->next = table[index];
  table[index] = newNode;
}

// Kiểm tra phần tử có trong Set không
bool contains(const string &key) {
  int index = hashFunction(key);
  Node* tmp = table[index];
  while (tmp != NULL) {
    if (tmp->key == key) {
      return true;
    }
    tmp = tmp->next;
  }
  return false;
}

void removeKey(const string &key) {
  int index = hashFunction(key);
  Node* tmp = table[index];
  Node* prev = NULL;
  while (tmp != NULL) {
    if (tmp->key == key) {
      if (prev == NULL) {
        // Xóa phần tử đầu danh sách
        table[index] = tmp->next;
      }
      else {
        // Xóa phần tử giữa hoặc cuối danh sách
        prev->next = tmp->next;
      }
      delete tmp;
      return;
    }
    prev = tmp;
    tmp = tmp->next;
  }
}

void printSet() {
  cout << "Set contents: { ";
  for (int i = 0; i < tableSize; i++) {
    Node* tmp = table[i];
    while (tmp != NULL) {
      cout << tmp->key << " ";
      tmp = tmp->next;
    }
  }
  cout << "}" << endl;
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
  insert("apple"); // Vào bucket 8
  insert("banana"); // Vào bucket 5
  insert("orange"); // Vào bucket 8
  insert("chile"); // Vào bucket 0
  insert("apple"); // Phần tử trùng sẽ không được thêm
  printSet();
  cout << "Contains 'banana': " << (contains("banana") ? "true" : "false") << endl;
  cout << "Contains 'grape': " << (contains("grape") ? "true" : "false") << endl;
  removeKey("banana");
  printSet();
  cleanup();
  return 0;
}
