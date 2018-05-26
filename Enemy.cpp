#include "DxLib.h"
#include <cmath>
#include "Enemy.h"

#include "Player.h"
#include "Constant.h"

Enemy::Enemy(){}

Enemy::Enemy(char* FileName_, EneDesign EnemyDesign_, int GrSizeX_, int GrSizeY_,char* BarrageFileName_, BarDesign BarrageDesign_, int BarrageGrSizeX_, int BarrageGrSizeY_)
{
	EnemyDesign = EnemyDesign_;
	GrSizeX = GrSizeX_;
	GrSizeY = GrSizeY_;
	Handle = LoadGraph(FileName_);

	BarrageDesign = BarrageDesign_;
	BarrageGrSizeX = BarrageGrSizeX_;
	BarrageGrSizeY = BarrageGrSizeY_;
	BarrageHandle = LoadGraph(BarrageFileName_);

	for (int n = 0; n < ENE_MAX; n++) {
		Gx[n] = 0;
		Gy[n] = 0;
		Speed[n] = 0;
		LoopCountIni[n] = 0;
		A[n] = 0;
		B[n] = 0;
		C[n] = 0;
		ScreenFlag[n] = FALSE;

		BarrageUseFlag[n] = FALSE;
		a[n] = 0;
		b[n] = 0;
		c[n] = 0;
		d[n] = 0;
		e[n] = 0;

		for (int m = 0; m < BAR_MAX; m++) {
			BarrageGx[n][m] = 0;
			BarrageGy[n][m] = 0;
			BarrageScreenFlag[n][m] = FALSE;
			BarrageSpeed[n][m] = 0;
		}
	}
}

void Enemy::SetUp() {
	switch (EnemyDesign) {
	case BlueEnemy:
		Set(100, Parabola, 3.0, LEFT, 50, AimAtPlayer, 1.0, 60, 75, 20, 2, 2, 30);
		Set(110, Parabola, 3.0, LEFT, 35, AimAtPlayer, 1.0, 68, 82, 20, 2, 2, 30);
		Set(120, Parabola, 3.0, LEFT, 65, AimAtPlayer, 1.0, 65, 87, 20, 2, 2, 30);

		Set(160, Parabola, 3.0, RIGHT - 50, 0, AimAtPlayer, 1.0, 120, 110, 20, 2, 1, 30);
		Set(170, Parabola, 3.0, RIGHT - 46, 0, AimAtPlayer, 1.0, 115, 118, 20, 2, 1, 30);
		Set(180, Parabola, 3.0, RIGHT - 55, 0, AimAtPlayer, 1.0, 119, 127, 20, 2, 1, 30);

		Set(350, Parabola, 3.0, LEFT + 150, 0, AimAtPlayer, 1.0, 85, 80, 10, 2, 2, 30);
		Set(355, Parabola, 3.0, LEFT + 134, 0, AimAtPlayer, 1.0, 67, 70, 10, 2, 2, 30);
		Set(360, Parabola, 3.0, LEFT + 169, 0, AimAtPlayer, 1.0, 79, 85, 10, 2, 2, 30);
		Set(365, Parabola, 3.0, LEFT + 144, 0, AimAtPlayer, 1.0, 87, 88, 10, 2, 2, 30);
		Set(370, Parabola, 3.0, LEFT + 120, 0, AimAtPlayer, 1.0, 59, 50, 10, 2, 2, 30);

		Set(600, Linear, 3.0, LEFT, 30, TwoTimesTwo, 2.0, 0, 0, 0, 1);
		Set(610, Linear, 3.0, LEFT, 50, TwoTimesTwo, 2.0, 0, 0, 0, 1);
		Set(620, Linear, 3.0, LEFT, 70, TwoTimesTwo, 2.0, 0, 0, 0, 1);
		Set(630, Linear, 3.0, LEFT, 90, TwoTimesTwo, 2.0, 0, 0, 0, 1);
		
		Set(605, Linear, -3.0, RIGHT, 40, TwoTimesTwo, 2.0, 0, 0, 0, 1);
		Set(615, Linear, -3.0, RIGHT, 60, TwoTimesTwo, 2.0, 0, 0, 0, 1);
		Set(625, Linear, -3.0, RIGHT, 80, TwoTimesTwo, 2.0, 0, 0, 0, 1);
		Set(635, Linear, -3.0, RIGHT, 100, TwoTimesTwo, 2.0, 0, 0, 0, 1);

		Set(680, Parabola, 2.5, RIGHT - 10, UP, AimAtPlayer, 1.5, 100, 110, 10, 3, 2, 30);
		Set(690, Parabola, 2.5, RIGHT - 30, UP, AimAtPlayer, 1.5, 110, 105, 10, 3, 2, 30);//21
		Set(700, Parabola, 2.5, RIGHT - 50, UP, AimAtPlayer, 1.5,  95,  91, 15, 3, 2, 30);
		Set(710, Parabola, 2.5, RIGHT - 70, UP, AimAtPlayer, 1.5, 115, 100, 15, 3, 2, 30);

		Set(685, Parabola, 2.5, LEFT + 50, UP, AimAtPlayer, 1.5, 80, 175, 0, 3, 2, 30);
		Set(695, Parabola, 2.5, LEFT + 58, UP, AimAtPlayer, 1.5, 81, 173, 0, 3, 2, 30);
		Set(705, Parabola, 2.5, LEFT + 40, UP, AimAtPlayer, 1.5, 88, 179, 0, 3, 2, 30);
		Set(715, Parabola, 2.5, LEFT + 64, UP, AimAtPlayer, 1.5, 71, 169, 0, 3, 2, 30);
		
		break;

	case RedStar:
		
		//るーぷ450~
		Set(450, Parabola, 2.0, CENTER - 100, UP, nWayCircle, 1.5, 90, 90, 50, 8, 1, 2);
		Set(450, Parabola, 2.0, CENTER + 100, UP, nWayCircle, 1.5, 90, 90, 50, 8, 1, 2);
		Set(500, Parabola, 2.0, CENTER		, UP, nWayCircle, 1.5, 90, 90, 50, 8, 1, 2);

		Set(700, Parabola, 2.0, CENTER - 120, UP, nWayCircle, 2.0, 90, 0, 50, 12, 1, 2);
		Set(700, Parabola, 2.0, CENTER + 120, UP, nWayCircle, 2.0, 90, 0, 50, 12, 1, 2);
		Set(720, Parabola, 3.0, CENTER - 160, UP, nWayCircle, 2.0, 90, 0, 50, 12, 1, 2);
		Set(720, Parabola, 3.0, CENTER + 160, UP, nWayCircle, 2.0, 90, 0, 50, 12, 1, 2);

		Set(900, Parabola, 4.0, CENTER		, UP, nWayCircle, 2.0, 90, 90, 150, 15, 1, 4.0);
		Set(940, Parabola, 3.5, CENTER -  75, UP, nWayCircle, 2.0, 90, 90, 150, 15, 1, 3.0);
		Set(940, Parabola, 3.5, CENTER +  75, UP, nWayCircle, 2.0, 90, 90, 150, 15, 1, 3.0);
		Set(980, Parabola, 3.0, CENTER - 150, UP, nWayCircle, 1.5, 90, 90, 150, 15, 1, 4.0);
		Set(980, Parabola, 3.0, CENTER + 150, UP, nWayCircle, 1.5, 90, 90, 150, 15, 1, 4.0);
		
		break;
	}
}

void Enemy::Set(int LoopCount_, EnePattern EnemyPattern_, double Speed_, double Gx_, double Gy_, BarPattern BarPattern_, double BarrageSpeed_, double A_, double B_, double C_, double a_, double b_, double c_, double d_, double e_) {
	if (LoopCount == LoopCount_) {
		for (int n = 0; n < ENE_MAX; n++) {
			if (ScreenFlag[n] == FALSE && BarrageUseFlag[n] == FALSE) {
				//パラメータをセット
				ScreenFlag[n] = TRUE;
				LoopCountIni[n] = LoopCount_;
				EnemyPattern[n] = EnemyPattern_;
				Speed[n] = Speed_;
				Gx[n] = Gx_;
				Gy[n] = Gy_;
				A[n] = A_;
				B[n] = B_;
				C[n] = C_;

				BarrageUseFlag[n] = TRUE;
				BarragePattern[n] = BarPattern_;
				a[n] = a_;
				b[n] = b_;
				c[n] = c_;
				d[n] = d_;
				e[n] = e_;
				for (int m = 0; m < BAR_MAX; m++) {
					BarrageSpeed[n][m] = BarrageSpeed_;
				}

				break;
			}
		}
	}
}

void Enemy::EnemyDisplay() {
	switch (EnemyDesign) {
	case RedStar:
		for (int n = 0; n < ENE_MAX; n++) {
			double Time = LoopCount - LoopCountIni[n];
			if (ScreenFlag[n] == TRUE) {
				DrawRotaGraph(Gx[n], Gy[n], 32.0 / 256.0, 2 * PI / 180 * DegToRad Time * 200, Handle, TRUE);
			}
		}
		break;

	default:
		for (int n = 0; n < ENE_MAX; n++) {
			if (ScreenFlag[n] == TRUE)DrawRotaGraph(Gx[n], Gy[n], 1, 0, Handle, TRUE);
		}
		break;
	}
}
void Enemy::BarrageDisplay() {
	for (int n = 0; n < ENE_MAX; n++) {
		switch (BarrageDesign) {
		case Bullet:
			for (int m = 0; m < BAR_MAX; m++) {
				if (BarrageScreenFlag[n][m] == TRUE)DrawRotaGraph(BarrageGx[n][m] , BarrageGy[n][m], 1.0, 2 * PI / a[n] * m + DegToRad 135, BarrageHandle, TRUE);
			}
			break;
		case Circle:
			for (int m = 0; m < BAR_MAX; m++) {
				if (BarrageScreenFlag[n][m] == TRUE)DrawExtendGraph(BarrageGx[n][m], BarrageGy[n][m], BarrageGx[n][m] + BarrageGrSizeX + 1, BarrageGy[n][m] + BarrageGrSizeY + 1, BarrageHandle, TRUE);
			}
			break;
		}
	}
}

void Enemy::EnemyMove() {
	EnemyDisplay();
	for (int n = 0; n < ENE_MAX; n++) {	
		double Time = LoopCount - LoopCountIni[n];
		switch (EnemyPattern[n]) {
		case Parabola://減速して接近、静止後、加速して離脱
					  /*	A	:行きの角度
							B	:帰りの角度
							C	:停止ループ数		*/
			if (Time < 150) {
				Gx[n] += Speed[n] * cos(PI / 180 * A[n]) * (1 - Time / 150);
				Gy[n] += Speed[n] * sin(PI / 180 * A[n]) * (1 - Time / 150);
			}
			if (Time >= 150 + C[n]) {
				Gx[n] += Speed[n] * cos(PI / 180 * B[n]) * (1 - Time / 150);
				Gy[n] += Speed[n] * sin(PI / 180 * B[n]) * (1 - Time / 150);
			}
			break;

		case Linear://等速運動
					  /*	A	:x軸からの角度
													*/
			Gx[n] += Speed[n] * cos(PI / 180 * A[n]);
			Gy[n] += Speed[n] * sin(PI / 180 * A[n]);
			break;
		}
		if (Gx[n] < LEFT - 50 || Gx[n] > RIGHT + 50 || Gy[n] < UP - 50 || Gy[n] > DOWN + 50)ScreenFlag[n] = FALSE;
	}
}
void Enemy::BarrageMove(Player Player_) {
	BarrageDisplay();
	for (int n = 0; n < ENE_MAX; n++) {
		double Time = LoopCount - LoopCountIni[n];

		switch (BarragePattern[n]) {

		case nWayCircle:	//減速して接近、静止(後、加速して離脱)
							//静止中にm-Way弾を放つ
							//	a	:Way数
							//	b	:弾列数

			for (int m = 0; m < (int)a[n] * (int)b[n]; m++) {
				if (Time == 150 + m * 3 && ScreenFlag[n] == TRUE) {
					BarrageScreenFlag[n][m] = TRUE;
					BarrageGx[n][m] = Gx[n];
					BarrageGy[n][m] = Gy[n];
				}
				if (Time > 150 && BarrageUseFlag[n] == TRUE) {
					BarrageGx[n][m] += BarrageSpeed[n][m] * cos(2 * PI / (int)a[n] * m + DegToRad 45);
					BarrageGy[n][m] += BarrageSpeed[n][m] * sin(2 * PI / (int)a[n] * m + DegToRad 45);
				}
			}
			break;

		case AimAtPlayer:	//自機狙いm-Way
							//	a	:Way数	2or3or4
							//	b	:弾列数
							//	c	:列間の角度
							//	d	:自機との角度

			for (int m = 0; m < a[n] * b[n]; m++) {
				if (Time == 150) {
					d[n] = atan2((Player_.Gy - Gy[n]), (Player_.Gx - Gx[n]));
				}
				if (Time == 150 + m * 5 && ScreenFlag[n] == TRUE) {
					BarrageScreenFlag[n][m] = TRUE;
					BarrageGx[n][m] = Gx[n] + 0.5*(GrSizeX - BarrageGrSizeX);
					BarrageGy[n][m] = Gy[n] + 0.5*(GrSizeY - BarrageGrSizeY);

				}
				if (Time > 150) {
					BarrageGx[n][m] += BarrageSpeed[n][m] * cos(d[n] + e[n]);
					BarrageGy[n][m] += BarrageSpeed[n][m] * sin(d[n] + e[n]);
					switch ((int)a[n]) {
					case 2:
						switch (m % 2) {
						case 0:
							BarrageGx[n][m] += BarrageSpeed[n][m] * cos(d[n] - DegToRad c[n] / 2);
							BarrageGy[n][m] += BarrageSpeed[n][m] * sin(d[n] - DegToRad c[n] / 2);
							break;
						case 1:
							BarrageGx[n][m] += BarrageSpeed[n][m] * cos(d[n] + DegToRad c[n] / 2);
							BarrageGy[n][m] += BarrageSpeed[n][m] * sin(d[n] + DegToRad c[n] / 2);
							break;
						}
						break;
					case 3:
						switch (m % 3) {
						case 0:	//m=0,3,...
							BarrageGx[n][m] += BarrageSpeed[n][m] * cos(d[n]);
							BarrageGy[n][m] += BarrageSpeed[n][m] * sin(d[n]);
							break;
						case 1:	//m=1
							BarrageGx[n][m] += BarrageSpeed[n][m] * cos(d[n] - DegToRad c[n]);
							BarrageGy[n][m] += BarrageSpeed[n][m] * sin(d[n] - DegToRad c[n]);
							break;
						case 2: //m=2
							BarrageGx[n][m] += BarrageSpeed[n][m] * cos(d[n] + DegToRad c[n]);
							BarrageGy[n][m] += BarrageSpeed[n][m] * sin(d[n] + DegToRad c[n]);
							break;
						}
						break;
					case 4:
						switch (m % 4) {
						case 0:
							BarrageGx[n][m] += BarrageSpeed[n][m] * cos(d[n] - DegToRad 3 * c[n] / 2);
							BarrageGy[n][m] += BarrageSpeed[n][m] * sin(d[n] - DegToRad 3 * c[n] / 2);
							break;
						case 1:
							BarrageGx[n][m] += BarrageSpeed[n][m] * cos(d[n] - DegToRad c[n] / 2);
							BarrageGy[n][m] += BarrageSpeed[n][m] * sin(d[n] - DegToRad c[n] / 2);
							break;
						case 2:
							BarrageGx[n][m] += BarrageSpeed[n][m] * cos(d[n] + DegToRad c[n] / 2);
							BarrageGy[n][m] += BarrageSpeed[n][m] * sin(d[n] + DegToRad c[n] / 2);
							break;
						case 3:
							BarrageGx[n][m] += BarrageSpeed[n][m] * cos(d[n] + DegToRad 3 * c[n] / 2);
							BarrageGy[n][m] += BarrageSpeed[n][m] * sin(d[n] + DegToRad 3 * c[n] / 2);
							break;
						}
						break;
					}
				}
			}
			break;

		case TwoTimesTwo:		//2-Wayを2回
								//a	:中心軸の角度

			for (int m = 0; m < 2; m++) {
				if (Time == 40 + m * 20) {
					BarrageScreenFlag[n][2 * m] = TRUE;
					BarrageGx[n][2 * m] = Gx[n] + 0.5*(GrSizeX - BarrageGrSizeX);
					BarrageGy[n][2 * m] = Gy[n] + 0.5*(GrSizeY - BarrageGrSizeY);
					BarrageScreenFlag[n][2 * m + 1] = TRUE;
					BarrageGx[n][2 * m + 1] = Gx[n] + 0.5*(GrSizeX - BarrageGrSizeX);
					BarrageGy[n][2 * m + 1] = Gy[n] + 0.5*(GrSizeY - BarrageGrSizeY);
				}
				if (Time > 40 + m * 20) {
					BarrageGx[n][2 * m] += BarrageSpeed[n][m] * cos(DegToRad(90 + a[n] + 20));
					BarrageGy[n][2 * m] += BarrageSpeed[n][m] * sin(DegToRad(90 + a[n] + 20));
					BarrageGx[n][2 * m + 1] += BarrageSpeed[n][2 * m + 1] * cos(DegToRad(90 + a[n] - 20));
					BarrageGy[n][2 * m + 1] += BarrageSpeed[n][2 * m + 1] * sin(DegToRad(90 + a[n] - 20));
				}
			}
			break;

		case Sample:
			for (int m = 0; m < 5; m++) {
				if (Time == 10 * (m + 1)) {
					BarrageScreenFlag[n][m] = TRUE;
					BarrageGx[n][m] = Gx[n];
					BarrageGy[n][m] = Gy[n];
				}
				if (Time > 10 * (m + 1)) {
					BarrageGy[n][m] += BarrageSpeed[n][m];
				}
			}
			break;
		}

		/*範囲外に行ったらBarrageScreenFlagをFALSEにする*/
		for (int m = 0; m < BAR_MAX; m++) {
			if (BarrageGx[n][m] < LEFT - 50 || BarrageGx[n][m] > RIGHT + 50 || BarrageGy[n][m] < UP - 50 || BarrageGy[n][m] > DOWN + 50) {
				BarrageScreenFlag[n][m] = FALSE;
			}
		}

		/*全部の弾FlagがFALSEならBarrageUseFlagをFALSEにする*/
		int l;
		for (l = 0; l < BAR_MAX; l++) {
			if (BarrageScreenFlag[n][l] != FALSE) {
				break;
			}
		}
		if (l == BAR_MAX) {
			BarrageUseFlag[n] = FALSE;
		}
		else {
			BarrageUseFlag[n] = TRUE;
		}
	}
}

void Enemy::Move(Player Player_) {
	EnemyMove();
	BarrageMove(Player_);
}

void Enemy::KillCheck(Player *Player_) {
	for (int n = 0; n < ENE_MAX; n++) {
		for (int m = 0; m < BAR_MAX; m++) {
			BarrageDistance[n][m] = sqrt(pow(((Player_->Gx) - (BarrageGx[n][m])), 2) + pow(((Player_->Gy) - (BarrageGy[n][m])), 2));
			if (BarrageDistance[n][m] < Player_->Radius + BarrageRadius) {
				Player_->ScreenFlag = FALSE;
			}
		}
	}
}
