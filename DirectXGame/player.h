#pragma once
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
class player {
public:
	void Initialize(Model*model,uint32_t textureHandle);
	void Updete();
	void Draw();

private:
	WorldTransform worldTransform_;
	Model* model_ = nullptr;
uint32_t textureHandle_=0u;

};



	
