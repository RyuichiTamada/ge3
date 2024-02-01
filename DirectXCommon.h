#pragma once
class DirectXCommon
{
public:
	void Initialize();
	void Update();
	void Draw();

private:
	//�f�o�C�X
	void DeviceInitialize();
	//�R�}���h
	void CommandInitialize();
	//�X���b�v�`�F�[��
	void SwapChainInitialize();
	//�����_�[�^�[�Q�b�g
	void RenderTargetInitialize();
	//�[�x�o�b�t�@
	void DepthBufferInitialize();
	//�t�F���X
	void FenceInitialize();
};
