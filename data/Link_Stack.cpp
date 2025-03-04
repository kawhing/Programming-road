#include <iostream>
using namespace std;

typedef struct Stack{
    int data;
    struct Stack* next;
}Stack;

void initStack(Stack** stack){
    *(stack) = new Stack;
    (*stack)->next = NULL;

}

void PushStackNode(Stack* stack, int x) {
    Stack* newNode = new Stack;
    newNode->data = x;
    newNode->next = stack->next;
    stack->next = newNode;
    cout << "入栈 : " << x << endl;
}

void popStackNode(Stack* stack){
    if(stack->next == NULL){
        cout << "栈空!" << endl;
        return;
    }
    Stack* temp = stack->next;
    cout << "出栈 : " << temp->data << endl;
    stack->next = temp->next;
    //free(temp);
    delete temp;
}

void get_Top(Stack* satck){
    if(satck->next == NULL){
        cout << "栈空!" << endl;
        return;
    }
    cout << "栈顶元素 : " << satck->next->data << endl;
}
void get_length(Stack* satck){
    if(satck->next == NULL){
        cout << "栈空!" << endl;
        return;
    }
    int StackLength = 0;
    Stack* current = new Stack;
    current = satck;
    while(current->next != NULL){
        ++StackLength;
        current = current->next;
    }
    cout << "栈的长度 : " << StackLength << endl;
}

int main(){
    Stack* stack;
    initStack(&stack);
    PushStackNode(stack, 10);
    PushStackNode(stack, 20);
    PushStackNode(stack, 30);
    popStackNode(stack);
    get_Top(stack);
    get_length(stack);
    return 0;
}