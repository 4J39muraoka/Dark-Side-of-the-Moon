#include "Button.h"
#include "DxLib.h"


Button::Button() : Object::Object(&del){
	if (del) {
		delete this;
		return;
	}
	if (this->RegistObj(this) == -1) {
		delete this;
		return;
	}
}

Button::Button(std::function<void(void)> onpush) : Button::Button(){
	OnPush = onpush;
}

bool Button::push = 0;
void Button::Push() {
	bool click = GetMouseInput() & MOUSE_INPUT_LEFT;
	if (click) {
		if (push) return;

		int mx, my;
		GetMousePoint(&mx, &my);

		for (int i = 0; i < total_object; i++) {
			if (object_l[i]->PushButton(mx, my)) break;
		}

		push = 1;
	}
	else{
		push = 0;
	}
}

bool Button::PushButton(int x, int y) {
	if (!(Object::posx < x && x < Object::posx + Object::sx)) return 0;
	if (!(Object::posy < y && y < Object::posy + Object::sy)) return 0;
	
	this->OnPush();
	return 1;
}

Button* Button::object_l[MAX_OBJECT];
int Button::total_object = 0;
int Button::RegistObj(Button* button) {
	if (MAX_OBJECT <= total_object) {
		OutputDebugString("これ以上オブジェクトは追加できません\n");
		return -1;
	}

	button->serial_n = total_object;
	object_l[total_object] = button;
	total_object++;

	return 0;
}
