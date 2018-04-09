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
	char enemy002hd[50] = "enemy002.png";						//30*40

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

	//今は出てこない敵
	Enemy Enemy100(420, 100, 30, 40, FALSE, enemy001hd);
	Barrage Enemy100Barrage[100];
	for (n = 0; n < 100; n++) {
		Enemy100Barrage[n] = Barrage(0, 0, 16, 16, FALSE, enemybarrage001hd, 12, 0);
	}

	//Pattern0で出てくる敵
	Enemy Enemy0[30];
	for (n = 0; n < 30; n++) {
		Enemy0[n] = Enemy(0, 0, 30, 40, FALSE, enemy001hd);
	}
	Barrage Enemy0Bar[30][100];
	for (n = 0; n < 30; n++) {
		for (m = 0; m < 100; m++) {
			Enemy0Bar[n][m] = Barrage(0, 0, 16, 16, FALSE, enemybarrage001hd, 12, 0);
		}
	}

	//Patten1
	Enemy Enemy1[10];
	for (n = 0; n < 10; n++) {
		Enemy1[n] = Enemy(0, 0, 30, 40, FALSE, enemy002hd);
	}

	//Pattern2
	Enemy Enemy2[10];
	for (n = 0; n < 10; n++) {
		Enemy2[n] = Enemy(0, 0, 30, 40, FALSE, enemy002hd);
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
		/*
		//LoopCount=100で最初の敵登場

		if (LoopCount > 100) Enemy100.ScreenFlag = TRUE;

		if (Enemy100.ScreenFlag == TRUE) {
			Enemy100.Display();

			//CENTERまで右から移動してくる
			if (Enemy100.Gx > CENTER)Enemy100.Move(3, 3);
			//弾幕を撃っている間静止
			if (Enemy100Barrage[24].ScreenFlag == TRUE) {
				Enemy100.Move(3, 3);
			}
			
			//当たり判定
			for (n = 0; n < 100; n++) {
				RenkoBarrge001[n].Distance = sqrt((RenkoBarrge001[n].x - Enemy100.x)*(RenkoBarrge001[n].x - Enemy100.x) + (RenkoBarrge001[n].y - Enemy100.y)*(RenkoBarrge001[n].y - Enemy100.y));
				if (RenkoBarrge001[n].Distance <= 10) {
					Enemy100.ScreenFlag = FALSE;
				}

			}
			
		}
		

		//CENTERまで来たら弾幕を撃つ
		if (Enemy100.Gx <= CENTER) {
			for (n = 0; n < 25; n++) {
				if (Enemy100Barrage[n].ScreenFlag == FALSE && LoopCount % 2 == 0) {
					Enemy100Barrage[n].Gx = Enemy100.Gx + 7;
					Enemy100Barrage[n].Gy = Enemy100.Gy + 12;
					Enemy100Barrage[n].ScreenFlag = TRUE;
					break;
				}
			}
			for (n = 0; n < 25; n++) {
				if (Enemy100Barrage[n].ScreenFlag == TRUE) {
					Enemy100Barrage[n].Display();
					Enemy100Barrage[n].Move(1, 3 * cos(2 * PI / 8 + 2 * PI / 5 * n));
					Enemy100Barrage[n].Move(2, 3 * sin(2 * PI / 8 + 2 * PI / 5 * n));

				}
			}
		}
		*/

		for (n = 0; n < 3; n++) {
			if (LoopCount == 100 + 20 * n)Enemy0[n].SetPos(0, 75 + 25 * n);
			Enemy0[n].Move(0, PI / 6, 0, 4);
		}

		for (n = 3; n < 6; n++) {
			if (LoopCount == 90 + 20 * n)Enemy0[n].SetPos(420, 25 * n);
			Enemy0[n].Move(0, 5 * PI / 6, 0, 4);
		}

		if (LoopCount == 200) {
			
			Enemy1[1].SetPos(320, 0);
			Enemy1[0].SetPos(100, 0);
		}
		
		Enemy1[1].Move(1, 320, 250, 2);
		Enemy1[0].Move(1, 100, 250, 2);

		/*LoopCount == 1500)Enemy1[0].SetPos(100, 0);
		Enemy1[0].Move(1, 100, 200, 1);
		*/

		//Pattern2
		if (LoopCount == 2500)Enemy2[0].SetPos(100, 0);
		Enemy2[0].Move(2, 0, 250, 3);

		//蓮子の当たり判定
		/*
		for (n = 0; n < 100; n++) {
			Enemy100Barrage[n].Distance = sqrt((Enemy100Barrage[n].x - Renko.x)*(Enemy100Barrage[n].x - Renko.x) + (Enemy100Barrage[n].y - Renko.y)*(Enemy100Barrage[n].y - Renko.y));
			if (Enemy100Barrage[n].Distance <= 10) {
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
