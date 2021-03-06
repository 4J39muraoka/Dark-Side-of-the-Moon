#include "DxLib.h"
#include "MovableObject.h"
#include "Button.h"

#define SCREEN_MX 640	//ゲームスクリーンの�]方向の大きさ
#define SCREEN_MY 480	//ゲームスクリーンのＹ方向の大きさ

int InitGame();
int Game();
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化，エラー処理
	SetGraphMode(SCREEN_MX, SCREEN_MY, 16);
	SetMouseDispFlag(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);

	if (InitGame() == -1) return -1;
	Game();

	DxLib_End();	// ＤＸライブラリ使用の終了処理
	return 0;		// ソフトの終了 
}

int InitGame() {
	OutputDebugString("InitGame\n");

	return 0;
}

int Game() {
	OutputDebugString("Game\n");
	
	for (int i = 0; i < 3; i++) {
		Object* obj = new Object();
		obj->SetPosition(i * 50, 100);
	}

	for (int i = 0; i < 3; i++){
		MovableObject* obj = new MovableObject();
		obj->SetPosition(i * 50, 50);
	}
	
	Button button0([]() {
		OutputDebugStringA("ボタン0が押された\n");
	});
	button0.SetPosition(0, 150);

	Button button1([]() {
		OutputDebugStringA("ボタン1が押された\n");
	});
	button1.SetPosition(50, 150);


	WaitTimer(0);
	while (true){
		ClearDrawScreen();
		MovableObject::Drag();
		Button::Push();
		Object::Put();
		ScreenFlip();
	}

	DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ
	WaitKey();	// キー入力待ち

	return 0;
}