#include <iostream>
using namespace std;

typedef struct Stack{
    int* top;
    int* base;
    int data[100];
    //int stackSize;
}Stack;

void initStack(Stack* stack){
    stack->base = stack->data;
    stack->top = stack->data;
}

void push(Stack* stack, int x){
    if(stack->top - stack->base >= 100){
        cout << "栈满" << endl;
        return;
    }
    *(stack->top) = x;
    stack->top++;
    cout << "入栈 : " << x << endl;
}

void pop(Stack* stack){
    if(stack->top == stack->base){
        cout << "栈空" << endl;
        return;
    }
    stack->top--;
    cout << "出栈 : " << *(stack->top) << endl;
}
void get_top(Stack* stack){
    cout << "栈顶元素 : " << *(stack->top-1) << endl;
}
void get_length(Stack* stack){
    cout << "栈长度 : " << stack->top - stack->base << endl;
}
bool isEmpty(Stack* stack){
    return stack->top == stack->base;
}

void clearStack(Stack* stack){
    stack->top = stack->base;
}
void destroyStack(Stack* stack){
    stack->top = stack->base = NULL;
}
int main(){
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 100);
    pop(&stack);
    get_top(&stack);
    get_length(&stack);
    cout << "栈是否为空 : " << isEmpty(&stack) << endl;
    return 0;
}