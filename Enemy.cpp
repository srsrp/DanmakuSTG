#include "DxLib.h"
#include "Enemy.h"
#include <cmath>
#include "Constant.h"

Enemy::Enemy(){}
Enemy::Enemy(double Gx_, double Gy_, double Speed_, int GraphSizeX_, int GraphSizeY_, bool ScreenFlag_, char* FileName_)
	:Object(Gx_, Gy_, Speed_, GraphSizeX_, GraphSizeY_, ScreenFlag_, FileName_)
{
	//BarHandle = LoadGraph(FileName2_);
}

void Enemy::SetUp(int LoopCount_, int MovePattern_, double Speed_, double x_, double y_, double A_, double B_, double C_) {
	ScreenFlag = TRUE;
	LoopCountIni = LoopCount_;
	MovePattern = MovePattern_;
	Speed = Speed_;
	Gx = x_;
	Gy = y_;
	A = A_;
	B = B_;
	C = C_;
}

void Enemy::Move() {
	if (ScreenFlag == TRUE)Display();
	double Time = LoopCount - LoopCountIni;

	switch (MovePattern) {
	case 0://減速して接近、静止後、加速して離脱
		/*	A	:行きの角度
			B	:帰りの角度
			C	:停止ループ数		*/
		if (Time < 150) {
			Gx += Speed * cos(PI / 180 * A) * (1 - Time / 150);
			Gy += Speed * sin(PI / 180 * A) * (1 - Time / 150);
		}
		if (Time >= 150 + C) {
			Gx += Speed * cos(PI / 180 * B) * (1 - Time / 150);
			Gy += Speed * sin(PI / 180 * B) * (1 - Time / 150);
		}
		break;

	case 1://等速運動
		   /*	A	:x軸からの角度
				B	:
				C	:			*/
		Gx += Speed * cos(PI / 180 * A);
		Gy += Speed * sin(PI / 180 * A);
		break;
	}
	if (Gx<LEFT - 50 || Gx>RIGHT + 50 || Gy<UP - 50 || Gy>DOWN + 50)ScreenFlag = FALSE;
}
