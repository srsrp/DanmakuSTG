#include "DxLib.h"
#include "Object.h"
#include "Constant.h"

Object::Object(){}

Object::Object(double Gx_, double Gy_,double Speed_, int GraphicSizeX_, int GraphicSizeY_, bool ScreenFlag_, char* FileName_) :
	Gx(Gx_), Gy(Gy_), Speed(Speed_), GraphicSizeX(GraphicSizeX_), GraphicSizeY(GraphicSizeY_), ScreenFlag(FALSE)
{
	//Handle = LoadGraph(FileName_);
	Handle = LoadDivGraph(FileName_, 3, 3, 1, 60, 80, GraHandle);
}

void Object::Display() {
	//DrawGraph(Gx, Gy, Handle, TRUE);
	if (LoopCount % 21 >= 0 && LoopCount % 21 <= 6) {
		DrawExtendGraph(Gx, Gy, Gx + GraphicSizeX + 1, Gy + GraphicSizeY + 1, GraHandle[0], TRUE);
	}
	if (LoopCount % 21 >= 7 && LoopCount % 21 <= 13) {
		DrawExtendGraph(Gx, Gy, Gx + GraphicSizeX + 1, Gy + GraphicSizeY + 1, GraHandle[1], TRUE);
	}
	if (LoopCount % 21 >= 14 && LoopCount % 21 <= 20) {
		DrawExtendGraph(Gx, Gy, Gx + GraphicSizeX + 1, Gy + GraphicSizeY + 1, GraHandle[2], TRUE);
	}

}
