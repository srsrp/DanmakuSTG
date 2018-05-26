/*#ifndef INCLUDED_BARRAGE_H_
#define INCLUDED_BARRAGE_H_

#include "Player.h"
#include "Enemy.h"
#include "Constant.h"

class Barrage{
private:

	BOOL20			EneFlag;				//対応する敵のフラグ
	
	BOOL20			EneX,
					EneY;					//敵の座標
	enum BarType	Type;					//弾幕のデザイン：SetUp()で使う。列挙型
	enum BarPat		BarPattern[20];			//敵の移動パターン。列挙型でパターンわかり易く。

	INT20			LoopCountIni;			//出現ループ数
	BOOL1000		BarScreenFlag;			//画面上にいるかどうかのフラグ
	DBL1000			Speed;					//移動する速さ
	DBL1000			Gx;
	DBL1000			Gy;						//座標(左上)
	DBL20			a,
					b,
					c,
					e,
					d;						//弾幕に関するパラメータ
		
	int				Handle;					//画像ハンドル
	int				GrSizeX,
					GrSizeY;				//画像サイズ	
public:
	BOOL20			BarFlag;				//使ってるかどうかのフラグ
	
	//あいであ①
	//初期座標をセッティングして、敵と同じパターンで動かして（SF＝FALSEのまま）、
	//必要になればSF=TRUE
	//〇敵の座標を渡す必要なし。
	
	Barrage();
	Barrage(Enemy Enemy_, char* FileName_, BarType Type_, int GrSizeX_, int GrSizeY_);
	
	void BarSetUp(Enemy Enemy_);
	void BarMove(Enemy Enemy_,Player Player_);
	void BarSet(int LoopCount_, BarPat BarPattern_, double Speed_,Enemy Enemy_, double a_ = 0, double b_ = 0, double c_ = 0, double d_ = 0, double e_ = 0);
	void BarDisplay();
};

#endif*/
