#include<graphics.h>
#include<conio.h>
#include"plane.h"
#include"bullet.h"
#include<time.h>
#include<list>
using namespace std;
/*
WASD控制移动，注意编译时按一下shift，因为默认中文。
C++实际开发一般用封装好的数据结构，不用自己写
L，大招

主要讲设计思路，算法思路具体细节短时间理解不了
*/
char planeName1[50] = { "D:\\plane\\bing1.png" };
char planeName2[50] = { "D:\\plane\\bing2.png" };
char planeName3[50] = { "D:\\plane\\bing3.png" };
char bullet2[50] = { "D:\\plane\\bullet2.png" };//盘符用：
char planerole1[50] = { "D:\\plane\\blue.png" };
char planerole2[50] = { "D:\\plane\\pink.png" };
char planerole3[50] = { "D:\\plane\\plane1.png" };
char buff1[50] = { "D:\\plane\\buff1.png" };
char buff2[50] = { "D:\\plane\\buff2.png" };
char buff3[50] = { "D:\\plane\\buff3.png" };
char nandu1[50] = { "D:\\plane\\33.jpg" };
char nandu2[50] = { "D:\\plane\\22.jpg" };
char nandu3[50] = { "D:\\plane\\11.png" };
int ppp = 0;//选择1
int ppp2 = 0;//选择2
int buff = 0;//buff层数
int main()
{
	int r = 0, e = 0;
	srand((unsigned int)time(NULL));
	initgraph(513, 600, 0);//左右，上下，是否
	PIMAGE bei = newimage();
	PIMAGE choice1 = newimage();
	PIMAGE guan = newimage();
	PIMAGE over = newimage();
	PIMAGE end = newimage();
	PIMAGE choice2 = newimage();
	PIMAGE choice3 = newimage();
	getimage(choice1, "D:\\plane\\begin.png");
	getimage(over, "D:\\plane\\over.png");
	getimage(choice3, "D:\\plane\\choice3.png");
	getimage(guan, "D:\\plane\\guan.png");
	getimage(end, "D:\\plane\\end.png");
	getimage(choice2, "D:\\plane\\choice2.png");
	list<Bullet*>myBullet;
	list<Bullet*>::iterator iterBullet;
	Bullet* pBullet = NULL;
	MUSIC yin;
	yin.OpenFile("D:\\plane\\music.mp3");
	MUSIC boom;
	boom.OpenFile("D:\\plane\\boom.mp3");
	yin.Play();
	if (yin.GetPlayStatus() == MUSIC_MODE_STOP) {
		//从头开始播放
		yin.Play(0);
	}
	int s = 0;
	//
ggg:
	while (1)//开始界面成功
	{
		putimage(0, 0, choice1);
		if (kbhit())
		{
			char Key = getch();
			if (Key == 'a')
			{
				break;
			}
			else if (Key == 'b')
			{
				while (1)
				{
					putimage(0, 0, guan);
					if (kbhit())
					{
						char back = getch();
						if (back == 'a')
						{
							goto ggg;
						}
					}
				}
			}
			else if (Key == 'c')
			{
				exit(0);
			}
			else
			{
				int fff = 0;
				fff++;
			}
		}
	}
	while (1)//选择界面成功
	{
		putimage(0, 0, choice2);
		if (kbhit())
		{
			char Key2 = getch();
			if (Key2 == 'a')
			{
				ppp = 1;
			}
			if (Key2 == 'b')
			{
				ppp = 2;
			}
			if (Key2 == 'c')
			{
				ppp = 3;
			}
			if (Key2 == 'd');
			{
				break;
			}
		}
	}
	while (1)
	{
		putimage(0, 0, choice3);
		if (kbhit())
		{
			char Key3 = getch();
			if (Key3 == 'a')
			{
				ppp2 = 1;
			}
			else if (Key3 == 'b')
			{
				ppp2 = 2;
			}
			else if (Key3 == 'c')
			{
				ppp2 = 3;
			}
			else if (Key3 == 'd')
			{
				goto haha;
			}
		}
	}
haha:
	if (ppp2 == 1)
	{
		getimage(bei, nandu1);
	}
	if (ppp2 == 2)
	{
		getimage(bei, nandu2);
	}
	if (ppp2 == 3)
	{
		getimage(bei, nandu3);
	}
	Plane* pRole = new Plane(50, 50, planerole1, 10);
	if (ppp == 0)
	{
		exit(0);
	}
	if (ppp == 1)
	{
		pRole == NULL;
		pRole = new Plane(50, 50, planerole1, 10);
	}
	if (ppp == 2)
	{
		pRole == NULL;
		pRole = new Plane(50, 50, planerole2, 10);
	}
	if (ppp == 3)
	{
		pRole == NULL;
		pRole = new Plane(50, 50, planerole3, 10);
	}
	list<Plane*>myPlane;
	list<Plane*>myPlane2;//子弹的
	list<Plane*>myPlane3;//buff的
	list<Plane*>::iterator iterPlane;
	list<Plane*>::iterator iterPlane2;
	list<Plane*>::iterator iterPlane3;
	Plane* pOject = NULL;
	Plane* pOject2 = NULL;//敌方子弹
	Plane* pOject3 = NULL;//buff
	while (1)
	{
	congxin:
		putimage(0, 0, bei);
		setbkmode(TRANSPARENT);
		xyprintf(0, 30, "您的buff层数：%d层", buff);
		if (s <= 10)
		{
			xyprintf(0, 0, "你击落的敌机：%d", s);
			xyprintf(0, 15, "你的积分等级：菜鸟", s);
		}
		if (s > 10 && s <= 30)
		{
			xyprintf(0, 0, "你击落的敌机：%d", s);
			xyprintf(0, 15, "你的积分等级：精英", s);
		}
		if (s > 30 && s <= 50)
		{
			xyprintf(0, 0, "你击落的敌机：%d", s);
			xyprintf(0, 15, "你的积分等级：国服选手", s);
		}
		if (s > 50)
		{
			xyprintf(0, 0, "你击落的敌机：%d", s);
			xyprintf(0, 15, "你的积分等级：东软之光", s);
		}
		if (s == 100)
		{
		end2:
			while (1)//结束界面
			{
				putimage(0, 0, end);
			}
		}
		if (myPlane.size() < 3)
		{
			int pos = rand() % 3;
			switch (pos)
			{
			case 0:
				pOject = new Plane(rand() % 5 * 100, -100, planeName1, 1);
				break;
			case 1:
				pOject = new Plane(rand() % 1 * 300 + 200, -100, planeName2, 1);//调整不重叠
				break;
			case 2:
				pOject = new Plane(rand() % 3 * 120 + 140, -100, planeName3, 1);
				break;

			}
			myPlane.push_back(pOject);
			r++;
		}
		if (myPlane3.size() < 3)//buff的
		{
			int pos3 = rand() % 3;
			switch (pos3)
			{
			case 0:
				pOject3 = new Plane(rand() % 5 * 100, -100, buff1, 1);
				break;
			case 1:
				pOject3 = new Plane(rand() % 1 * 300 + 200, -100, buff2, 1);//调整不重叠
				break;
			case 2:
				pOject3 = new Plane(rand() % 3 * 120 + 140, -100, buff3, 1);
				break;

			}
			myPlane3.push_back(pOject3);
		}
		if (ppp2 == 1)
		{
			if (myPlane2.size() < 3)//敌方子弹
			{
				int pos2 = rand() % 3;
				switch (pos2)
				{
				case 0:
					pOject2 = new Plane(rand() % 5 * 100, -100, bullet2, 2);
					break;
				case 1:
					pOject2 = new Plane(rand() % 1 * 300 + 200, -100, bullet2, 2);
					break;
				case 2:
					pOject2 = new Plane(rand() % 3 * 120 + 140, -100, bullet2, 2);
					break;

				}
				myPlane2.push_back(pOject2);
			}
		}
		if (ppp2 == 3)
		{
			if (myPlane2.size() < 1)//敌方子弹
			{
				pOject2 = new Plane(rand() % 5 * 100, -100, bullet2, 2);
				myPlane2.push_back(pOject2);
			}
		}
		if (ppp2 == 2)
		{
			if (myPlane2.size() < 2)//敌方子弹
			{
				int pos2 = rand() % 3;
				switch (pos2)
				{
				case 0:
					pOject2 = new Plane(rand() % 5 * 100, -100, bullet2, 2);
					break;
				case 1:
					pOject2 = new Plane(rand() % 1 * 300 + 200, -100, bullet2, 2);
					break;
				}
				myPlane2.push_back(pOject2);
			}
		}
		for (iterPlane2 = myPlane2.begin(); iterPlane2 != myPlane2.end(); iterPlane2++)//释放子弹
		{
			if ((*iterPlane2)->gety() >= 600)
			{
				iterPlane2 = myPlane2.erase(iterPlane2);
				if (iterPlane2 == myPlane2.end())
				{
					break;
				}
			}
		}
		for (iterPlane3 = myPlane3.begin(); iterPlane3 != myPlane3.end(); iterPlane3++)//释放buff
		{
			if ((*iterPlane3)->gety() >= 600)
			{
				iterPlane3 = myPlane3.erase(iterPlane3);
				if (iterPlane3 == myPlane3.end())
				{
					break;
				}
			}
		}
		pRole->drawPlane();
		if (kbhit())
		{
			char userKey = getch();
			pRole->keyDown(userKey);
			if (userKey == ' ')
			{
				pBullet = new Bullet(pRole->getx(), pRole->gety() - 30, "D:\\plane\\bullet1.png", 10);
				myBullet.push_back(pBullet);
				e++;
			}
			if (userKey == 'l')
			{
				pBullet = new Bullet(pRole->getx(), pRole->gety() - 30, "D:\\plane\\bos.png", 10);
				myBullet.push_back(pBullet);
			}
			if (userKey == 'z')
			{
				goto end2;
			}
		}
		for (iterPlane = myPlane.begin(); iterPlane != myPlane.end(); iterPlane++)
		{

			(*iterPlane)->drawPlane();
			(*iterPlane)->movePlane();
		}
		for (iterPlane2 = myPlane2.begin(); iterPlane2 != myPlane2.end(); iterPlane2++)//敌方子弹
		{

			(*iterPlane2)->drawPlane();
			(*iterPlane2)->movePlane();
		}
		for (iterPlane3 = myPlane3.begin(); iterPlane3 != myPlane3.end(); iterPlane3++)//buff
		{

			(*iterPlane3)->drawPlane();
			(*iterPlane3)->movePlane();
		}
		for (iterPlane = myPlane.begin(); iterPlane != myPlane.end(); iterPlane++)
		{
			if ((*iterPlane)->gety() >= 600)
			{
				iterPlane = myPlane.erase(iterPlane);
				if (iterPlane == myPlane.end())
				{
					break;
				}
			}
		}
		for (iterBullet = myBullet.begin(); iterBullet != myBullet.end(); iterBullet++)
		{
			for (iterPlane = myPlane.begin(); iterPlane != myPlane.end(); iterPlane++)
			{
				int xx, yy, xx1, yy2;
				xx = (*iterPlane)->getx();
				yy = (*iterPlane)->gety();
				xx1 = (*iterBullet)->getx();
				yy2 = (*iterBullet)->gety();
				if (xx > (xx1 - 50) && xx < (xx1 + 50))
				{
					if (yy > (yy2 - 30) && yy < (yy2 + 30))
					{
						boom.Play();
						(*iterPlane)->delet();//控制子弹删除飞机,成功
						s++;
					}
				}
			}
		}
		for (iterPlane3 = myPlane3.begin(); iterPlane3 != myPlane3.end(); iterPlane3++)
		{
			int xx2, yy2, xx3, yy3;
			xx2 = pRole->getx();
			yy2 = pRole->gety();
			xx3 = (*iterPlane3)->getx();
			yy3 = (*iterPlane3)->gety();
			if (xx2 > (xx3 - 50) && xx2 < (xx3 + 50))
			{
				if (yy2 > (yy3 - 30) && yy2 < (yy3 + 30))
				{
					(*iterPlane3)->delet();//buff成功
					buff++;
				}
			}
		}
		for (iterPlane2 = myPlane2.begin(); iterPlane2 != myPlane2.end(); iterPlane2++)//敌方子弹打我方
		{
			int xx5, yy5, xx6, yy6;
			xx5 = pRole->getx();
			yy5 = pRole->gety();
			xx6 = (*iterPlane2)->getx();
			yy6 = (*iterPlane2)->gety();
			if (xx5 > (xx6 - 30) && xx5 < (xx6 + 30))
			{
				if (yy5 > (yy6 - 20) && yy5 < (yy6 + 20))
				{
					while (1)
					{
						putimage(0, 0, over);//结束部分
						xyprintf(190, 290, "您的buff层数：%d层", buff);
						xyprintf(190, 260, "你击落的敌机：%d", s);
						if (s <= 10)
						{
							xyprintf(190, 230, "你的积分等级：菜鸟", s);
						}
						if (s > 10 && s <= 30)
						{
							xyprintf(190, 230, "你的积分等级：精英", s);
						}
						if (s > 30 && s <= 50)
						{
							xyprintf(190, 230, "你的积分等级：国服选手", s);
						}
						if (s > 50)
						{
							xyprintf(190, 230, "你的积分等级：东软之光", s);
						}
						Sleep(0.5);
						if (kbhit())
						{
							char userKey9 = getch();
							if (userKey9 == 'a')
							{
								goto congxin;
							}
						}
					}
				}
			}
		}
		for (iterBullet = myBullet.begin(); iterBullet != myBullet.end(); iterBullet++)
		{
			(*iterBullet)->drawBullet();
			(*iterBullet)->moveBullet();
			if (e == 8)
			{
				e = 0;
				myBullet.pop_back();
			}
		}
		Sleep(0.1);//防止闪屏
	}
	return 0;
}