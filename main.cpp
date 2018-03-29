#include <math.h>
#include "DxLib.h"
#include "Constant.h"
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "Barrage.h"

//��ʂ̕ϐ�
int LoopCount = 0;
int n, m;
char KeyBuffer[256];

//�@�q�̏����ʒu
int RenkoX = (LEFT + RIGHT) / 2;
int RenkoY = (UP + DOWN) / 2 + 200;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�摜Handle
	char renkohd[50] = "renko.png";								//30*40
	char renkobarrage001hd[50] = "renkobarrage001.png";			//30*15
	char enemy001hd[50] = "enemy001.png";						//30*40
	char enemybarrage001hd[50] = "enemybarrage001.png";			//16*16

	//�w�i�Ɋւ���ϐ�
	unsigned int fuji;

	if (DxLib_Init() == -1) { return -1; }		//DXlib�̌Ăяo��

	ChangeWindowMode(TRUE);
	SetWindowSize(960, 720);
	SetWindowPosition(0, 10);

	//���@
	Player Renko(RenkoX, RenkoY, 30, 40, TRUE, renkohd, 5);

	Barrage RenkoBarrage[100];
	for (n = 0; n < 100; n++) {
		RenkoBarrage[n] = Barrage(0, 0, 30, 15, FALSE, renkobarrage001hd, 12, 0);
	}

	//100���[�v�ŏo�Ă���G
	Enemy Enemy001(420, 100, 30, 40, FALSE, enemy001hd, 5);

	Barrage Enemy001Barrage[100];
	for (n = 0; n < 100; n++) {
		Enemy001Barrage[n] = Barrage(0, 0, 16, 16, FALSE, enemybarrage001hd, 12, 0);
	}

	//�w�i
	fuji = GetColor(187, 188, 222);

	SetDrawScreen(DX_SCREEN_BACK);

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		ClearDrawScreen();

		DrawBox(LEFT, UP, RIGHT + 31, DOWN + 41, fuji, TRUE);

		GetHitKeyStateAll(KeyBuffer);

		//�@�q����̕\��
		//�@�q�̈ړ�

		if (Renko.ScreenFlag == FALSE)Renko.Display();
		Renko.Move();

		//�@�q�̒e���̈ړ�
		for (n = 0; n < 30; n++) {
			if (KeyBuffer[KEY_INPUT_Z] && RenkoBarrage[n].ScreenFlag == FALSE) {
				RenkoBarrage[n].Gx = Renko.Gx;				//���S�Ƃ����
				RenkoBarrage[n].Gy = Renko.Gy;				//����
				RenkoBarrage[n].ScreenFlag = TRUE;
				break;
			}
		}

		for (n = 0; n < 30; n++) {
			if (RenkoBarrage[n].ScreenFlag == TRUE) {
				RenkoBarrage[n].Display();
				RenkoBarrage[n].Move(0, RenkoBarrage[n].RunSpeed);
				if (RenkoBarrage[n].Gy < UP)RenkoBarrage[n].ScreenFlag = FALSE;
			}
		}

		//�G����̕\��
		//LoopCount=101�ōŏ��̓G�o��

		if (LoopCount > 100)Enemy001.ScreenFlag = TRUE;

		if (Enemy001.ScreenFlag == TRUE) {
			Enemy001.Display();

			//CENTER�܂ŉE����ړ����Ă���
			if (Enemy001.Gx > CENTER)Enemy001.Move(3, 3);
			//�e���������Ă���ԐÎ~
			if (Enemy001Barrage[24].ScreenFlag == TRUE) {
				Enemy001.Move(3, 3);
			}
			/*
			//�����蔻��
			for (n = 0; n < 100; n++) {
				RenkoBarrage[n].Distance = sqrt((RenkoBarrage[n].x - Enemy001.x)*(RenkoBarrage[n].x - Enemy001.x) + (RenkoBarrage[n].y - Enemy001.y)*(RenkoBarrage[n].y - Enemy001.y));
				if (RenkoBarrage[n].Distance <= 10) {
					Enemy001.ScreenFlag = FALSE;
				}

			}
			*/
		}

		//CENTER�܂ŗ�����e��������
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

		//�@�q�̓����蔻��
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