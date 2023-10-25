#include "DxLib.h"
#include "Player.h"
#include "InputControl.h"
#include "Bullet.h"

/****************************
プロトタイプ変数宣言
****************************/
float PlayerX, PlayerY;
int PlayerImage;
int trigger;	//ストレートか三方向かを決める 0はストレート

/****************************
自機制御機能：初期化処理
引　数：なし
戻り値：なし
****************************/
void Player_Initialize(void)
{
	PlayerImage = LoadGraph("images/ico.jpg");

	PlayerX = 250.0f;
	PlayerY = 360.0f;
	trigger = FALSE;
}

/****************************
自機制御機能：更新処理
引　数：なし
戻り値：なし
****************************/
void Player_Updata(void)
{
	//プレイヤーの移動処理
	if (key()[KEY_INPUT_A] == TRUE)
	{
		PlayerX -= 4.5f;
	}
	if (key()[KEY_INPUT_D] == TRUE)
	{
		PlayerX += 4.5f;
	}

	//弾の特徴を変化させる
	//Cキーが押された時とその時に弾のフラグが0なら
	//ストレートの弾を出す。
	//Xキーの同様で押された時とその時に弾のフラグが0なら
	//三方向の弾を出す。
	if (key()[KEY_INPUT_C] == TRUE && GetBulletFlag() == FALSE)
	{
		trigger = FALSE;
	}
	else if (key()[KEY_INPUT_X] == TRUE && GetBulletFlag() == FALSE)
	{
		trigger = TRUE;
	}


	//SPACEキーが押された時とその時に弾のフラグが0なら
	//弾を作り出す処理を呼び出す。
	//その際に自機の位置情報を渡す。
	if (key()[KEY_INPUT_SPACE] == TRUE && GetBulletFlag() == FALSE)
	{
		Bullet_Create(PlayerX, PlayerY);
	}

}

/****************************
自機制御機能：描画処理
引　数：なし
戻り値：なし
****************************/
void Player_Draw(void)
{
	DrawGraphF(PlayerX, PlayerY, PlayerImage, TRUE);
}

/****************************
自機制御機能：弾の特徴を変えるための情報を取得
引　数：なし
戻り値：なし
****************************/
int ChangeStatus(void)
{
	return trigger;
}