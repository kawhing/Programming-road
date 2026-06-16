#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define DATA int

typedef struct{
    DATA *data;
    int length;
    int capacity;
}List;

List initList(){
    List list;
    list.length = 0;
    list.capacity = 4;
    list.data = (DATA*)malloc(sizeof(DATA) * list.capacity);
    return list;
}

void insertNode(List *list, int index, int element){
    if(index > list->length || index < 0){
        printf("ERROR: 插入位置不合法!\n");
        return;
    }
    if(list->length == list->capacity){
        list->capacity *= 2;
        DATA *temp = list->data;
        list->data = (DATA*)malloc(sizeof(DATA) * list->capacity);
        for(int i = 0; i < list->length; ++i){
            list->data[i] = temp[i];
        }
    }
    if(index != list->length){
        for(int i = list->length; i > index; --i){
            list->data[i] = list->data[i - 1];
        }
    }
    list->data[index] = element;
    ++list->length;
    printf("INFO: 在动态顺序表位置 [%d] 插入 [%d]!\n", index, element);
}

void deleteNodeIndex(List *list, int index){
    if(index > list->length || index < 0){
        printf("ERROR: 要删除的元素下标不合法!\n");
        return;
    }
    int element = list->data[index];
    if(index != list->length - 1){
        for(int i = index; i < list->length - 1; ++i){
            list->data[i] = list->data[i + 1];
        }
    }
    --list->length;
    printf("ERROR: 成功动态顺序表在位置 [%d] 删除 [%d]\n", index, element);
}

void deleteNodeElemet(List *list, int element){
    int cnt = 0;
    for(int i = 0; i < list->length; ++i){
        if(i != list->length - 1 && list->data[i] == element){
            for(int j = i; j < list->length - 1; ++j){
                list->data[j] = list->data[j + 1];
            }
            if(cnt == 0){
                printf("WARNING: 在动态顺序表的以下下标删除了元素 [%d]:", element);
            }
                printf(" [%d]", i + cnt);
            ++cnt;
            --list->length;
            --i;
        }else if(i == list->length - 1 && list->data[i] == element){
            printf(" [%d]", i + cnt);
            ++cnt;
            --list->length;
        }
    }
    printf("\n");
}

void printLength(List list){
    printf("INFO: 动态顺序表的长度为 [%d]\n", list.length);
}

void printList(List list){
    printf("INFO: 动态顺序表:");
    for(int i = 0; i < list.length; ++i){
        printf(" %d", list.data[i]);
    }
    printf("\n");
}

int main(){
    List list = initList();

    insertNode(&list, 0, 1);
    printList(list);
    
    insertNode(&list, 0, 1);
    printList(list);

    insertNode(&list, 0, 2);
    printList(list);

    insertNode(&list, 0, 3);
    printList(list);

    deleteNodeElemet(&list, 1);
    printList(list);

    deleteNodeIndex(&list, 0);
    printList(list);

    printLength(list);

    return 0;
}