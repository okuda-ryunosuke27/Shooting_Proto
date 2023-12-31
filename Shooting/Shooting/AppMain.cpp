#include "DxLib.h"
#include "ErrorFlag.h"
#include "Player.h"
#include "InputControl.h"
#include "Bullet.h"
#include "Enemy.h"
#include "FreamControl.h"


#define SCREEN_HEIGHT (480)		//スクリーンサイズ(高さ)
#define SCREEN_WIDTH (640)		//スクリーンサイズ(幅)
#define SCREEN_COLORBIT (32)	//スクリーンカラービット




int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR IpCmdLine, _In_ int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//画面サイズの最大サイズ、カラービット数を設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);

	//Dxライブラリの初期化処理
	if (DxLib_Init() == D_ERROR)
	{
		return D_ERROR;
	}

	//フレームレートの初期化
	FreamControl_Initialize();
	//自機の初期化
	Player_Initialize();
	//弾の初期化
	Bullet_Initialize();
	//敵の初期化
	Enemy_Initialize();

	//ゲームループ
	while (ProcessMessage()!=D_ERROR && Input_Escape() == FALSE)
	{
		//フレーム制御機能更新処理
		FreamControl_Update();
		//入力の更新処理
		Input_Updata();

		//画面クリア
		ClearDrawScreen();

		//弾の更新処理
		Bullet_Updata();

		//プレイヤー更新処理
		Player_Updata();

		//エネミー更新処理
		Enemy_Update();

		//弾の描画
		Bullet_Draw();

		//プレイヤーの描画
		Player_Draw();

		//エネミーの描画
		Enemy_Draw();

		//画面の内容を表画面に反映
		ScreenFlip();
	}

	//Dxライブラリ使用の終了処理
	DxLib_End();

	return 0;
}