#include "DxLib.h"
#include "MovableObject.h"

#define SCREEN_MX 640	//�Q�[���X�N���[���̇]�����̑傫��
#define SCREEN_MY 480	//�Q�[���X�N���[���̂x�����̑傫��

int InitGame();
int Game();
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏������C�G���[����
	SetGraphMode(SCREEN_MX, SCREEN_MY, 16);
	SetMouseDispFlag(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);

	if (InitGame() == -1) return -1;
	Game();

	DxLib_End();	// �c�w���C�u�����g�p�̏I������
	return 0;		// �\�t�g�̏I�� 
}

int InitGame() {
	OutputDebugString("InitGame\n");

	return 0;
}

int Game() {
	OutputDebugString("Game\n");
	
	for (int i = 0; i < 6; i++){
		MovableObject* obj = new MovableObject();
		obj->SetPosition(i * 50, 50);
	}

	Object::Delete(3);

	for (int i = 0; i < 4; i++) {
		Object* obj = new Object();
		obj->SetPosition(i * 50, 100);
	}
	while (true){
		ClearDrawScreen();
		MovableObject::Drag();
		Object::Put();
		ScreenFlip();
	}

	DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�
	WaitKey();	// �L�[���͑҂�

	return 0;
}