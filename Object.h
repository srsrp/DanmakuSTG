#ifndef INCLUDED_OBJECT_H_
#define INCLUDED_OBJECT_H_

class Object {
private:
	int GraphicSizeX, GraphicSizeY;

protected:
	int Handle;
	int GraHandle[2];
	double Speed;

public:
	double Gx, Gy;		//ćĚŔW
	bool ScreenFlag;
	Object();
	Object(double Gx_, double Gy_, double Speed_, int GraphicSizeX_, int GraphicSizeY_, bool ScreenFlag_, char* FileName_);
	
	void Display();

};

#endif
