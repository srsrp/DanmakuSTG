#include "DxLib.h"
#include "Barrage.h"

Barrage::Barrage(){}

Barrage::Barrage(int Gx_, int Gy_, int GraphicSizeX_, int GraphicSizeY_, bool ScreenFlag_, char* FileName_, int RunSpeed_, int Distance_)
	:Object(Gx_, Gy_, GraphicSizeX_, GraphicSizeY_, ScreenFlag_, FileName_), RunSpeed(RunSpeed_), Distance(Distance_)
{}

void Barrage::Move(int Way_, int RunSpeed_) {
	switch (Way_) {
	case 0://è„
		Gy -= RunSpeed_;
		y -= Gy + GraphicSizeY / 2;
		break;
	case 1://âE
		Gx += RunSpeed_;
		x += Gx + GraphicSizeX / 2;
		break;
	case 2://â∫
		Gy += RunSpeed_;
		y += Gy + GraphicSizeY / 2;
		break;
	case 3://ç∂
		Gx -= RunSpeed_;
		x -= Gx + GraphicSizeX / 2;
		break;
	}
}

void Barrage::Hit(Object Object_) {
	//Distance=
}