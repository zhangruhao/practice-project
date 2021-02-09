#include<iostream>
#include<graphics.h>
using namespace std;
class Plane
{
public:
	Plane();//构造函数
	Plane(int x, int y,const char *imgURL,int speed);//文件路径传递错误，在前面加上const，飞机创建
	void drawPlane();//画飞机
	void keyDown(char userKey);//键盘移动飞机
	void movePlane();//敌机飞机的移动，敌机和我方战机用的同一个类
	void delet();//删除敌机
	int& getx();//获得飞机x坐标
	int& gety();//获得飞机y坐标
	int& getSpeed();//获得飞机速度
protected:
	int x;
	int y;
	int speed;
	PIMAGE img;
};