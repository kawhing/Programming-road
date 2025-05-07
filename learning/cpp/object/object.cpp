#include <iostream>
#include <string>
#include <vector>
using namespace std;

class object{
    public:
        object(){
            cout << "object的构造函数" << endl;
        }
        ~object(){
            cout << "object的析构函数" << endl;
        }
};

int main(){
    object temp;
    

    return 0;
}