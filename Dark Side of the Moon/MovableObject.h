#pragma once

#include "Object.h"

class MovableObject : public Object {
public:

	MovableObject();
	~MovableObject();

	static void Drag();


protected:
private:

	static MovableObject* object_l[MAX_OBJECT];		//�I�u�W�F�N�g�̃��X�g
	static int total_object;						//�I�u�W�F�N�g�̑���
	int serial_n = -1;
	bool del;
	static int RegistObj(MovableObject*);

	int prex, prey;

	static int cx, cy;								//�N���b�N�������W
	static int mx, my;								//�}�E�X�̍��W

	bool DragObject(int, int, int, int);
};

