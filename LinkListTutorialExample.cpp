
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkList {
private:
    Node* head;
    Node* end;
public:
    LinkList(int data) {
        head = new Node(data);
        end = head;
    }
    void insert(int data) {
        Node* newNode = new Node(data);
        end->next = newNode;
        end = newNode;
    }
    void print() {
        Node* start = head;
        cout << "\n\t";
        while (start != NULL) {
            cout << start->data;
            if (start != end) {
                cout << "-->";
            }
            start = start->next;
        }
        cout << "\n\t";
    }

    void reverseList() {
        if (!head->next) {
            return;
        }
        end = head;
        Node* previous = NULL;
        Node* next = head->next;
        while (next) {
            head->next = previous;
            previous = head;
            head = next;
            next = head->next;
        }
        head->next = previous;
    }

    int size() {
        int size = 0;
        Node* start = head;
        while (start) {
            start = start->next;
            ++size;

        }
        return size;
    }

};

int main()
{
    LinkList myList(0);
    myList.insert(10);
    myList.insert(20);
    myList.insert(30);
    myList.print();
    myList.reverseList();
    myList.insert(-10);
    myList.insert(-20);
    myList.print();
    cout << "\nSize of list is : " << myList.size();

}

