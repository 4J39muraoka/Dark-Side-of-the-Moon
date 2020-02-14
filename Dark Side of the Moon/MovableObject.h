#pragma once
#include "Object.h"
class MovableObject : public Object {
public:

	MovableObject();
	~MovableObject();

	void DragObject(int, int, int, int, bool);

	static void Drag();

protected:
private:
	int prex, prey;

	static MovableObject* object_l[MAX_OBJECT];		//オブジェクトのリスト
	static int total_object;						//オブジェクトの総数
	static int cx, cy;								//クリックした座標
	static int mx, my;								//マウスの座標
	int serial_n;


	static int RegistObj(MovableObject*);
};

