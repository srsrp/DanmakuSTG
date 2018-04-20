#include "DxLib.h"
#include "Constant.h"
#include "Barrage.h"
#include <cmath>

Barrage::Barrage() {}

Barrage::Barrage(double Gx_, double Gy_, double Speed_, int GraphSizeX_, int GraphSizeY_, bool ScreenFlag_, char* FileName_)
	:Object(Gx_, Gy_, Speed_, GraphSizeX_, GraphSizeY_, ScreenFlag_, FileName_)
{}

void Barrage::SetUp(int LoopCount_, int MovePattern_, double Speed_, double Gx_, double Gy_, double A_, double B_, double C_) {
	ScreenFlag = TRUE;
	LoopCountIni = LoopCount_;
	MovePattern = MovePattern_;
	Speed = Speed_;
	Gx = Gx_;
	Gy = Gy_;
	A = A_;
	B = B_;
	C = C_;
}

void Barrage::Move() {
	if (ScreenFlag == TRUE)Display();
	double Time = LoopCount - LoopCountIni;

	switch (MovePattern) {

	case 0://ｙ座標を減らすだけ
		Gy += Speed;
		break;

	case 1://ななめに撃つ
		Gx += Speed * cos(PI / 180 * A);
		Gy += Speed * sin(PI / 180 * A);
		break;

	case 2:
		break;

	case 3:
		break;	
	}
	if (Gx<LEFT - 50 || Gx>RIGHT + 50 || Gy<UP - 50 || Gy>DOWN + 50)ScreenFlag = FALSE;
}
