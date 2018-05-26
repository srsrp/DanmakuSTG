#include <math.h>
#include "DxLib.h"
#include "Constant.h"
//#include "Object.h"
#include "Player.h"
#include "Shoot.h"
#include "Enemy.h"
//#include "Barrage.h"

//一般の変数
int LoopCount = 0;
int n = 0;
int m = 0;
int l = 0;
char KeyBuffer[256];

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//画像Handle
	char RenkoGraph[50] =				"RenkoGraph.png";					//30*40*3
	char RenkoShoot001Graph[50] =		"Laser.png";						//64*256 as 8*32

	char RedStarHandle[50] =			"RedStar.png";						//256*256 as 32*32
	char BlueEnemyHandle[50] =			"BlueEnemy.png";					//32*32
	char RedCircleHandle[50] =			"RedCircle.png";					//256*256 as 16*16
	char RedBullet[50] =				"RedBullet.png";					//10*15

	//背景に関する変数
	unsigned int fuji;

	if (DxLib_Init() == -1) { return -1; }		//DXlibの呼び出し

	ChangeWindowMode(TRUE);
	SetWindowSize(960, 720);
	SetWindowPosition(0, 10);

	/*各オブジェクトの作成*/
	Player Renko(RenkoGraph, UsamiRenko, 30, 40);											//自機
	Shoot RenkoS1(&Renko, RenkoShoot001Graph, First, 10, 8, 32);							//自機ショット1

	Enemy BlueEnemy(BlueEnemyHandle, BlueEnemy, 32, 32, RedCircleHandle, Circle, 16, 16);	//青い丸敵＋赤丸弾幕
	Enemy RedStar(RedStarHandle, RedStar, 32, 32, RedBullet, Bullet, 10, 15);				//四芒星＋赤い弾丸

	DrawString(0, 0, "DEBUG MODE : Press 'D'", GetColor(255, 255, 255));
	DrawString(0, 20, "GAME MODE  : Press 'G'", GetColor(255, 255, 255));
	WaitKey();
	if (CheckHitKey(KEY_INPUT_D) == TRUE) {
		/*デバッグモード*/
		while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
			ClearDrawScreen();
			GetHitKeyStateAll(KeyBuffer);

			ScreenFlip();
			LoopCount++;
			if (ProcessMessage() < 0) break;
			WaitTimer(INTERVAL);
		}

	}
	if (CheckHitKey(KEY_INPUT_G) == TRUE) {
		/*ゲームモード*/
		/*背景*/
		fuji = GetColor(187, 188, 222);

		SetDrawScreen(DX_SCREEN_BACK);

		while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

			ClearDrawScreen();
			DrawBox(LEFT, UP, RIGHT + 31, DOWN + 41, fuji, TRUE);
			GetHitKeyStateAll(KeyBuffer);

			/*自機*/
			Renko.Move();

			RenkoS1.SetUp(&Renko);
			RenkoS1.Move(&Renko);

			RenkoS1.KillCheck(&BlueEnemy);
			RenkoS1.KillCheck(&RedStar);
			//敵
			BlueEnemy.SetUp();
			BlueEnemy.Move(Renko);
			BlueEnemy.KillCheck(&Renko);

			RedStar.SetUp();
			RedStar.Move(Renko);
			RedStar.KillCheck(&Renko);

			ScreenFlip();
			LoopCount++;
			if (ProcessMessage() < 0) break;
			WaitTimer(INTERVAL);
		}
	}
	DxLib_End();
	return 0;
}
