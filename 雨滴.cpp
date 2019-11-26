#include <iostream>
#include<corecrt_wstdio.h>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include<string>
#include <vector>
using namespace std;
struct water {
	int x, y1, y2;
	int speed;
	vector<int> v;
	water(int x, int y1, int y2, int speed):x(x),y1(y1),y2(y2),speed(speed){
		for (int i = 0; i < y2; i++) {
			v.push_back(rand() % 2+'0');
		}
	}
};

void drawWater(water w){
	for (int i = 0; i < w.y2; i++) {
		if (rand() % 10 < 1)
		{
			if (w.v[i] == '0') w.v[i] = '1';
			if (w.v[i] == '1') w.v[i] = '0';
		}
		outtextxy(w.x, i*16 + w.y1, w.v[i]);
	}
}


void CharWater()
{
	const int width = 1200;
	const int hight = 600;
	initgraph(width, hight);
	srand((unsigned)time(nullptr));
	vector<water> ws;
	settextstyle(16, 8,_T("宋体"));
	//配置
	int speed = 20;//下落速度
	int nums = 20; // 雨滴产生速度
	int len = 5; // 雨滴的最大长度

	while (1) {
	
		// 随机生成余雨滴数量
		int wn = rand() % nums;
		for (int i = 0; i < wn; i++) {
			ws.push_back(water((rand() % (width/16))*16, 10,rand()%len, rand()%speed+1));
		}
		//落下
		for (int i = ws.size() - 1; i >= 0; i--) {
			setcolor(BLACK);
			drawWater(ws[i]);
			
			setcolor(GREEN);
			ws[i].y1 += ws[i].speed;
			drawWater(ws[i]);

			if (ws[i].y1 + ws[i].y2 >= hight+20)
				ws.erase(ws.begin() + i);
		}
		//显示目前多少雨滴
		string size = to_string(ws.size());
		for (int i = 0; i < size.size(); i++) {
			outtextxy(i * 16, 0, size[i]);
		}
		Sleep(50);
	}

	// 关闭图形模式
	closegraph();
}

int main() {
	CharWater();
}