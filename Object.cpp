#include "DxLib.h"
#include "Object.h"

Object::Object(){}

Object::Object(double Gx_, double Gy_,double Speed_, int GraphicSizeX_, int GraphicSizeY_, bool ScreenFlag_, char* FileName_) :
	Gx(Gx_), Gy(Gy_), Speed(Speed_), GraphicSizeX(GraphicSizeX_), GraphicSizeY(GraphicSizeY_), ScreenFlag(FALSE)
{
	Handle = LoadGraph(FileName_);
}

void Object::Display() {
	DrawGraph(Gx, Gy, Handle, TRUE);
}
