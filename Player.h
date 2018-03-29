#ifndef INCLUDED_PLAYER_H_
#define INCLUDED_PLAYER_H_

#include"Object.h"

extern char KeyBuffer[256];

class Player :public Object {
public:
	int MoveSpeed;	//移動スピード

	Player();
	Player(int Gx_, int Gy_, int GraphicSizeX_, int GraphicSizeY_, bool ScreenFlag_, char* FileName_, int MoveSpeed_);
	void Move();
};

#endif