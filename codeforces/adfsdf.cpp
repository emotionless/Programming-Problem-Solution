#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node *head;

void Remove(int d) {
    Node *t, *prev;
    if (!head) return;
    t = head;
    if (head->data == d) {
        head = head->next;
        delete t;
    }
    else {
        while (t != nullptr && t->data != d) {
            prev = t;
            t = t->next;
        }
        if (t) {
            prev->next = t->next;
            delete t;
        }
        else {
            cout << "value not found" << endl;
        }
    }
}


int main() {
    head = new Node(1);
    Node *prev = head;
    Node *save = head;
    for(int i = 2; i < 10; i++) {
        prev -> next = new Node(i);
        prev = prev->next;
    }


    Remove(5);

    while(head != NULL) {
        cout<<head->data<<endl;
        head = head -> next;
    }

    return 0;
}
