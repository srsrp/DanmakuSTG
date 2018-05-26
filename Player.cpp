#include "DxLib.h"
#include "Player.h"
#include "Constant.h"

int Counter;

Player::Player(){}

Player::Player(char* FileName_, PlayerType Type_, int SizeX_, int SizeY_) {
	
	Type = Type_;
	SizeX = SizeX_;
	SizeY = SizeY_;
	Handle = LoadDivGraph(FileName_, 3, 3, 1, SizeX, SizeY, GraHandle);
	Gx = RenkoX;
	Gy = RenkoY;
	MoveSpeed = 0;
	ScreenFlag = TRUE;

}

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
	if (Gx > RIGHT + SizeX)	Gx = RIGHT + SizeX;
	if (Gy > DOWN + SizeY)	Gy = DOWN + SizeY;

	if (ScreenFlag == TRUE) {
		Display();
		Counter = 0;
	}
	else {
		Counter++;
		if (Counter > 50) {
			ScreenFlag = TRUE;
			Gx = RenkoX;
			Gy = RenkoY;
		}
	}
}

void Player::Display() {
	if (LoopCount % 32 >= 0 && LoopCount % 32 <= 7) {
		DrawRotaGraph(Gx, Gy, 1.0, 0, GraHandle[0], TRUE);
	}
	if (LoopCount % 32 >= 8 && LoopCount % 32 <= 15) {
		DrawRotaGraph(Gx, Gy, 1.0, 0, GraHandle[1], TRUE);
	}
	if (LoopCount % 32 >= 16 && LoopCount % 32 <= 23) {
		DrawRotaGraph(Gx, Gy, 1.0, 0, GraHandle[2], TRUE);
	}
	if (LoopCount % 32 >= 24 && LoopCount % 32 <= 31) {
		DrawRotaGraph(Gx, Gy, 1.0, 0, GraHandle[1], TRUE);
	}
	if (MoveSpeed == LOW) {
		DrawCircle(Gx, Gy, Radius, GetColor(255, 0, 0), 1);
	}
}
