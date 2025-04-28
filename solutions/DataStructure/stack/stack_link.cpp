#include <iostream>
using namespace std;

typedef struct Stack{
    int data;
    struct Stack* next;
}Stack;

void initStack(Stack** stack){
    *stack = new Stack;
    (*stack)->next = nullptr;
}
void pushStack(Stack*& stack, int x){
    Stack* newNode = new Stack;
    newNode->data = x;
    newNode->next = stack;
    stack = newNode;
    cout << "入栈 : " << x << endl;
}

void popStack(Stack*& stack){
    if (stack->next == nullptr) {
        cout << "栈空!" << endl;
        return;
    }
    
    Stack* temp = stack;  
    cout << "出栈 : " << temp->data << endl;
    stack = temp->next;
    delete temp;
}

void get_top(Stack* stack){
    if(stack->next == nullptr){
        cout << "栈空!" << endl;
        return;
    }
    cout << "栈顶元素 : " << stack->data << endl;
}

void getLength(Stack* stack){
    int length = 0;
    Stack* current = stack;
    while(current->next != nullptr){
        ++length;
        current = current->next;
    }
    cout << "栈的长度 : " << length << endl;
}
int main(){
    Stack* stack;
    initStack(&stack);
    pushStack(stack, 10);
    pushStack(stack, 20);
    pushStack(stack, 30);
    popStack(stack);
    get_top(stack);
    getLength(stack);
    return 0;
}