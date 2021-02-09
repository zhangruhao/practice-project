#include<iostream>
#include<graphics.h>
using namespace std;
/*
* 飞机类的头文件，
*/
class Bullet
{
public:
	Bullet();//构造函数
	Bullet(int x, int y, const char* imgURL, int speed);//文件路径传递错误，在前面加上const
	void drawBullet();
	void moveBullet();
    int& getx();
	int& gety();
	int& getSpeed();
protected:
	int x = 250;
	int y = 250;
	int speed = 10;
	PIMAGE img;
};
