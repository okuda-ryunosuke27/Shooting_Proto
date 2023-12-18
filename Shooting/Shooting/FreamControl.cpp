#include "DxLib.h"
#include "FreamControl.h"

/****************************
変数宣言
****************************/
int FreamTime;
int LastTime;
int FreamCount;

/****************************
フレーム制御機能：初期化処理
引　数：なし
戻り値：なし
****************************/
void FreamControl_Initialize(void)
{
	FreamTime = ((int) 1000.0f / FREAM_RATE);
	LastTime = GetNowCount();
	FreamCount = 0;	
}

/****************************
フレーム制御機能：更新処理
引　数：なし
戻り値：なし
****************************/
void FreamControl_Update(void)
{
	if (FreamCount == FREAM_RATE)
	{
		FreamCount = 0;
		LastTime = GetNowCount();
	}
	FreamCount++;

	int took = GetNowCount() - LastTime;
	int wait = FreamCount * 1000 / 60 - took;
	if (wait > 0)
	{
		WaitTimer(wait);
	}
}

/****************************
フレーム制御機能：フレームレートを取得する
引　数：なし
戻り値：フレームレート
****************************/
float GetFreamRate(void)
{
	return (float)(GetNowCount() - LastTime) / FreamCount;
}