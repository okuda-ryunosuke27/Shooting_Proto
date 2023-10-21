#include "Enemy.h"
#include "DxLib.h"

float EnemyX = 300.0f, EnemyY = 10.0f, EnemyR = 18.0f, EnemySpeed = 2.0f;
int IsEnemyAlive = 1;

/****************************
*敵制御処理：敵の更新処理
* 引　数：なし
* 戻り値：なし
****************************/
void Enemy_Update(void)
{
	if (EnemyX + 32 >= 640 || EnemyX <= 0)
	{
		EnemySpeed *= -1;
	}

	EnemyX += EnemySpeed;
}

/****************************
*敵制御処理：敵の描画処理
* 引　数：なし
* 戻り値：なし
****************************/
void Enemy_Draw(void)
{
	DrawBoxAA(EnemyX, EnemyY, EnemyX + 32, EnemyY + 32, 0xFFFFFF, TRUE);
}

/****************************
*敵制御処理：敵のX座標を取得
* 引　数：なし
* 戻り値：なし
****************************/
float GetEnemyX(void)
{
	return EnemyX;
}

/****************************
*敵制御処理：敵のY座標を取得
* 引　数：なし
* 戻り値：なし
****************************/
float GetEnemyY(void)
{
	return EnemyY;
}