#include <iostream>
using namespace std;

// Java页面
class Java{
    public:
        void header(){
            cout << "首页、公开课、登录、注册...(公共头部)" << endl;
        }
        void footer(){
            cout << "帮助中心、交流合作、站内地图...(公共)" << endl;
        }
        void left(){
            cout << "Java、Python、C++...(公共分类列表)" << endl;
        }
        void content(){
            cout << "Java学科视频" << endl;
        }
};
// Python页面
class Python{
    public:
        void header(){
            cout << "首页、公开课、登录、注册...(公共头部)" << endl;
        }
        void footer(){
            cout << "帮助中心、交流合作、站内地图...(公共)" << endl;
        }
        void left(){
            cout << "Java、Python、C++...(公共分类列表)" << endl;
        }
        void content(){
            cout << "Python学科视频" << endl;
        }
};

// C++页面
class Cpp{
    public:
        void header(){
            cout << "首页、公开课、登录、注册...(公共头部)" << endl;
        }
        void footer(){
            cout << "帮助中心、交流合作、站内地图...(公共)" << endl;
        }
        void left(){
            cout << "Java、Python、C++...(公共分类列表)" << endl;
        }
        void content(){
            cout << "Cpp学科视频" << endl;
        }
};

void test01(){
    Java ja;
    cout << "Java下载视频页面如下 :" << endl;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "----------------------" << endl;
    Python py;
    cout << "Python下载视频页面如下 :" << endl;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "----------------------" << endl;
    Cpp cp;
    cout << "Cpp下载视频页面如下 :" << endl;
    cp.header();
    cp.footer();
    cp.left();
    cp.content();
    
}
int main(){
    test01();
    return 0;
}