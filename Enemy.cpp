#include "DxLib.h"
#include "Enemy.h"
#include "math.h"
#include "Constant.h"

Enemy::Enemy(){}

Enemy::Enemy(int Gx_, int Gy_, int GraphicSizeX_, int GraphicSizeY_, bool ScreenFlag_, char* FileName_) 
	:Object(Gx_, Gy_, GraphicSizeX_, GraphicSizeY_, ScreenFlag_, FileName_), MoveSpeed(0)
{}

void Enemy::SetPos(int x_, int y_) {
	ScreenFlag = TRUE;
	Gx = x_;
	Gy = y_;
}

void Enemy::Move(int Pattern_, double x, double y, int Speed_) {
	if (ScreenFlag == TRUE)Display();
	switch (Pattern_) {
	case 0://直線移動、xは角度
		Gx += Speed_ * cos(x);
		Gy += Speed_ * sin(x);
		if (Gx > RIGHT + 30 || Gx < LEFT - 40)ScreenFlag = FALSE;
		break;

	case 1://直角移動
		if (Gy < y) {
			Gy += Speed_;
		}
		if (Gy >= y) {
			if (x < CENTER)Gx += Speed_;
			if (x > CENTER)Gx -= Speed_;
		}
		if (Gx > RIGHT + 30 || Gx < LEFT - 40)ScreenFlag = FALSE;
		break;

	case 2://漸近曲線
		Gx += Speed_;
		Gy += 0.04*Speed_ * (y - Gy);
		if (Gx > RIGHT + 30 || Gx < LEFT - 40)ScreenFlag = FALSE;
		break;
	}
}
