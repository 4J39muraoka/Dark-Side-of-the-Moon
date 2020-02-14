#include "Object.h"
#include "DxLib.h"

Object::Object() {
	if (this->RegistObj(this) == -1) {
		delete this;
		return;
	}
}

Object::~Object() {
	for (int i = serial_n; i < Object::total_object; i++) {
		Object::object_l[i] = Object::object_l[i+1];
	}
	Object::total_object--;
}

void Object::SetPicture(int pict) {
	picture = pict;
}

void Object::SetPosition(int x, int y) {
	posx = x;
	posy = y;
}

void Object::SetScale(int x, int y) {
	sx = x;
	sy = y;
}

void Object::Put() {
	for (int i=0; i<total_object; i++) {
		if (object_l[i]->exist) {
			object_l[i]->PutObject();
		}
	}
}

void Object::Delete() {
	for (int i = 0; i < total_object; i++) {
		delete object_l[i];
	}
}

void Object::Delete(int serial) {
	delete object_l[serial];
}

void Object::SetExist(bool e) {
	exist = e;
}

Object* Object::object_l[MAX_OBJECT];
int Object::total_object = 0;

void Object::PutObject() {
	if (picture == -1) DrawBox(posx, posy, posx + sx, posy + sy, GetColor(255, 255, 255), true);
	else DrawExtendGraph(posx, posy, posx + sx, posy + sy, picture, true);
	
}

int Object::RegistObj(Object* obj) {
	if (MAX_OBJECT <= total_object) {
		OutputDebugString("これ以上オブジェクトは追加できません\n");
		return -1;
	}

	obj->serial_n = total_object;
	object_l[total_object] = obj;
	total_object++;

	return 0;
}