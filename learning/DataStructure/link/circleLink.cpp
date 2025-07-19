#include <iostream>
using namespace std;

typedef struct List{
    int data;
    struct List* next;
} List;

void InitList(List &head){
    head.data = 0;
    head.next = &head;
}
void InsertNode1(List &head, int val){// 头插法
    List *p = new List;
    p->data = val;
    p->next = head.next;
    head.next = p;
    head.data++;
}
void InsertAt(List &head, int pos, int val){
    if(pos < 1 || pos > head.data + 1){
        cout << "插入位置非法" << endl;
        return;
    }
    List *current = &head;
    for(int i = 0; i < pos - 1; ++i)
        current = current->next;
    List *newNode = new List;
    newNode->data = val;
    newNode->next = current->next;
    current->next = newNode;
    head.data++;
}
void DeleteNode(List &head, int pos){
    if(pos < 1 || pos > head.data){
        cout << "删除位置非法" << endl;
        return;
    }
    List *current = &head;
    for(int i = 0; i < pos - 1; ++i)
        current = current->next;
    List *DeleteNode = current->next;
    current->next = DeleteNode->next;
    delete DeleteNode;
    head.data--;
}
void PrintList(List &head){
    if(head.next == &head){
        cout << "链表为空" << endl;
        return;
    }
    List *current = head.next;
    do {
        cout << current->data << " ";
        current = current->next;
    } while(current != &head);
    cout << endl;
}
int FindNode(List &head, int val){
    if(head.next == &head){
        cout << "链表为空" << endl;
        return -1;
    }
    List *current = head.next;
    int pos = 1;
    while(current != &head){
        
        if(current->data == val){
            return pos;
        }
        current = current->next;
        ++pos;
    }
    return -1;
}
int main(){
    List head;
    InitList(head);
    InsertNode1(head, 3);
    PrintList(head);
    InsertNode1(head, 2);
    PrintList(head);
    InsertNode1(head, 1);
    PrintList(head);
    InsertAt(head, 3, 4);
    PrintList(head);
    DeleteNode(head, 3);
    PrintList(head);
    cout << "2在位置" << FindNode(head, 2) << endl;
    return 0;
}