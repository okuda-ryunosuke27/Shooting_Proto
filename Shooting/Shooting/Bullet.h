#pragma once


/****************************
�^�錾
****************************/
typedef struct Bullet
{
	float BulletX;
	float BulletY;
	float BulletR;
	int IsBulletFlag;
}BulletStatus;

typedef enum BulletWay
{
	Straight,
	Right,
	Left,
};


/****************************
�v���g�^�C�v�錾
****************************/
void Bullet_Initialize(float& PlayerX, float& PlayerY);
void Bullet_Updata(void);

void Bullet_Homing(void);
void Bullet_Draw(void);

int GetBulletFlag(void);