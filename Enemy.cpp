#include "DxLib.h"
#include "Enemy.h"

Enemy::Enemy(){}

Enemy::Enemy(int Gx_, int Gy_, int GraphicSizeX_, int GraphicSizeY_, bool ScreenFlag_, char* FileName_, int MoveSpeed_) 
	:Object(Gx_, Gy_, GraphicSizeX_, GraphicSizeY_, ScreenFlag_, FileName_), MoveSpeed(MoveSpeed_)
{}

void Enemy::Move(int Way_, int MoveSpeed_) {
	switch (Way_) {//right,up,・・・とかで指定できればなおわかり易い
	case 0://上
		Gy -= MoveSpeed_;
		y -= Gy + GraphicSizeY / 2;
		break;
	case 1://右
		Gx += MoveSpeed_;
		x += Gx + GraphicSizeX / 2;
		break;
	case 2://下
		Gy += MoveSpeed_;
		y += Gy + GraphicSizeY / 2;
		break;
	case 3://左
		Gx -= MoveSpeed_;
		x -= Gx + GraphicSizeX / 2;
		break;
	}
}