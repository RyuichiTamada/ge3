#include "Input.h"

#include <cassert>
using namespace Microsoft::WRL;

void Input::Initialize(HINSTANCE hInstance, HWND hwnd)
{
    HRESULT result;

    // DirectInput�̏�����
    ComPtr<IDirectInput8> directInput;
    result = DirectInput8Create(
        hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
    assert(SUCCEEDED(result));

    // �L�[�{�[�h�f�o�C�X�̐���
    result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
    // ���̓f�[�^�`���̃Z�b�g
    result = keyboard->SetDataFormat(&c_dfDIKeyboard); // �W���`��
    assert(SUCCEEDED(result));
    // �r�����䃌�x���̃Z�b�g
    result = keyboard->SetCooperativeLevel(
        hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    assert(SUCCEEDED(result));
}

void Input::Update()
{
   /* for (int i = 0; i < 256; i++;) {
        keyPre[i] = key[i];
    }*/

    //keyPre�̒���key�̏���ۑ�
    memcpy(keyPre, key, sizeof(key));

    // �L�[�{�[�h���̎擾�J�n
    keyboard->Acquire();
    // �S�L�[�̓��͏�Ԃ��擾����
    keyboard->GetDeviceState(sizeof(key), key);
}

bool Input::PushKey(BYTE keyNumber)
{
    //�C�ӂ̃{�^���������ꂽ��
    if (key[keyNumber]) {
        return true;
    }

    //������Ă��Ȃ�
    return false;
}

bool Input::TriggerKey(BYTE keyNumber)
{
    if (key[keyNumber]) {
        return true;
    }
    return false;
}
