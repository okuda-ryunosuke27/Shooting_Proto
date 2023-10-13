#include "InputControl.h"
#include "ErrorFlag.h"
#include "DxLib.h"


char keys[256] = { 0 };
char oldkeys[256] = { 0 };

/****************************
入力の更新処理
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
ESCキー押されているかどうか

****************************/
int Input_Escape(void)
{
	int ret = FALSE;

	if (CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ret = TRUE;
	}

	return ret;
}

/****************************
他のcppに入力処理を使えるようにする関数。

****************************/
char* key(void)
{
	return keys;
}
