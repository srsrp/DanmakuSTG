#ifndef INCLUDED_ENEMY_H_
#define INCLUDED_ENEMY_H_

#include "Object.h"

class Enemy :public Object {
public:
	int MoveSpeed;

	Enemy();
	Enemy(int Gx_, int Gy_, int GraphicSizeX_, int GraphicSizeY_, bool ScreenFlag_, char* FileName_, int MoveSpeed_);

	//ï˚å¸ÅAó 
	void Move(int Way_, int MoveSpeed_);
};

#endif