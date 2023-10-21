#include "Enemy.h"
#include "DxLib.h"

float EnemyX = 300.0f, EnemyY = 10.0f, EnemyR = 18.0f, EnemySpeed = 2.0f;
int IsEnemyAlive = 1;

/****************************
*�G���䏈���F�G�̍X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
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
*�G���䏈���F�G�̕`�揈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
****************************/
void Enemy_Draw(void)
{
	DrawBoxAA(EnemyX, EnemyY, EnemyX + 32, EnemyY + 32, 0xFFFFFF, TRUE);
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