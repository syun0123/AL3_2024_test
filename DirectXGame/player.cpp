#include "player.h"
#include"cassert"

void Player::Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewprojection) {
//NULLポインタチェック
assert(model);

//引数の内容をメンバ変数に記録

model_ = model;
textureHandle_ = textureHandle;
viewProjection_ = viewprojection;
worldTransform_.Initialize();
}

void Player::Update() {/* worldTransform_.TransferMatrix();*/ }

//void Player::Draw() {
//	model_->Draw(worldTransform_, *viewProjection_, textureHandle_);
//}
void Player::Draw() {
	// 3Dモデルを描画
	/* model_->Draw(worldTransform_, *viewProjection_);*/
}