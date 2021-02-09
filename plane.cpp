#include"plane.h"
Plane::Plane()
{

}//构造函数
Plane::Plane(int x, int y,const char *imgURL,int speed)//创建一个飞机
{
	this->x = x;
	this->y = y;
	img = newimage();
	getimage(img,imgURL);//飞机显示不出，出在文件路径传递上面，：不用带双引号。
	this->speed = speed;
}
void Plane::drawPlane()//画出飞机
{
	putimage_withalpha(NULL, img, x, y);
}
void Plane::keyDown(char userKey)//键盘移动飞机
{
	switch (userKey)
	{
	case 'W':
	case 'w':
	case 72:
		this->y -= this->speed;
		break;
	case 'S':
	case 's':
	case 80:
		this->y += this->speed;
		break;
	case 'A':
	case 'a':
	case 75:
		this->x -= this->speed;
		break;
	case 'D':
	case 'd':
	case 77:
		this->x += this->speed;//this指针调用函数
		break;
	}
}
int& Plane::getx()//获得飞机x坐标
{
	return x;
}
int& Plane::gety()//获得飞机y坐标
{
	return y;
}
int& Plane::getSpeed()//获得飞机速度
{
	return speed;
}
void Plane::movePlane()//飞机移动
{
	this->y += this->speed;
}
void Plane::delet()//飞机删除，就是把飞机移动到界面外面
{
	this->x = 900;
}