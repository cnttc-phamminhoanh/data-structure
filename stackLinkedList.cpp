#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* makeNode(int value) {
  Node* newNode = new Node();
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

bool isEmpty(Node* &head) {
  return head == NULL;
}

void push(Node* &head, int value) {
  Node* newNode = makeNode(value);
  if (isEmpty(head)) {
    head = newNode;
    return;
  }
  newNode->next = head;
  head = newNode;
}

int top(Node* &head) {
  if (isEmpty(head)) {
    cout << "Stack Empty!" << endl;
    return -1;
  }
  return head->data;
}

int pop(Node* &head) {
  if (isEmpty(head)) {
    cout << "Stack Empty!" << endl;
    return -1;
  }
  int removeValue = head->data;
  Node* tmp = head;
  head = head->next;
  delete tmp;
  return removeValue;
}

void print(Node* &head) {
  Node* tmp = head;
  while (tmp != NULL) {
    cout << tmp->data << " ";
    tmp = tmp->next;
  }
  cout << endl;
}

int count(Node* &head) {
  int count = 0;
  Node* tmp = head;
  while (tmp != NULL) {
    count++;
    tmp = tmp->next;
  }
  return count;
}

int main() {
  Node* head = NULL;
  push(head, 33);
  push(head, 45);
  push(head, 7);
  print(head);
  cout << "Stack count: " << count(head) << endl;
  cout << "Stack Top: " << top(head) << endl;
  print(head);
  cout << "Stack Peek And Remove Top: " << pop(head) << endl;
  print(head);
  cout << "Stack Peek And Remove Top: " << pop(head) << endl;
  print(head);
  cout << "Stack Peek And Remove Top: " << pop(head) << endl;
  print(head);
  cout << "Stack Empty: " << boolalpha << isEmpty(head) << endl;
  return 0;
}
