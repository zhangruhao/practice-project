#include"bullet.h"
Bullet::Bullet()
{

}//构造函数
/*
* 创建对象时进行初始化，是一种特殊的成员函数，它的名字和类名相同
，没有返回值，不需要用户调用，而是在创建对象时自动执行，用于类的实例化
*/
Bullet::Bullet(int x, int y, const char* imgURL, int speed)//创造一个子弹
{
	this->x = x;//this指针调用类元素
	this->y = y;
	img = newimage();
	getimage(img, imgURL);
	this->speed = speed;
}
void Bullet::drawBullet()
{
	putimage_withalpha(NULL, img, x, y);
}
void Bullet::moveBullet()
{
	this->y -= this->speed;
}
int& Bullet::getx()
{
	return x;
}
int& Bullet::gety()
{
	return y;
}
int& Bullet::getSpeed()
{
	return speed;
}