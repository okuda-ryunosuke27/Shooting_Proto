#include "DxLib.h"
#include "ErrorFlag.h"
#include "Player.h"
#include "InputControl.h"
#include "Bullet.h"
#include "Enemy.h"
#include "FreamControl.h"


#define SCREEN_HEIGHT (480)		//�X�N���[���T�C�Y(����)
#define SCREEN_WIDTH (640)		//�X�N���[���T�C�Y(��)
#define SCREEN_COLORBIT (32)	//�X�N���[���J���[�r�b�g




int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR IpCmdLine, _In_ int nShowCmd)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);

	//Dx���C�u�����̏���������
	if (DxLib_Init() == D_ERROR)
	{
		return D_ERROR;
	}

	//�t���[�����[�g�̏�����
	FreamControl_Initialize();
	//�v���C���[�̏�����
	Player_Initialize();

	//�Q�[�����[�v
	while (ProcessMessage()!=D_ERROR && Input_Escape() == FALSE)
	{
		//���͂̍X�V����
		Input_Updata();

		//��ʃN���A
		ClearDrawScreen();

		//�e�̍X�V����
		//Bullet_Updata();
		Bullet_Homing();

		//�v���C���[�X�V����
		Player_Updata();

		//�e�̕`��
		Bullet_Draw();

		//�v���C���[�̕`��
		Player_Draw();

		//�G�l�~�[�̕`��
		Enemy_Draw();


		FreamControl_Update();

		//��ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}

	//Dx���C�u�����g�p�̏I������
	DxLib_End();

	return 0;
}