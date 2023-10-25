#pragma once
/****************************
�^�錾
****************************/
typedef struct				//�e�̃X�e�[�^�X��������B
{
	float BulletX;
	float BulletY;
	float BulletR;
	int IsBulletFlag;
}BulletStatus;

typedef enum				//�e�̎O�����������Ă���
{
	Straight,
	Right,
	Left,
}BulletWay;

/****************************
�v���g�^�C�v�錾
****************************/
void Bullet_Initialize(void);
void Bullet_Create(float& PlayerX, float& PlayerY);
void Bullet_Updata(void);
void Bullet_Draw(void);

int GetBulletFlag(void);

//�Â̕����z�[�~���O�Ƃ������̗U���~�T�C����
//����Ă������̂��̂ł���B
//�Ƃ肠�����������ɂȂ����̂ŃR�����g�����Ă���
//void Bullet_Homing(void);
