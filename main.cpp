#include"Input.h"
#include"WinApp.h"
#include"DirectXCommon.h"


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    //ポインタ置き場
    Input* input_ = nullptr;
    WinApp* winApp_ = nullptr;

#pragma region WindowsAPI初期化処理
    
    winApp_ = new WinApp();
    winApp_->Initialize();
    DirectXCommon* dxCommon_ = nullptr;

#pragma region DirectX初期化処理
    // DirectX初期化処理　ここから

    dxCommon_ = new DirectXCommon();
    dxCommon_->Initialize(winApp_);

    // DirectX初期化処理　ここまで
#pragma endregion

    //Inputの生成、初期化
    input_ = new Input();
    input_->Initialize(winApp_);


// 描画初期化処理

    // ゲームループ
    while (true) {
        //更新
        if (winApp_->Update() == true) {
            break;
        }

        input_->Update();

        //更新前処理
        dxCommon_->PreDraw();

        //更新後処理
        dxCommon_->PostDraw();

        // DirectX毎フレーム処理　ここまで
    }

    //解放処理
    delete input_;

    delete dxCommon_;

    winApp_->Finalize();
    delete winApp_;


    return 0;
}
