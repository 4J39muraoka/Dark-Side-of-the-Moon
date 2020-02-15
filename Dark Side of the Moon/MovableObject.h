#pragma once

#include "Object.h"

class MovableObject : public Object {
public:

	MovableObject();
	~MovableObject();

	static void Drag();


protected:
private:

	static MovableObject* object_l[MAX_OBJECT];		//オブジェクトのリスト
	static int total_object;						//オブジェクトの総数
	int serial_n = -1;
	bool del;
	static int RegistObj(MovableObject*);

	int prex, prey;

	static int cx, cy;								//クリックした座標
	static int mx, my;								//マウスの座標

	bool DragObject(int, int, int, int);
};

