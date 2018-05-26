#ifndef INCLUDED_PLAYER_H_
#define INCLUDED_PLAYER_H_

extern char KeyBuffer[256];

class Player {

private:
	enum PlayerType Type;				//自機のタイプ
	double			MoveSpeed;			//自機の速さ
	int				Handle;				//ロード用のハンドル
	int				GraHandle[3];		//分割後の画像用のハンドル
public:
	int				SizeX, 
					SizeY;				//分割後の画像サイズ
	double			Gx,
					Gy;					//座標
	bool			ScreenFlag;			//画面上にいるかどうかのフラグ
	double			Radius = 5.0;		//当たり判定用の自機半径

	Player();
	Player(char* FileName_, PlayerType Type_, int SizeX_, int SizeY_);

	void Move();
	void Display();
};

#endif
