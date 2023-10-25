#include "DxLib.h"
#include "Player.h"
#include "InputControl.h"
#include "Bullet.h"

/****************************
�v���g�^�C�v�ϐ��錾
****************************/
float PlayerX, PlayerY;
int PlayerImage;
int trigger;	//�X�g���[�g���O�����������߂� 0�̓X�g���[�g

/****************************
���@����@�\�F����������
���@���F�Ȃ�
�߂�l�F�Ȃ�
****************************/
void Player_Initialize(void)
{
	PlayerImage = LoadGraph("images/ico.jpg");

	PlayerX = 250.0f;
	PlayerY = 360.0f;
	trigger = FALSE;
}

/****************************
���@����@�\�F�X�V����
���@���F�Ȃ�
�߂�l�F�Ȃ�
****************************/
void Player_Updata(void)
{
	//�v���C���[�̈ړ�����
	if (key()[KEY_INPUT_A] == TRUE)
	{
		PlayerX -= 4.5f;
	}
	if (key()[KEY_INPUT_D] == TRUE)
	{
		PlayerX += 4.5f;
	}

	//�e�̓�����ω�������
	//C�L�[�������ꂽ���Ƃ��̎��ɒe�̃t���O��0�Ȃ�
	//�X�g���[�g�̒e���o���B
	//X�L�[�̓��l�ŉ����ꂽ���Ƃ��̎��ɒe�̃t���O��0�Ȃ�
	//�O�����̒e���o���B
	if (key()[KEY_INPUT_C] == TRUE && GetBulletFlag() == FALSE)
	{
		trigger = FALSE;
	}
	else if (key()[KEY_INPUT_X] == TRUE && GetBulletFlag() == FALSE)
	{
		trigger = TRUE;
	}


	//SPACE�L�[�������ꂽ���Ƃ��̎��ɒe�̃t���O��0�Ȃ�
	//�e�����o���������Ăяo���B
	//���̍ۂɎ��@�̈ʒu����n���B
	if (key()[KEY_INPUT_SPACE] == TRUE && GetBulletFlag() == FALSE)
	{
		Bullet_Create(PlayerX, PlayerY);
	}

}

/****************************
���@����@�\�F�`�揈��
���@���F�Ȃ�
�߂�l�F�Ȃ�
****************************/
void Player_Draw(void)
{
	DrawGraphF(PlayerX, PlayerY, PlayerImage, TRUE);
}

/****************************
���@����@�\�F�e�̓�����ς��邽�߂̏����擾
���@���F�Ȃ�
�߂�l�F�Ȃ�
****************************/
int ChangeStatus(void)
{
	return trigger;
}