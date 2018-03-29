#include "DxLib.h"
#include "Object.h"

Object::Object(){}

Object::Object(int Gx_, int Gy_, int GraphicSizeX_, int GraphicSizeY_, bool ScreenFlag_, char* FileName_) :
	Gx(Gx_), Gy(Gy_), GraphicSizeX(GraphicSizeX_), GraphicSizeY(GraphicSizeY_), x(Gx_ + GraphicSizeX / 2), y(Gy_ + GraphicSizeY / 2), ScreenFlag(FALSE)
{
	Handle = LoadGraph(FileName_);
}

void Object::Display() {
	DrawGraph(Gx, Gy, Handle, TRUE);
}

void Object::SetXY() {
	x = Gx + GraphicSizeX / 2;
	y = Gy + GraphicSizeY / 2;
}