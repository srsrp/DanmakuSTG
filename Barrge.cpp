/*#include "DxLib.h"
#include "Constant.h"
#include "Player.h"
#include "Enemy.h"
#include "Barrage.h"
#include <iostream>
#include <cmath>

Barrage::Barrage() {}

Barrage::Barrage(Enemy Enemy_, char* FileName_, BarType Type_, int GrSizeX_, int GrSizeY_) {
	Type = Type_;
	GrSizeX = GrSizeX_;
	GrSizeY = GrSizeY_;
	Handle = LoadGraph(FileName_);
	for (int m = 0; m < ENE_MAX; m++) {
		EneFlag[m] = Enemy_.ScreenFlag[m];
		BarFlag[m] = FALSE;
		LoopCountIni[m] = 0;
		a[m] = 0;
		b[m] = 0;
		c[m] = 0;
		d[m] = 0;
		e[m] = 0;

		for (int n = 0; n < BAR_MAX; n++) {
			BarScreenFlag[m][n] = FALSE;
			Speed[m][n] = 0;
		}
	}
}

void Barrage::BarSetUp(Enemy Enemy_) {
	switch (Type) {
	case RenkoBar:
		break;
	case RedCircle://BlueCirnoに対応

		break;

	case Zayaku://OrangeCirnoに対応
		BarSet(450, nWayCircle, 1.5, 5, 2);
		BarSet(450, nWayCircle, 1.5, 5, 2);
		BarSet(500, nWayCircle, 1.5, 5, 2);

		BarSet(700, nWayCircle, 2, 3, 2);
		BarSet(700, nWayCircle, 2, 3, 2);
		BarSet(720, nWayCircle, 1.5, 5, 2);
		BarSet(720, nWayCircle, 1.5, 5, 2);

		BarSet(900, nWayCircle, 2, 4, 4);
		BarSet(940, nWayCircle, 2, 4, 3);
		BarSet(940, nWayCircle, 2, 6, 3);
		BarSet(980, nWayCircle, 2, 3, 4);
		BarSet(980, nWayCircle, 2, 3, 4);
		break;
	}
}

void Barrage::BarSet(int LoopCount_, BarPat BarPattern_, double Speed_,Enemy Enemy_, double a_, double b_, double c_, double d_, double e_) {

	if (LoopCount == LoopCount_ + 1) {
		for (int m = 0; m < ENE_MAX; m++) {
			if (Enemy_.ScreenFlag[m] == TRUE && BarFlag[m] == FALSE) {
				BarFlag[m] = TRUE;
				LoopCountIni[m] = LoopCount_;
				BarPattern[m] = BarPattern_;
				switch (BarPattern[m]) {

				default:
					a[m] = a_;
					b[m] = b_;
					c[m] = c_;
					d[m] = d_;
					e[m] = e_;
					for (int n = 0; n < BAR_MAX; n++) {
						Speed[m][n] = Speed_;
					}
				}
				break;
			}
		}

	}
}


//Move関数
//	①敵オブジェクトのScreenFlagと座標の状態を取得する
//	②パターンにしたがって各弾幕を移動する


void Barrage::BarMove(Enemy Enemy_,Player Player_) {
	
	BarDisplay();

	for (int m = 0; m < ENE_MAX; m++) {

		double Time = LoopCount - LoopCountIni[m];

		switch (BarPattern[m]) {

		case nWayCircle:	//減速して接近、静止(後、加速して離脱)
				//静止中にn-Way弾を放つ
				//	a	:Way数
				//	b	:弾列数
											
			for (int n = 0; n < a[m] * b[m]; n++) {
				if (Time == 150 + n * 3) {
					BarScreenFlag[m][n] = TRUE;
					Gx[m][n] = Enemy_.Gx[m];
					Gy[m][n] = Enemy_.Gy[m];
				}
				if (Time > 150) {
					Gx[m][n] += Speed[m][n] * cos(2 * PI / a[m] * n + DegToRad 45);
					Gy[m][n] += Speed[m][n] * sin(2 * PI / a[m] * n + DegToRad 45);
				}
			}
			break;

		case AimAtPlayer:	//自機狙いn-Way
				
				//Player_.Gx[m]
				//Player_.Gy[m]
				//a	:Way数	2or3or4
			//	b	:弾列数
			//	c	:列間の角度
			//	d	:自機との角度
				
			for (int n = 0; n < a[m] * b[m]; n++) {
				if (Time == 150) {
					d[m] = atan2((Player_.Gy - Enemy_.Gy[m]), (Player_.Gx - Enemy_.Gx[m]));
				}
				if (Time == 150 + n * 5) {
					Gx[m][n] = Enemy_.Gx[m];
					Gy[m][n] = Enemy_.Gy[m];
					BarScreenFlag[m][n] = TRUE;
				}
				if (Time > 150) {
					Gx[m][n] += Speed[m][n] * cos(d[m] + e[m]);
					Gy[m][n] += Speed[m][n] * sin(d[m] + e[m]);
					switch ((int)a[m]) {
					case 2:
						switch (n % 2) {
						case 0:
							Gx[m][n] += Speed[m][n] * cos(d[m] - DegToRad c[m] / 2);
							Gy[m][n] += Speed[m][n] * sin(d[m] - DegToRad c[m] / 2);
							break;
						case 1:
							Gx[m][n] += Speed[m][n] * cos(d[m] + DegToRad c[m] / 2);
							Gy[m][n] += Speed[m][n] * sin(d[m] + DegToRad c[m] / 2);
							break;
						}
						break;
					case 3:
						switch (n % 3) {
						case 0:	//n=0,3,...
							Gx[m][n] += Speed[m][n] * cos(d[m]);
							Gy[m][n] += Speed[m][n] * sin(d[m]);
							break;
						case 1:	//n=1
							Gx[m][n] += Speed[m][n] * cos(d[m] - DegToRad c[m]);
							Gy[m][n] += Speed[m][n] * sin(d[m] - DegToRad c[m]);
							break;
						case 2: //n=2
							Gx[m][n] += Speed[m][n] * cos(d[m] + DegToRad c[m]);
							Gy[m][n] += Speed[m][n] * sin(d[m] + DegToRad c[m]);
							break;
						}
						break;
					case 4:
						switch (n % 4) {
						case 0:
							Gx[m][n] += Speed[m][n] * cos(d[m] - DegToRad 3 * c[m] / 2);
							Gy[m][n] += Speed[m][n] * sin(d[m] - DegToRad 3 * c[m] / 2);
							break;
						case 1:
							Gx[m][n] += Speed[m][n] * cos(d[m] - DegToRad c[m] / 2);
							Gy[m][n] += Speed[m][n] * sin(d[m] - DegToRad c[m] / 2);
							break;
						case 2:
							Gx[m][n] += Speed[m][n] * cos(d[m] + DegToRad c[m] / 2);
							Gy[m][n] += Speed[m][n] * sin(d[m] + DegToRad c[m] / 2);
							break;
						case 3:
							Gx[m][n] += Speed[m][n] * cos(d[m] + DegToRad 3 * c[m] / 2);
							Gy[m][n] += Speed[m][n] * sin(d[m] + DegToRad 3 * c[m] / 2);
							break;
						}
						break;
					}
				}
			}
			break;

		case TwoTimesTwo:		//2-Wayを2回
				
				//a	:中心軸の角度
				
			for (int n = 0; n < 2; n++) {
				if (Time == 10 + n * 30) {
					BarScreenFlag[m][2 * n] = TRUE;
					Gx[m][2 * n] = Enemy_.Gx[m];
					Gy[m][2 * n] = Enemy_.Gy[m];
					BarScreenFlag[m][2 * n + 1] = TRUE;
					Gx[m][2 * n + 1] = Enemy_.Gx[m];
					Gy[m][2 * n + 1] = Enemy_.Gy[m];
				}
				if (Time > 10 + n * 30) {
					Gx[m][2 * n] += Speed[m][n] * cos(DegToRad(90 + a[m] + 30));
					Gy[m][2 * n] += Speed[m][n] * sin(DegToRad(90 + a[m] + 30));
					Gx[m][2 * n + 1] += Speed[m][2 * n + 1] * cos(DegToRad(90 + a[m] - 30));
					Gy[m][2 * n + 1] += Speed[m][2 * n + 1] * sin(DegToRad(90 + a[m] - 30));
				}
			}
			break;
		}
		for (int n = 0; n < BAR_MAX; n++) {
			if (Gx[m][n] < LEFT - 50 || Gx[m][n] > RIGHT + 50 || Gy[m][n] < UP - 50 || Gy[m][n] > DOWN + 50) {
				BarScreenFlag[m][n] = FALSE;
			}
		}
		if (Enemy_.ScreenFlag[m] == FALSE) {
			BarFlag[m] = FALSE;
		}
	}
}
void Barrage::BarDisplay() {
	for (int m = 0; m < ENE_MAX; m++) {
		switch (Type) {
		case Zayaku:
			for (int n = 0; n < BAR_MAX; n++) {
				if (BarScreenFlag[m][n] == TRUE)DrawRotaGraph(Gx[m][n], Gy[m][n], 1.0, 2 * PI / a[m] * n + DegToRad 135, Handle, TRUE);
			}
			break;
		case RedCircle:
			for (int n = 0; n < BAR_MAX; n++) {
				if (BarScreenFlag[m][n] == TRUE)DrawGraph(Gx[m][n], Gy[m][n], Handle, TRUE);
			}
			break;
		}
	}
}*/
