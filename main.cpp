#include <math.h>
#include "DxLib.h"
#include "Constant.h"
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "Barrage.h"

//一般の変数
int LoopCount = 0;
int n, m;
char KeyBuffer[256];

//蓮子の初期位置
int RenkoX = (LEFT + RIGHT) / 2;
int RenkoY = (UP + DOWN) / 2 + 200;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//画像Handle
	char renkohd[50] = "renko.png";								//30*40
	char renkobarrage001hd[50] = "renkobarrage001.png";			//30*15
	char enemy001hd[50] = "enemy001.png";						//30*40
	char enemybarrage001hd[50] = "enemybarrage001.png";			//16*16

	//背景に関する変数
	unsigned int fuji;

	if (DxLib_Init() == -1) { return -1; }		//DXlibの呼び出し

	ChangeWindowMode(TRUE);
	SetWindowSize(960, 720);
	SetWindowPosition(0, 10);

	//自機
	Player Renko(RenkoX, RenkoY, 30, 40, TRUE, renkohd, 5);

	Barrage RenkoBarrge001[100];
	for (n = 0; n < 100; n++) {
		RenkoBarrge001[n] = Barrage(0, 0, 30, 15, FALSE, renkobarrage001hd, 12, 0);
	}

	//100ループで出てくる敵
	Enemy Enemy001(420, 100, 30, 40, FALSE, enemy001hd, 5);

	Barrage Enemy001Barrage[100];
	for (n = 0; n < 100; n++) {
		Enemy001Barrage[n] = Barrage(0, 0, 16, 16, FALSE, enemybarrage001hd, 12, 0);
	}

	//背景
	fuji = GetColor(187, 188, 222);

	SetDrawScreen(DX_SCREEN_BACK);

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		ClearDrawScreen();

		DrawBox(LEFT, UP, RIGHT + 31, DOWN + 41, fuji, TRUE);

		GetHitKeyStateAll(KeyBuffer);

		//蓮子周りの表示
		//蓮子の移動

		if (Renko.ScreenFlag == FALSE)Renko.Display();
		Renko.Move();

		//蓮子の弾幕の移動
		for (n = 0; n < 100; n++) {
			if (KeyBuffer[KEY_INPUT_Z] && RenkoBarrge001[n].ScreenFlag == FALSE) {
				RenkoBarrge001[n].Gx = Renko.Gx;				//中心とずれる
				RenkoBarrge001[n].Gy = Renko.Gy;				//同上
				RenkoBarrge001[n].ScreenFlag = TRUE;
				break;
			}
		}

		for (n = 0; n < 100; n++) {
			if (RenkoBarrge001[n].ScreenFlag == TRUE) {
				RenkoBarrge001[n].Display();
				RenkoBarrge001[n].Move(0, RenkoBarrge001[n].RunSpeed);
				if (RenkoBarrge001[n].Gy < UP)RenkoBarrge001[n].ScreenFlag = FALSE;
			}
		}

		//敵周りの表示
		//LoopCount=101で最初の敵登場

		if (LoopCount > 100)Enemy001.ScreenFlag = TRUE;

		if (Enemy001.ScreenFlag == TRUE) {
			Enemy001.Display();

			//CENTERまで右から移動してくる
			if (Enemy001.Gx > CENTER)Enemy001.Move(3, 3);
			//弾幕を撃っている間静止
			if (Enemy001Barrage[24].ScreenFlag == TRUE) {
				Enemy001.Move(3, 3);
			}
			/*
			//当たり判定
			for (n = 0; n < 100; n++) {
				RenkoBarrge001[n].Distance = sqrt((RenkoBarrge001[n].x - Enemy001.x)*(RenkoBarrge001[n].x - Enemy001.x) + (RenkoBarrge001[n].y - Enemy001.y)*(RenkoBarrge001[n].y - Enemy001.y));
				if (RenkoBarrge001[n].Distance <= 10) {
					Enemy001.ScreenFlag = FALSE;
				}

			}
			*/
		}

		//CENTERまで来たら弾幕を撃つ
		if (Enemy001.Gx <= CENTER) {
			for (n = 0; n < 100; n++) {
				if (Enemy001Barrage[n].ScreenFlag == FALSE && LoopCount % 2 == 0) {
					Enemy001Barrage[n].Gx = Enemy001.Gx + 7;
					Enemy001Barrage[n].Gy = Enemy001.Gy + 12;
					Enemy001Barrage[n].ScreenFlag = TRUE;
					break;
				}
			}

			for (n = 0; n < 25; n++) {
				if (Enemy001Barrage[n].ScreenFlag == TRUE) {
					Enemy001Barrage[n].Display();
					Enemy001Barrage[n].Move(1, 3 * cos(2 * PI / 8 + 2 * PI / 5 * n));
					Enemy001Barrage[n].Move(2, 3 * sin(2 * PI / 8 + 2 * PI / 5 * n));

				}
			}
		}

		//蓮子の当たり判定
		/*
		for (n = 0; n < 100; n++) {
			Enemy001Barrage[n].Distance = sqrt((Enemy001Barrage[n].x - Renko.x)*(Enemy001Barrage[n].x - Renko.x) + (Enemy001Barrage[n].y - Renko.y)*(Enemy001Barrage[n].y - Renko.y));
			if (Enemy001Barrage[n].Distance <= 10) {
				Renko.ScreenFlag = FALSE;
			}
		}
		*/

		ScreenFlip();
		LoopCount++;
		if (ProcessMessage() < 0) break;
		WaitTimer(INTERVAL);
	}

	DxLib_End();
	return 0;
}
