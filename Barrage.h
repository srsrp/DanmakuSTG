#ifndef INCLUDED_BARRAGE_H_
#define INCLUDED_BARRAGE_H_

#include "Object.h"

class Barrage :public Object {
public:
	int RunSpeed;
	int Distance;

	Barrage();
	Barrage(int Gx_, int Gy_, int GraphicSizeX_, int GraphicSizeY_, bool ScreenFlag_, char* FileName_, int RunSpeed_, int Distance_);

	void Move(int Way_, int runSpeed);
	void Hit(Object Object_);
};

#endif