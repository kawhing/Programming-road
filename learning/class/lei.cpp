#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
/*
class Person{//类 
	public:
		void get_name(string get_name){
			person_name = get_name;
		}
		string return_name(){
			return person_name;
		}
		int set_age(){
			if(person_age >= 0 && person_age <= 150){ 
				return person_age;
			}else{
				return 0;
			}
		} 
	private:
		string  person_name;
		int person_age = 180;
};
*/
/*
class cube{//类
	public:
		int length, weigth, high, area, volume;
		void test(int x, int y, int z){
			length = x;
			weigth = y;
			high = z; 
		}
		int get_area(){
			area = length*weigth + length*high + weigth*high;
			area *= 2;
			return area;
		}

		int get_volume(){
			volume = high*weigth*length;
			return volume;
		}
		bool campare(cube &cube2){
			if(length == cube2.length && weigth == cube2.weigth && high == cube2.high)
				return true;
			else return false;
		}
		
};
bool campare(cube cube1, cube cube2){
	if(cube1.length == cube2.length && cube1.weigth == cube2.weigth && cube1.high == cube2.high)
		return true;
	else return false;
}
*/

/*
class Circle{
	public:
		float c_p[2];//圆心坐标 (x, y)
		float c_r;//圆的半径 r
		float p[2];//点的坐标 (x, y)
		float r;//点到圆心的距离 r
		void set_circle_p(float x, float y){
			c_p[0] = x;
			c_p[1] = y;
		}
		void set_circle_r(float r){
			c_r = r;
		}
		void set_p(float x, float y){
			p[0] = x;
			p[1] = y;
		}
		void set_p_r(){
			float x, y, r;
			cout << "请输入圆心的坐标(x, y) : " << endl;
			cin >> x >> y;
			set_circle_p(x, y);
			cout << "请输入圆的半径r : " << endl;
			cin >> r;
			set_circle_r(r);
			cout << "请输入点的坐标(x, y) : " << endl;
			cin >> x >> y;
			set_p(x, y);
		}
		int is_in_circle(){
			
			r = sqrt(pow(p[0]-c_p[0], 2) + pow(p[1]-c_p[1], 2));
			if(r < c_r) return 1;
			else if(r == c_r) return 2;
			else return 0;
		}
};
*/

class test{
	public:
	test(){
		cout << "调用构造函数" << endl;
	}
	~test(){
		cout << "调用析构函数" << endl;
	}


};
void test01(){
	test test0;
}
int main(){
	/*
	cube cube1;//用类创建一个对象 
	int x = 10, y = 10, z = 10;
	
	cube cube2;
	cube2.test(x, y, z+1);

	cube1.test(x, y, z);
	cout << "这个立方体的面积是 : " << cube1.get_area() << endl;
	cout << "这个立方体的体积是 : " << cube1.get_volume() << endl;
	bool result = cube1.campare(cube2);
	if(result == true) cout << "这两个立方体是相同的" << endl;
	else cout << "这两个立方体是不同的" << endl;
	*/
	/*Circle circle;
	circle.set_p_r();
	int test = circle.is_in_circle();
	if(test == 0) cout << "这个点在圆外" << endl;
	else if(test == 1) cout << "这个点在圆内" << endl;
	else cout << "这个点在圆上" << endl;
	*/
	//test01();
	test test4;
	return 0;
}