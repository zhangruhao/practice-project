#include<iostream>
#include<graphics.h>
using namespace std;
class Plane
{
public:
	Plane();//���캯��
	Plane(int x, int y,const char *imgURL,int speed);//�ļ�·�����ݴ�����ǰ�����const���ɻ�����
	void drawPlane();//���ɻ�
	void keyDown(char userKey);//�����ƶ��ɻ�
	void movePlane();//�л��ɻ����ƶ����л����ҷ�ս���õ�ͬһ����
	void delet();//ɾ���л�
	int& getx();//��÷ɻ�x����
	int& gety();//��÷ɻ�y����
	int& getSpeed();//��÷ɻ��ٶ�
protected:
	int x;
	int y;
	int speed;
	PIMAGE img;
};