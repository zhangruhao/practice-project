#include<iostream>
#include<graphics.h>
using namespace std;
/*
* �ɻ����ͷ�ļ���
*/
class Bullet
{
public:
	Bullet();//���캯��
	Bullet(int x, int y, const char* imgURL, int speed);//�ļ�·�����ݴ�����ǰ�����const
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
