#include "Skydome.h"
#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include "WorldTransform.h"
#include"cassert"

void Skydome::Initialize(Model* model, ViewProjection* viewProjection) { 
	assert(model);

	model_ = model;
	viewProjection_ = viewProjection;
	worldTransform_.Initialize();
}

void Skydome::Update() { worldTransform_.TransferMatrix(); }

void Skydome::Draw() { 
	model_->Draw(worldTransform_, *viewProjection_);

}
