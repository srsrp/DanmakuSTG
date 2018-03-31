#ifndef INCLUDED_OBJECT_H_
#define INCLUDED_OBJECT_H_

class Object {
public:
	int Gx, Gy;		//ćĚŔW
	int GraphicSizeX, GraphicSizeY;
	int x, y;

	bool ScreenFlag;
	int Handle;

	Object();
	Object(int Gx_, int Gy_, int GraphicSizeX_, int GraphicSizeY_, bool ScreenFlag_, char* FileName_);
	void Display();
	//void SetXY();
};

#endif
