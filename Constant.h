#ifndef INCLUDED_CONSTANT_H_
#define INCLUDED_CONSTANT_H_

#define INTERVAL					20
#define HIGH						6
#define LOW							3

#define LEFT						20
#define UP							20
#define RIGHT						390
#define DOWN						420
#define CENTER						(LEFT+RIGHT)/2

#define RenkoX						(LEFT + RIGHT) / 2
#define RenkoY						(UP + DOWN) / 2 + 200

#define PI							3.1415926535							
#define DegToRad					PI / 180 *

#define ENE_MAX						20
#define BAR_MAX						50

extern int LoopCount;

typedef int		INT20[ENE_MAX];
typedef double	DBL20[ENE_MAX];
typedef bool	BOOL20[ENE_MAX];

typedef int		INT50[50];
typedef double	DBL50[50];
typedef bool	BOOL50[50];

typedef int		INT1000[ENE_MAX][BAR_MAX];
typedef double	DBL1000[ENE_MAX][BAR_MAX];
typedef bool	BOOL1000[ENE_MAX][BAR_MAX];

enum PlayerType {//自機のデザイン
	UsamiRenko,				//宇佐見蓮子
};

enum ShootPat {//ショットのパターン
	First,					//2Way
	Second,					//3way
	Third					//4Way
};

enum EneDesign {
	BlueEnemy,				//青丸
	RedStar				//赤星
	
};

enum EnePattern {
	Parabola,				//接近して、離脱
	Linear				//等速直線運動
};

enum BarDesign {
	RenkoBar,				//自機
	Circle,					//円
	Bullet
};
enum BarPattern {
	nWayCircle,				//n-Wayの円弾
	AimAtPlayer,			//自機狙いn弾(n=2,3,4)
	TwoTimesTwo,			//2Wayを3回

	Sample
};
#endif
