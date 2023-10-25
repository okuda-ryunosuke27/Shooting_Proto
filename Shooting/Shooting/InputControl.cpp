#include "InputControl.h"
#include "ErrorFlag.h"
#include "DxLib.h"


char keys[256] = { 0 };
char oldkeys[256] = { 0 };

/****************************
入力制御機能：更新処理
引　数：なし
戻り値：なし
****************************/
void Input_Updata(void)
{
	//最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
	for (int i = 0; i < 256; ++i)
	{
		oldkeys[i] = keys[i];
	}

	//最新のキーボード情報を取得
	GetHitKeyStateAll(keys);
}

/****************************
入力制御機能：ESCキー入力チェック
引　数：なし
戻り値：TRUE(入力された)、FALSE(未入力)
****************************/
int Input_Escape(void)
{
	int ret = FALSE;

	//ESCキーが押されたらループから抜ける
	if (CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ret = TRUE;
	}

	return ret;
}

/****************************
入力制御機能：入力情報取得処理
引　数：なし
戻り値：入力された情報を渡す
****************************/
char* key(void)
{
	return keys;
}

/****************************
入力制御機能：入力情報取得処理
引　数：なし
戻り値：過去に入力された情報を渡す
****************************/
char* oldkey(void)
{
	return oldkeys;
}