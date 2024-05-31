#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include"ImGuiManager.h"

GameScene::GameScene() {}

GameScene::~GameScene() { 
	// delete sprite_; 
	delete modelBlock_;
	//delete player_;
//for (WorldTransform* worldTransformBlock : worldTransformBlocks_) {
//	delete worldTransformBlock;
//}
//worldTransformBlocks_.clear();
	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
			delete worldTransformBlock;
		}
	}
	worldTransformBlocks_.clear();
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
//	audio_ = Audio::GetInstance();
	textureHandle_ = TextureManager::Load("kamereon.jpeg");
	//スプライトの生成
	//sprite_ = Sprite::Create(textureHandle_, {100, 50});
	//3D モデルの生成
	modelBlock_ = Model::CreateFromOBJ("cube");
	worldTransform_.Initialize();
	viewProjection_.Initialize();
	//自キャラの生成
	//player_ = new Player();
	//自キャラの初期化
	//player_->Initialize( model_,  textureHandle_,  &viewProjection_);
	//要素数
	const uint32_t kNumBlockVirtical = 10;
	const uint32_t kNumBlockHorizontal = 20;
	//ブロック1個分の横幅
	const float kBlockWidth = 2.0f;
	const float kBlockHeight = 2.0f;
	//要素数を変更
	//worldTransformBlocks_.resize(kNumBlockHorizontal);
	worldTransformBlocks_.resize(kNumBlockVirtical);
	for (uint32_t i = 0; i < kNumBlockVirtical; ++i) {
	//1列の要素数を設定
		worldTransformBlocks_[i].resize(kNumBlockHorizontal);
	}
	    //キューブ生成

	for (uint32_t i = 0; i < kNumBlockHorizontal; i++) {
		for (uint32_t j = 0; j < kNumBlockHorizontal; j++) {
		
		worldTransformBlocks_[i][j] = new WorldTransform();
		worldTransformBlocks_[i][j]->Initialize();
		worldTransformBlocks_[i][j]->translation_.x = kBlockWidth * j;
		worldTransformBlocks_[i][j]->translation_.y = kBlockHeight*i;
	}
	}
}

void GameScene::Update() { /*
	移動
	Vector2 position = sprite_->GetPosition();
	position.x += 2.0f;
	position.y += 1.0f;
	sprite_->SetPosition(position);*/
	//ImGui::Begin("Debug1");
	////ImGui::Text("Kamata tarou %d,%d,%d,2050,12,31");
	//ImGui::InputFloat3("InputFloat3", inputFloat3);
	// ブロックの更新

	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
			// 平行移動
			Matrix4x4 result{
			    1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f, 
				0.0f, 0.0f, 1.0f, 0.0f,
				worldTransformBlock->translation_.x, 
				worldTransformBlock->translation_.y, 
				worldTransformBlock->translation_.z,
			    1.0f};

			// 平行移動だけ代入
			worldTransformBlock->matWorld_ = result;
			// 定数バッファに転送する
			worldTransformBlock->TransferMatrix(); // ImGui::End();
			worldTransformBlock->UpdateMatrix();
			// player_->Update();
		}

		}
	





	/* for (WorldTransform* worldTransformBlock : 
		worldTransformBlocks_) {
		// 平行移動
		Matrix4x4 result{
		    1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			worldTransformBlock->translation_.x,
			worldTransformBlock->translation_.y,
			worldTransformBlock->translation_.z,
		    1.0f};
	
	// 平行移動だけ代入
	worldTransformBlock->matWorld_ = result;
	// 定数バッファに転送する
	worldTransformBlock->TransferMatrix(); // ImGui::End();
	worldTransformBlock->UpdateMatrix();
	//player_->Update();
	}*/

}
void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);
	//ブロック描画
	//for (WorldTransform* worldTransformBlock : worldTransformBlocks_) {
	//	modelBlock_->Draw(*worldTransformBlock, viewProjection_);
	//}
	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
		modelBlock_->Draw(*worldTransformBlock, viewProjection_);
		}
	}
	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	modelBlock_->Draw(worldTransform_, viewProjection_, textureHandle_);
	//player_->Draw();

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);
	
	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>
	/// 
	//sprite_-> Draw();
	// スプライト描画後処理
	Sprite::PostDraw();
	
#pragma endregion
}
