#pragma once

#include "Object.h"
#include "functional"

class Button : public Object{
public:

	Button();
	Button(std::function<void(void)>);

	static void Push();

protected:
private:

	std::function<void(void)> OnPush;
	static bool push;

	bool PushButton(int x, int y);

	static Button* object_l[MAX_OBJECT];		//�I�u�W�F�N�g�̃��X�g
	static int total_object;						//�I�u�W�F�N�g�̑���
	int serial_n = -1;
	bool del;
	static int RegistObj(Button*);

};

