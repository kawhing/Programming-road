#include <iostream>
#include <string>
using namespace std;

class Building;
class GoodGay{
    public:
        GoodGay();
        void visit();
        void visit2();
        Building *building;
};

class Building{
    friend void GoodGay::visit();
    public:
        Building();
    public:
        string m_SittingRoom;
    private:
        string m_BedRoom;
};

Building::Building(){
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodGay::GoodGay(){
    building = new Building;
}


void GoodGay::visit(){
    cout << "好基友正在访问：" << building->m_SittingRoom << endl;
    cout << "好基友正在访问：" << building->m_BedRoom << endl;
}

void GoodGay::visit2(){
    cout << "好基友正在访问：" << building->m_SittingRoom << endl;
    //cout << "好基友正在访问：" << building->m_BedRoom << endl;
}

void test01(){
    GoodGay gg;
    gg.visit();
}
int main(){
    test01();
    return 0;
}