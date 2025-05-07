#include <iostream>
#include <vector>
using namespace std;

typedef int E;
struct ArrayList {
    int capacity;
    vector<E> array;
    int size;
};

void initArrayList(ArrayList &list) {
    list.capacity = 10;
    list.array.resize(list.capacity);
    list.size = 0;
}

void insertList(ArrayList &list, E element, int index) {

   for (int i = list.size; i > index; --i) {
      list.array[i] = list.array[i - 1];
   }
   list.array[index] = element; 
   ++list.size; 
}

void printList(ArrayList& list){
     for(int i = 0; i < list.size; ++i){
       cout << list.array[i] << " ";
     }
     cout<<endl;

}
int main() {
 ArrayList arr_list ;
 initArrayList(arr_list);
 insertList(arr_list, 111,0); 
 printList(arr_list); // printing the first inserted element
 insertList(arr_list,222,0);
 printList(arr_list); // printing the second inserted element
 insertList(arr_list,333,2); 
 printList(arr_list); // printing the third inserted element

 return 0;

}
