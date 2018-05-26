#ifndef INCLUDED_ENEMY_H_
#define INCLUDED_ENEMY_H_

#include "Player.h"
#include "Constant.h"

class Enemy{
	/*
	オブジェクト宣言時に敵の形、弾幕の形を与える。
	Setで両方のデータを設定。
	*/
private:
	/*共通*/
	INT20			LoopCountIni;			//出現ループ数
	void Set(int LoopCount_, EnePattern EnemyPatter_, double Speed_, double Gx_, double Gy_, BarPattern BarragePattern_, double BarrageSpeed_, double A_ = 0, double B_ = 0, double C_ = 0, double a_ = 0, double b_ = 0, double c_ = 0, double d_ = 0, double e_ = 0);
	
	/*敵*/	
	enum EneDesign	EnemyDesign;			//デザイン
	enum EnePattern	EnemyPattern[ENE_MAX];	//移動パターン

	DBL20			Speed;					//速さ
	
	DBL20			A,
					B,
					C;						//パラメータ

	int				Handle;					//画像ハンドル
	int				GrSizeX,
					GrSizeY;				//画像サイズ
	
	
	void			EnemyDisplay();			//表示関数
	void			EnemyMove();

	/*弾幕*/
	enum BarDesign	BarrageDesign;			//デザイン
	enum BarPattern	BarragePattern[20];		//移動パターン

	BOOL20			BarrageUseFlag;			//弾幕配列を使っているかのフラグ

	BOOL1000		BarrageScreenFlag;		//画面上にいるかのフラグ
	DBL1000			BarrageSpeed;			//速さ
	DBL1000			BarrageGx;
	DBL1000			BarrageGy;				//座標(左上)
	DBL1000			BarrageDistance;		//当たり判定用
	DBL20			a,
					b,
					c,
					e,
					d;						//パラメータ

	int				BarrageHandle;			//画像ハンドル
	int				BarrageGrSizeX,
					BarrageGrSizeY;			//画像サイズ


	void			BarrageMove(Player Player_);
	void			BarrageDisplay();		//表示関数
public:
	DBL20			Gx,
					Gy;						//座標
	BOOL20			ScreenFlag;				//画面上にいるかのフラグ
	double			EnemyRadius = 15.0;		//敵の当たり判定半径
	double			BarrageRadius = 5.0;	//弾幕の当たり判定半径
	//コンストラクタ
	Enemy();
	Enemy(char* FileName_, EneDesign EnemyDesign_, int SizeX_, int SizeY_, char* BarFileName_, BarDesign BarrageDesign_, int BarSizeX_, int BarSizeY_);

	//移動に関するメソッド
	void SetUp();
	void Move(Player Player_);
	void KillCheck(Player *Player_);
};

#endif
