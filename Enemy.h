#ifndef INCLUDED_ENEMY_H_
#define INCLUDED_ENEMY_H_

#include "Object.h"

class Enemy :public Object {
public:
	int MoveSpeed;

	Enemy();
	Enemy(int Gx_, int Gy_, int GraphicSizeX_, int GraphicSizeY_, bool ScreenFlag_, char* FileName_);

	void SetPos(int x_, int y_);

	//座標指定して移動
	void Move(int Pattern_, double x, double y, int Speed_);

};

#endif
