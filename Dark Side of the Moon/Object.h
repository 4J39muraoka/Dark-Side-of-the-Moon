#pragma once

#include "memory"

#define MAX_OBJECT 10

class Object {
public:

	Object();
	virtual ~Object();
	
	void SetPicture(int pict);
	void SetPosition(int x, int y);
	void SetScale(int x, int y);
	void SetExist(bool);

	static void Put();
	static void Delete();
	static void Delete(int serial);

protected:

	int posx = 0, posy = 0;	//位置
	int sx = 32, sy = 32;	//大きさ
private:
	int picture = -1;	//画像
	bool exist = 1;
	int serial_n;

	static Object* object_l[MAX_OBJECT];	//オブジェクトのリスト
	static int total_object;				//オブジェクトの総数

	void PutObject();

	static int RegistObj(Object*);
};