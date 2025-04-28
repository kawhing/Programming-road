#include <stdio.h>
typedef struct{
    int* data;
    int size;
}List;
int initList(List* list){
    list->size = 0;
    return 1;
}
void printList(List* list){
    for(int i = 0; i < list->size; ++i){
        printf("%d ", list->data[i]);
    }
    printf("\n");
}
int insertList(List* list, int element, int index){
    if(index < 0 || index > list->size){
        printf("插入位置不合法!\n");
        return 0;
    }
    for(int i = list->size; i > index; --i){
        list->data[i] = list->data[i-1];
    }
    list->data[index] = element;
    ++list->size;
}


void deleteList(List* list, int index){
    for(int i = index; i < list->size; ++i){
        list->data[i] = list->data[i+1];
    }
    --list->size;
}
void changeList(List* list, int index, int element){
    list->data[index] = element;
}

int main(){
    List list;
    if(initList(&list)){
        insertList(&list, 2024, 0);
        printList(&list);
        insertList(&list, 2025, 1);
        printList(&list);
        deleteList(&list, 0);
        printList(&list);
        insertList(&list, 2027, 0);
        printList(&list);
    }
    return 0;
}