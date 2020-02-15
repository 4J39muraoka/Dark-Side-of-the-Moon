#include "MovableObject.h"
#include "DxLib.h"

MovableObject::MovableObject() : Object(&del){
	if (del) {
		delete this;
		return;
	}
	if (this->RegistObj(this) == -1) {
		delete this;
		return;
	}
	prex = posx;
	prey = posy;
}

MovableObject::~MovableObject() {
	if (serial_n != -1) {
		for (int i = serial_n; i < MovableObject::total_object; i++) {
			MovableObject::object_l[i] = MovableObject::object_l[i + 1];
			if (i < MovableObject::total_object - 1)MovableObject::object_l[i]->serial_n--;
		}
		MovableObject::total_object--;
	}
}

void MovableObject::Drag() {
	GetMousePoint(&mx, &my);
	
	bool click = GetMouseInput() & MOUSE_INPUT_LEFT;

	if (click) {
		for (int i = 0; i < total_object; i++) {
			if (object_l[i]->DragObject(cx, cy, mx, my)) break;
		}
	}
	else{
		cx = mx;
		cy = my;
	}
	
	DrawFormatString(0, 0, GetColor(255, 255, 255), "初期(%d, %d)", cx, cy);
	DrawFormatString(0, 18, GetColor(255, 255, 255), "現在(%d, %d)", mx, my);
}


MovableObject* MovableObject::object_l[MAX_OBJECT];
int MovableObject::total_object = 0;
int MovableObject::cx = 0;
int MovableObject::cy = 0;
int MovableObject::mx = 0;
int MovableObject::my = 0;

bool MovableObject::DragObject(int cx, int cy, int mx, int my) {
	if (prex < cx && cx < prex + Object::sx && prey < cy && cy < prey + Object::sy) {
		Object::posx = prex + mx - cx;
		Object::posy = prey + my - cy;

		return 1;
	}
	prex = Object::posx;
	prey = Object::posy;
	return 0;
}

int MovableObject::RegistObj(MovableObject* mvobj) {
	if (MAX_OBJECT <= total_object) {
		OutputDebugString("これ以上オブジェクトは追加できません\n");
		return -1;
	}

	mvobj->serial_n = total_object;
	object_l[total_object] = mvobj;
	total_object++;

	return 0;
}
