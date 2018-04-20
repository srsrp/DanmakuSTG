#ifndef INCLUDED_BARRAGE_H_
#define INCLUDED_BARRAGE_H_

#include "Object.h"

class Barrage :public Object {
private:

	int LoopCountIni;
	int MovePattern;	//移動パターン
	double A, B, C;		//パラメータ。必要に応じて個数追加すべし。

	double Distance;
	
public:
	
	Barrage();
	Barrage(double Gx_, double Gy_, double Speed_, int GraphSizeX_, int GraphSizeY_, bool ScreenFlag_, char* FileName_);
	
	void SetUp(int LoopCount_, int MovePattern_, double Speed_, double Gx_, double Gy_, double A_, double B_, double C_);
	void Move();

};

#endif
