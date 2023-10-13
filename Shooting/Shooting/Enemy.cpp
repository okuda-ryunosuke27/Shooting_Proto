#include "Enemy.h"
#include "DxLib.h"

float EnemyX = 300.0f, EnemyY = 10.0f, EnemyR = 18.0f, EnemySpeed = 2.0f;
int IsEnemyAlive = 1;


void Enemy_Draw(void)
{
	DrawBoxAA(EnemyX, EnemyY, EnemyX + 32, EnemyY + 32, 0xFFFFFF, TRUE);
}

float GetEnemyX(void)
{
	return EnemyX;
}
float GetEnemyY(void)
{
	return EnemyY;
}