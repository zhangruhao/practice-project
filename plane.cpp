#include"plane.h"
Plane::Plane()
{

}//���캯��
Plane::Plane(int x, int y,const char *imgURL,int speed)//����һ���ɻ�
{
	this->x = x;
	this->y = y;
	img = newimage();
	getimage(img,imgURL);//�ɻ���ʾ�����������ļ�·���������棬�����ô�˫���š�
	this->speed = speed;
}
void Plane::drawPlane()//�����ɻ�
{
	putimage_withalpha(NULL, img, x, y);
}
void Plane::keyDown(char userKey)//�����ƶ��ɻ�
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
		this->x += this->speed;//thisָ����ú���
		break;
	}
}
int& Plane::getx()//��÷ɻ�x����
{
	return x;
}
int& Plane::gety()//��÷ɻ�y����
{
	return y;
}
int& Plane::getSpeed()//��÷ɻ��ٶ�
{
	return speed;
}
void Plane::movePlane()//�ɻ��ƶ�
{
	this->y += this->speed;
}
void Plane::delet()//�ɻ�ɾ�������ǰѷɻ��ƶ�����������
{
	this->x = 900;
}