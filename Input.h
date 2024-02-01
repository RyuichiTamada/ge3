#pragma once

#include<Windows.h>
#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>
#include <wrl.h>

#include"WinApp.h"

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

class Input
{
public:  //�����o�֐�
	//������
	void Initialize(WinApp* winApp);
	//�X�V
	void Update();

	//�C�ӂ̃{�^����������Ă���
	bool PushKey(BYTE keyNumber);

	//�C�ӂ̃{�^���������ꂽ�u��
	bool TriggerKey(BYTE keyNumber);

	//�C�ӂ̃{�^���������ꂽ�u��

private:
	WinApp* winApp_ = nullptr;

	Microsoft::WRL::ComPtr<IDirectInput8> directInput;
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;

	BYTE key[256] = {};
	BYTE keyPre[256] = {};
};

