#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define Data int
#define SIZE 100

typedef struct{
    Data data[SIZE];
    int length;
}List;

List initList(){
    List list;
    list.length = 0;
    return list;
}

void insertNode(List *list, int index, int element){
    if(list->length >= SIZE){
        printf("ERROR: 静态顺序表已满!\n");
        return;
    }else if(index > list->length || index < 0){
        printf("ERROR: 插入位置不合法!\n");
        return;
    }
    for(int i = list->length; i > index; --i){
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = element;
    ++list->length;
    printf("INFO: 在静态顺序表位置 [%d] 插入 [%d] 成功!\n", index, element);
}

void searchNodeIndex(List list, int index){
    if(index > list.length || index < 0){
        printf("ERROR: 插入位置不合法!\n");
        return;
    }
    printf("INFO: 静态顺序表 位置 [%d] 的元素为 [%d]!\n", index, list.data[index]);
}

void searchNodeElement(List list, int element){
    bool flag = false;
    for(int i = 0; i < list.length; ++i){
        if(!flag && list.data[i] == element){
            flag = true;
            printf("INFO: 在静态顺序表以下位置找到 [%d]: %d", element, i);
        }else if(flag && list.data[i] == element){
            printf(" [%d]", i);
        }
        if(!flag){
            printf("WARNING: 未在静态顺序表中找到 [%d]!", element);
        }
        printf("!\n");
    }
}

void deleteNodeElement(List *list, int element){
    int cnt = 0;
    for(int i = 0; i < list->length; ++i){
        if(cnt == 0 && list->data[i] == element){
            printf("WARNING: 在静态顺序表以下位置删除 [%d]: [%d]", element, i + cnt);
            ++cnt;
            for(int j = i; j < list->length - 1; ++j){
                list->data[j] = list->data[j + 1];
            }
            --list->length;
            --i;
        }else if(cnt > 0 && list->data[i] == element){
            if(i < list->length - 1){
                for(int j = i; j < list->length - 1; ++j){
                    list->data[j] = list->data[j + 1];
                }
            }
            printf(" [%d]", i + cnt);
            ++cnt;
            --i;
            --list->length;
        }
    }
    printf("!\n");
}

void deleteNodeIndex(List *list, int index){
    if(list->length <= 0){
        printf("ERROR: 删除失败, 静态顺序表为空!\n");
    }else if(index > list->length || index < 0){
        printf("ERROR: 删除位置不合法!\n");
        return;
    }
    int element = list->data[index];
    for(int i = index; i < list->length; ++i){
        list->data[i] = list->data[i + 1];
    }
    printf("WARNING: 在静态顺序表位置 [%d] 删除 [%d]!\n", index, element);
    --list->length;
}

void printList(List list){
    printf("INFO: 静态顺序表: ");
    for(int i = 0; i < list.length; ++i){
        printf("%d ", list.data[i]);
    }
    printf("\n");
}

void printLength(List list){
    printf("INFO: 顺序表长度为%d\n", list.length);
}
int main(){
    List list = initList();

    insertNode(&list, 0, 1);
    printList(list);

    insertNode(&list, 0, 1);
    printList(list);

    insertNode(&list, 0, 3);
    printList(list);

    insertNode(&list, 0, 4);
    printList(list);

    printLength(list);

    deleteNodeElement(&list, 1);
    printList(list);

    deleteNodeIndex(&list, 1);
    printList(list);

    return 0;
}