#pragma once

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

	Object(bool*);

	int posx = 0, posy = 0;	//�ʒu
	int sx = 32, sy = 32;	//�傫��

private:
	
	int picture = -1;	//�摜
	int serial_n = -1;
	bool exist = 1;

	static Object* object_l[MAX_OBJECT];	//�I�u�W�F�N�g�̃��X�g
	static int total_object;				//�I�u�W�F�N�g�̑���

	void PutObject();

	static int RegistObj(Object*);
};