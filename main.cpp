#include <math.h>
#include "DxLib.h"
#include "Constant.h"
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "Barrage.h"

//一般の変数
int LoopCount = 0;
int n = 0;
int m = 0;
int l = 0;
char KeyBuffer[256];

void SetEne(Enemy enemy_[], int LoopCount_, int MovePattern_, double Speed_, double Gx_, double Gy_, double A_, double B_, double C_);
void SetBar(Barrage barrage_[], int LoopCount_, int MovePattern_, double Speed_, double Gx_, double Gy_, double A_, double B_, double C_);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//画像Handle
	char renkohd[50]			=	"renko.png";					//30*40
	char renkobarrage001hd[50]	=	"renkobarrage001.png";			//30*15
	char enemy001hd[50]			=	"enemy001.png";					//30*40
	char enemybarrage001hd[50]	=	"enemybarrage001.png";			//16*16
	char enemybarrage002hd[50]	=	"enemybarrage002.png";			//16*16
	char enemy002hd[50]			=	"enemy002.png";					//30*40

	//背景に関する変数
	unsigned int fuji;

	if (DxLib_Init() == -1) { return -1; }		//DXlibの呼び出し

	ChangeWindowMode(TRUE);
	SetWindowSize(960, 720);
	SetWindowPosition(0, 10);

	//自機
	Player Renko(RenkoX, RenkoY, 30, 40, 5, TRUE, renkohd);
	Barrage *RenkoBar0;
	RenkoBar0 = new Barrage[100];
	for (n = 0; n < 100; n++) {
		RenkoBar0[n] = Barrage(0, 0, 10, 30, 15, FALSE, renkobarrage001hd);
	}

	//今は出てこない敵
	/*Enemy Enemy100(420, 100, 30, 40, FALSE, enemy001hd);
	Barrage Enemy100Barrage[100];
	for (n = 0; n < 100; n++) {
		Enemy100Barrage[n] = Barrage(0, 0, 16, 16, FALSE, enemybarrage002hd, 12, 0);
	}*/

	//水色の敵
	Enemy *Enemy0;
	Enemy0 = new Enemy[50];
	for (n = 0; n < 50; n++) {
		Enemy0[n] = Enemy(0, 0, 30, 40, 0, FALSE, enemy001hd);
	}
	Barrage *Bar0;
	Bar0 = new Barrage[100];
	for (n = 0; n < 100; n++) {
		Bar0[n] = Barrage(0, 0, 10, 16, 16, FALSE, enemybarrage002hd);
	}

	//オレンジの敵
	Enemy *Enemy1;
	Enemy1 = new Enemy[50];
	for (n = 0; n < 50; n++) {
		Enemy1[n] = Enemy(0, 0, 30, 40, 0, FALSE, enemy002hd);
	}
	Barrage *Bar1;
	Bar1 = new Barrage[100];
	for (n = 0; n < 100; n++) {
		Bar1[n] = Barrage(0, 0, 10, 16, 16, FALSE, enemybarrage001hd);
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
			if (KeyBuffer[KEY_INPUT_Z] == TRUE && RenkoBar0[n].ScreenFlag == FALSE) {
				RenkoBar0[n].ScreenFlag = TRUE;
				RenkoBar0[n].Gx = Renko.Gx;
				RenkoBar0[n].Gy = Renko.Gy;
				break;
			}
		}

		for (n = 0; n < 100; n++) {
			if (RenkoBar0[n].ScreenFlag == TRUE) {
				RenkoBar0[n].Display();
				RenkoBar0[n].Gy -= 10;
				if (RenkoBar0[n].Gy < UP)RenkoBar0[n].ScreenFlag = FALSE;
			}
		}

		//敵周りの表示

		//るーぷ100~
		SetEne(Enemy0, 100, 0, 3, LEFT, 50, 60, 75, 0);
		SetBar(Bar0, 100, 1, 3, Enemy0[0].Gx, Enemy0[0].Gy, 60, 0, 0);
		SetEne(Enemy0, 110, 0, 3, LEFT, 35, 68, 82, 0);
		SetBar(Bar0, 110, 1, 3, Enemy0[1].Gx, Enemy0[1].Gy, 50, 0, 0);
		SetEne(Enemy0, 120, 0, 3, LEFT, 65, 65, 87, 0);
		SetBar(Bar0, 120, 1, 3, Enemy0[2].Gx, Enemy0[0].Gy, 80, 0, 0);
		//弾幕
		
		SetEne(Enemy0, 160, 0, 3, RIGHT - 50, 0, 120, 110, 0);
		SetBar(Bar0, 160, 1, 3, Enemy0[3].Gx, Enemy0[3].Gy, 110, 0, 0);
		SetEne(Enemy0, 170, 0, 3, RIGHT - 46, 0, 115, 118, 0);
		SetBar(Bar0, 170, 1, 3, Enemy0[4].Gx, Enemy0[4].Gy, 80, 0, 0);
		SetEne(Enemy0, 180, 0, 3, RIGHT - 55, 0, 119, 127, 0);
		SetBar(Bar0, 180, 1, 3, Enemy0[5].Gx, Enemy0[5].Gy, 70, 0, 0);
		SetEne(Enemy0, 190, 0, 3, RIGHT - 51, 0, 118, 120, 0);
		SetBar(Bar0, 190, 1, 3, Enemy0[6].Gx, Enemy0[6].Gy, 20, 0, 0);
		SetEne(Enemy0, 200, 0, 3, RIGHT - 49, 0, 116, 121, 0);
		SetBar(Bar0, 200, 1, 3, Enemy0[7].Gx, Enemy0[7].Gy, 55, 0, 0);

		SetEne(Enemy0, 350, 0, 3, LEFT + 150, 0, 85, 80, 10);
		SetBar(Bar0, 350, 1, 3, Enemy0[8].Gx, Enemy0[8].Gy, 120, 0, 0);
		SetEne(Enemy0, 355, 0, 3, LEFT + 134, 0, 67, 70, 10);
		SetBar(Bar0, 355, 1, 3, Enemy0[9].Gx, Enemy0[9].Gy, 90, 0, 0);
		SetEne(Enemy0, 360, 0, 3, LEFT + 169, 0, 79, 85, 10);
		SetBar(Bar0, 360, 1, 3, Enemy0[10].Gx, Enemy0[10].Gy, 75, 0, 0);
		SetEne(Enemy0, 365, 0, 3, LEFT + 144, 0, 87, 88, 10);
		SetBar(Bar0, 365, 1, 3, Enemy0[11].Gx, Enemy0[11].Gy, 120, 0, 0);
		SetEne(Enemy0, 370, 0, 3, LEFT + 120, 0, 59, 50, 10);
		SetBar(Bar0, 370, 1, 3, Enemy0[12].Gx, Enemy0[12].Gy, 100, 0, 0);

		//るーぷ450~
		SetEne(Enemy1, 450, 0, 2, CENTER - 100, 0, 90, 90, 50);
		SetBar(Bar1, 450, 0, 4, Enemy1[0].Gx, Enemy1[0].Gy, 0, 0, 0);
		SetEne(Enemy1, 450, 0, 2, CENTER + 100, 0, 90, 90, 50);
		SetBar(Bar1, 450, 0, 4, Enemy1[1].Gx, Enemy1[1].Gy, 0, 0, 0);
		SetEne(Enemy1, 500, 0, 2.5, CENTER, 0, 90, 90, 100);
		SetBar(Bar1, 500, 0, 4, Enemy1[2].Gx, Enemy1[2].Gy, 0, 0, 0);

		//るーぷ600~
		SetEne(Enemy0, 600, 1, 5, LEFT, 10, 5, 0, 0);
		SetEne(Enemy0, 610, 1, 5, LEFT, 150, -14, 0, 0);
		SetEne(Enemy0, 615, 1, 5, LEFT, 80, 0, 0, 0);
		SetEne(Enemy0, 622, 1, 5, LEFT, 70, 2, 0, 0);

		SetEne(Enemy0, 605, 1, -5, RIGHT, 30, 11, 0, 0);
		SetEne(Enemy0, 610, 1, -5, RIGHT, 60, 7, 0, 0);
		SetEne(Enemy0, 618, 1, -5, RIGHT, 180, -10, 0, 0);
		SetEne(Enemy0, 628, 1, -5, RIGHT, 40, 17, 0, 0);

		//るーぷ680
		SetEne(Enemy0, 680, 0, 2.5, RIGHT - 10, 0, 100, 110, 10);
		SetEne(Enemy0, 690, 0, 2.5, RIGHT, 10, 110, 105, 10);
		SetEne(Enemy0, 700, 0, 2.5, RIGHT - 40, 0, 95, 91, 15);
		SetEne(Enemy0, 710, 0, 2.5, RIGHT, 20, 115, 100, 15);

		SetEne(Enemy0, 685, 0, 2, LEFT + 50, 0, 80, 175, 0);
		SetEne(Enemy0, 695, 0, 2, LEFT + 58, 0, 81, 173, 0);
		SetEne(Enemy0, 705, 0, 2, LEFT + 40, 0, 88, 179, 0);
		SetEne(Enemy0, 715, 0, 2, LEFT + 64, 0, 71, 169, 0);

		SetEne(Enemy1, 700, 0, 2, CENTER - 120, 0, 90, 0, 50);
		SetBar(Bar1, 700, 0, 4, Enemy1[3].Gx, Enemy1[3].Gy, 0, 0, 0);
		SetEne(Enemy1, 720, 0, 3, CENTER - 160, 0, 90, 0, 50);
		SetBar(Bar1, 720, 0, 4, Enemy1[4].Gx, Enemy1[4].Gy, 0, 0, 0);
		SetEne(Enemy1, 700, 0, 2, CENTER + 120, 0, 90, 0, 50);
		SetBar(Bar1, 700, 0, 4, Enemy1[5].Gx, Enemy1[5].Gy, 0, 0, 0);
		SetEne(Enemy1, 720, 0, 3, CENTER + 160, 0, 90, 0, 50);
		SetBar(Bar1, 720, 0, 4, Enemy1[6].Gx, Enemy1[6].Gy, 0, 0, 0);

		//る-ぷ900
		SetEne(Enemy1, 900, 0, 4, CENTER, 0, 90, 90, 150);
		SetEne(Enemy1, 940, 0, 3.5, CENTER - 75, 0, 90, 90, 150);
		SetEne(Enemy1, 940, 0, 3.5, CENTER + 75, 0, 90, 90, 150);
		SetEne(Enemy1, 980, 0, 3, CENTER - 150, 0, 90, 90, 150);
		SetBar(Bar1, 980, 0, 4, Enemy1[7].Gx, Enemy1[7].Gy, 0, 0, 0);
		SetEne(Enemy1, 980, 0, 3, CENTER + 150, 0, 90, 90, 150);
		SetBar(Bar1, 980, 0, 4, Enemy1[8].Gx, Enemy1[8].Gy, 0, 0, 0);

		//敵を動かす
		for (m = 0; m < 50; m++) {
			Enemy0[m].Move();
			Enemy1[m].Move();
		}
		//敵弾幕を動かす
		for (n = 0; n < 100; n++) {
			Bar0[n].Move();
			Bar1[n].Move();
		}

		ScreenFlip();
		LoopCount++;
		if (ProcessMessage() < 0) break;
		WaitTimer(INTERVAL);
	}

	DxLib_End();
	return 0;
}

void SetEne(Enemy enemy_[],int LoopCount_,int MovePattern_,double Speed_,double Gx_,double Gy_,double A_,double B_,double C_) {
	if (LoopCount == LoopCount_) {
		for (int m = 0; m < 50; m++) {
			if (enemy_[m].ScreenFlag == FALSE) {
				enemy_[m].SetUp(LoopCount_, MovePattern_, Speed_, Gx_, Gy_, A_, B_, C_);
				break;
			}
		}
	}
}

void SetBar(Barrage barrage_[], int LoopCount_, int MovePattern_, double Speed_, double Gx_, double Gy_, double A_, double B_, double C_) {
	if (LoopCount >= LoopCount_ && LoopCount % 10 == 0) {
		for (int m = 0; m < 100; m++) {
			if (barrage_[m].ScreenFlag == FALSE) {
				barrage_[m].SetUp(LoopCount_, MovePattern_, Speed_, Gx_, Gy_, A_, B_, C_);
				break;
			}
		}
	}
}
