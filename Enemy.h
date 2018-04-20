#ifndef INCLUDED_ENEMY_H_
#define INCLUDED_ENEMY_H_

#include "Object.h" 

class Enemy :public Object {
private:

	int MovePattern;			//敵の移動パターン
	int LoopCountIni;			//出現ループ数
	double A, B, C;				//移動に関するパラメータ

public:

	//コンストラクタ
	Enemy();
	Enemy(double Gx_, double Gy_, double Speed_, int GraphSizeX_, int GraphSizeY_, bool ScreenFlag_, char* FileName_);

	//移動に関するメソッド
	void SetUp(int LoopCount_, int MovePattern_, double Speed_, double x_, double y_, double A_, double B_, double C_);
	void Move();									//ループごとに呼び出し。SetUp関数に従って移動。

};

#endif
