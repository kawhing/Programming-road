#include <iostream>
#include <string>
using namespace std;
class person{
    public:
        string name;
        string phone;
        person(string name, string phone) : name(name), phone(phone) {}

        
};
class phone{
    public:
        string name;

};
void test(){
    person p("张三", "红米K60");
    cout << p.name << " " << p.phone << endl;
}
int main(){
    test();
    return 0;

}