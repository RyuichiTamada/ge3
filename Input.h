#pragma once

#include<Windows.h>
#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>
#include <wrl.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

class Input
{
public:  //メンバ関数
	//初期化
	void Initialize(HINSTANCE hInstance, HWND hwnd);
	//更新
	void Update();

	//任意のボタンが押されている
	bool PushKey(BYTE keyNumber);

	//任意のボタンが押された瞬間
	bool TriggerKey(BYTE keyNumber);

	//任意のボタンが離された瞬間

private:
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;

	BYTE key[256] = {};
	BYTE keyPre[256] = {};
};

