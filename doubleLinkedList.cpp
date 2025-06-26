#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* prev;
  Node* next;
};

Node* makeNode(int value) {
  Node* newNode = new Node();
  newNode->data = value;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

// Thêm node vào đầu danh sách O(1)
void insertHead(Node* &head, Node* &tail, int value) {
  Node* newNode = makeNode(value);
  if (head == NULL) {
    head = tail = newNode;
    return;
  }
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

// Thêm node vào cuối danh sách O(1)
void insertTail(Node* &head, Node* &tail, int value) {
  Node* newNode = makeNode(value);
  if (tail == NULL) {
    head = tail = newNode;
    return;
  }
  newNode->prev = tail;
  tail->next = newNode;
  tail = newNode;
}

// Duyệt danh sách từ đầu đến cuối O(n)
void traverseForward(Node* &head) {
  Node* tmp = head;
  cout << "LinkedList Forward: ";
  while (tmp != NULL) {
    cout << tmp->data << " ";
    tmp = tmp->next;
  }
  cout << endl;
}

// Duyệt từ cuối về đầu O(n)
void traverseBackward(Node* &tail) {
  Node* tmp = tail;
  cout << "LinkedList Backward: ";
  while (tmp != NULL) {
    cout << tmp->data << " ";
    tmp = tmp->prev;
  }
  cout << endl;
}

// Xóa node đầu danh sách O(1)
void deleteHead(Node* &head, Node* &tail) {
  // Danh sách rỗng
  if (head == NULL) return;
  Node* tmp = head;
  // Danh sách chỉ có 1 node
  if (head == tail) {
    head = tail = NULL;
    delete tmp;
    return;
  }
  head = head->next;
  head->prev = NULL;
  delete tmp;
}

// Xóa node cuối danh sách O(1)
void deleteTail(Node* &head, Node* &tail) {
  // Danh sách rỗng
  if (tail == NULL) return;
  Node* tmp = tail;
  // Danh sách chỉ có 1 node
  if (head == tail) {
    head = tail = NULL;
    delete tmp;
    return;
  }
  tail = tail->prev;
  tail->next = NULL;
  delete tmp;
}

// Lấy kích thước danh sách
int getSize(Node* &head)  {
  int count = 0;
  Node* tmp = head;
  while (tmp != NULL) {
    count++;
    tmp = tmp->next;
  }
  return count;
}

// Kiểm tra danh sách trống
bool isEmpty(Node* &head) {
  return head == NULL;
}

// Chèn theo vị trí (index) - O(n)
void insertAt(Node* &head, Node* &tail, int index, int value) {
  int size = getSize(head);
  if (index < 1 || index > size + 1) return;
  if (index == 1) {
    insertHead(head, tail, value);
    return;
  }
  if (index == size + 1) {
    insertTail(head, tail, value);
    return;
  }
  Node* tmp = head;
  for (int i = 1; i < index; i++) {
    tmp = tmp->next;
  }
  Node* prev = tmp->prev;
  Node* newNode = makeNode(value);
  newNode->next = tmp;
  tmp->prev = newNode;
  newNode->prev = prev;
  prev->next = newNode;
}

// Xóa theo vị trí (index) - O(n)
void deleteAt(Node* &head, Node* &tail, int index) {
  int size = getSize(head);
  if (index < 1 || index > size) return;
  if (index == 1) {
    deleteHead(head, tail);
    return;
  }
  if (index == size) {
    deleteTail(head, tail);
    return;
  }
  Node* tmp = head;
  for (int i = 1; i < index; i++) {
    tmp = tmp->next;
  }
  Node* prev = tmp->prev;
  Node* next = tmp->next;
  prev->next = next;
  next->prev = prev;
  delete tmp;
}

// Tìm kiếm giá trị - O(n)
int search(Node* &head, int value) {
  Node* tmp = head;
  int index = 1;
  while (tmp != NULL) {
    if (tmp->data == value) {
      return index;
    }
    tmp = tmp->next;
    index++;
  }
  return -1; // Không tìm thấy
}

// Xóa toàn bộ danh sách O(n)
void cleanup(Node* &head, Node* &tail) {
  while (head != NULL) {
    Node* tmp = head;
    head = head->next;
    delete tmp;
  }
  // Trả head và tail về trạng thái ban đầu lúc khởi tạo
  head = tail = NULL;
}

int main() {
  Node* head = NULL;
  Node* tail = NULL;

  // Thêm vào dầu
  insertHead(head, tail, 8);
  insertHead(head, tail, 41);
  insertHead(head, tail, 562);
  insertHead(head, tail, 77);
  // Duyệt danh sách đầu -> cuối
  traverseForward(head);

  // Thêm vào cuối
  insertTail(head, tail, 5678);
  insertTail(head, tail, 11);
  insertTail(head, tail, 1505);
  insertTail(head, tail, 2402);
  // Duyệt danh sách đầu -> cuối
  traverseForward(head);

  // Kích thước danh sách
  cout << "Size of LinkedList: " << getSize(head) << endl;

  // Kiển tra danh sách trống
  cout << "LinkedList Empty: " << boolalpha << isEmpty(head) << endl;

  // Duyệt danh sách cuối -> đầu
  traverseBackward(tail);

  // Xóa đầu
  deleteHead(head, tail);
  // Duyệt đầu -> cuối
  traverseForward(head);

  // Xóa cuối
  deleteTail(head, tail);
  // Duyệt đầu -> cuối
  traverseForward(head);

  // Chèn theo vị trí
  insertAt(head, tail, 4, 83);
  // Duyệt đầu -> cuối
  traverseForward(head);

  // Xóa theo vị trí
  deleteAt(head, tail, 5);
  // Duyệt đầu -> cuối
  traverseForward(head);

  // Tìm giá trị
  int value = 83;
  cout << "Index Of Value " << value << ": "  << search(head, value) << endl;

  // Dọn dẹp
  cleanup(head, tail);
  return 0;
}