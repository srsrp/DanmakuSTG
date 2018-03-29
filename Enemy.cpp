#include "DxLib.h"
#include "Enemy.h"

Enemy::Enemy(){}

Enemy::Enemy(int Gx_, int Gy_, int GraphicSizeX_, int GraphicSizeY_, bool ScreenFlag_, char* FileName_, int MoveSpeed_) 
	:Object(Gx_, Gy_, GraphicSizeX_, GraphicSizeY_, ScreenFlag_, FileName_), MoveSpeed(MoveSpeed_)
{}

void Enemy::Move(int Way_, int MoveSpeed_) {
	switch (Way_) {//right,up,�E�E�E�Ƃ��Ŏw��ł���΂Ȃ��킩��Ղ�
	case 0://��
		Gy -= MoveSpeed_;
		y -= Gy + GraphicSizeY / 2;
		break;
	case 1://�E
		Gx += MoveSpeed_;
		x += Gx + GraphicSizeX / 2;
		break;
	case 2://��
		Gy += MoveSpeed_;
		y += Gy + GraphicSizeY / 2;
		break;
	case 3://��
		Gx -= MoveSpeed_;
		x -= Gx + GraphicSizeX / 2;
		break;
	}
}