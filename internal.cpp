int data;
Node* prev;
Node* next;
Node(int value) {
data = value;
prev = nullptr;
next = nullptr;
}
};
class DoublyLinkedList {
private:
Node* head;
public:
DoublyLinkedList() {
head = nullptr;
}
void insert_at_beginning(int value) {
Node* new_node = new Node(value);
if (head != nullptr) {
head->prev = new_node;
new_node->next = head;
}
head = new_node;
}
void delete_at_end() {
if (head == nullptr) {
cout << "List is empty" << endl;
return;
}
Node* temp = head;
if (temp->next == nullptr) {
delete temp;
head = nullptr;
return;
}
while (temp->next != nullptr) {
temp = temp->next;
}
temp->prev->next = nullptr;
delete temp;
}
void display() {
if (head == nullptr) {
cout << "List is empty" << endl;
return;
}
Node* temp = head;
cout << "Doubly Linked List: ";
while (temp != nullptr) {
cout << temp->data << " <-> ";
temp = temp->next;
}
cout << "NULL" << endl;
}
};
int main() {
DoublyLinkedList dll;
dll.insert_at_beginning(10);
dll.insert_at_beginning(20);
dll.insert_at_beginning(30);
dll.display();
dll.delete_at_end();
dll.display();
return 0;
}
