#include "Enemy.h"
#include "DxLib.h"

#define ENEMYSIZE	(32)

float EnemyX = 300.0f,
float EnemyY = 10.0f, EnemyR = 18.0f, EnemySpeed = 2.0f;
int IsEnemyAlive = 1;

/****************************
�G���䏈���F�G�̍X�V����
���@���F�Ȃ�
�߂�l�F�Ȃ�
****************************/
void Enemy_Initialize(void)
{
	EnemyX = 300.f;
	EnemyY = 10.f;
	EnemyR = 18.f;
}

/****************************
�G���䏈���F�G�̍X�V����
���@���F�Ȃ�
�߂�l�F�Ȃ�
****************************/
void Enemy_Update(void)
{
	if (EnemyX + ENEMYSIZE >= 640 || EnemyX <= 0)
	{
		EnemySpeed *= -1;
	}

	EnemyX += EnemySpeed;
}

/****************************
�G���䏈���F�G�̕`�揈��
���@���F�Ȃ�
* �߂�l�F�Ȃ�
****************************/
void Enemy_Draw(void)
{
	DrawBoxAA(EnemyX, EnemyY, EnemyX + ENEMYSIZE, EnemyY + ENEMYSIZE, 0xFFFFFF, TRUE);
}

/****************************
*�G���䏈���F�G��X���W���擾
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
****************************/
float GetEnemyX(void)
{
	return EnemyX;
}

/****************************
*�G���䏈���F�G��Y���W���擾
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
****************************/
float GetEnemyY(void)
{
	return EnemyY;
}