#include"bullet.h"
Bullet::Bullet()
{

}//���캯��
/*
* ��������ʱ���г�ʼ������һ������ĳ�Ա�������������ֺ�������ͬ
��û�з���ֵ������Ҫ�û����ã������ڴ�������ʱ�Զ�ִ�У��������ʵ����
*/
Bullet::Bullet(int x, int y, const char* imgURL, int speed)//����һ���ӵ�
{
	this->x = x;//thisָ�������Ԫ��
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