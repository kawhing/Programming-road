#include <iostream>
using namespace std;

// 抽象不同零件类
// 抽象CPU类
class CPU{
    public:
        // 抽象的计算函数
        virtual void calculator() = 0;
};
// 抽象显卡类
class VideoCard{    
    public:
        // 抽象的显示函数
        virtual void display() = 0;
};
// 抽象内存条类
class Memory{
    public:
        // 抽象的存储函数
        virtual void storage() = 0;
};
// 电脑类
class Computer{
    public:
        Computer(CPU *cpu, VideoCard *vc, Memory *mem){
            this->cpu = cpu;
            this->vc = vc;
            this->mem = mem;
        }
        // 提供工作的函数
        void work(){
            cpu->calculator();
            vc->display();
            mem->storage();
        }
        // 提供析构函数，释放三个零件
        ~Computer(){
            if (cpu != NULL){
                delete cpu;
                cpu = NULL;
            }
            if (vc != NULL){
                delete vc;
                vc = NULL;
            }
            if (mem != NULL){
                delete mem;
                mem = NULL;
            }
        }

    private:
        CPU *cpu;
        VideoCard *vc;
        Memory *mem;

};

class InterCPU : public CPU{
    virtual void calculator(){
        cout << "Inter CPU 计算中" << endl; 
    }
};

class InterVideoCard : public VideoCard{
    virtual void display(){
        cout << "Inter VideoCard 显示中" << endl;
    }
};

class InterMemory : public Memory{
    virtual void storage(){
        cout << "Inter Memory 存储中" << endl;
    }
};

void test(){
    CPU *cpu = new InterCPU;
    VideoCard *vc = new InterVideoCard;
    Memory *mem = new InterMemory;
    Computer *computer = new Computer(cpu, vc, mem);
    computer->work();
    delete computer;
}

int main(){
    test();
    return 0;
}