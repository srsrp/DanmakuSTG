#include "DxLib.h"
#include "Player.h"

#include "Constant.h"

Player::Player(){}

Player::Player(int Gx_, int Gy_, int GraphicSizeX_, int GraphicSizeY_, bool ScreenFlag_, char* FileName_, int MoveSpeed_) 
	:Object(Gx_, Gy_, GraphicSizeX_, GraphicSizeY_, ScreenFlag_, FileName_),MoveSpeed(MoveSpeed_)
{}

void Player::Move() {
	if (KeyBuffer[KEY_INPUT_LSHIFT] == 0) {
		MoveSpeed = HIGH;
	}
	else {
		MoveSpeed = LOW;
	}

	if (KeyBuffer[KEY_INPUT_LEFT])	Gx -= MoveSpeed;
	if (KeyBuffer[KEY_INPUT_UP])	Gy -= MoveSpeed;
	if (KeyBuffer[KEY_INPUT_RIGHT])	Gx += MoveSpeed;
	if (KeyBuffer[KEY_INPUT_DOWN])	Gy += MoveSpeed;

	if (Gx < LEFT)	Gx = LEFT;
	if (Gy < UP)	Gy = UP;
	if (Gx > RIGHT)	Gx = RIGHT;
	if (Gy > DOWN)	Gy = DOWN;
}