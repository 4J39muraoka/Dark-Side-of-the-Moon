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

	static MovableObject* object_l[MAX_OBJECT];		//�I�u�W�F�N�g�̃��X�g
	static int total_object;						//�I�u�W�F�N�g�̑���
	static int cx, cy;								//�N���b�N�������W
	static int mx, my;								//�}�E�X�̍��W
	int serial_n;


	static int RegistObj(MovableObject*);
};

