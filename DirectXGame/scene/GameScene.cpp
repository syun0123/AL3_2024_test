#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include"ImGuiManager.h"

GameScene::GameScene() {}

GameScene::~GameScene() { 
	
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	textureHandle_ = TextureManager::Load("kamereon.jpeg");
	//スプライトの生成
	sprite_ = Sprite::Create(textureHandle_, {100, 50});
	//3D モデルの生成
	model_ = Model::Create();
	//ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	//ビュープロジェクションの初期化
	viewProjection_.Initialize();
	//サウンドデータ読み込み
	//soundDataHandle_ = audio_->LoadWave("se_sad03.wav");
	//自キャラ生成
	//player_ = new player();
	//自キャラの初期化
	//player_->Initialize();
}

void GameScene::Update() { 
	//移動
	//Vector2 position = sprite_->GetPosition();
	//position.x += 2.0f;
	//position.y += 1.0f;
	//sprite_->SetPosition(position);
	ImGui::ShowDemoWindow();
	ImGui::Begin("Debug1");
	ImGui::Text("Kamata tarou %d,%d,%d,2050,12,31");
	ImGui::InputFloat3("InputFloat3", inputFloat3);
	ImGui::SliderFloat3("SliderFloat3", inputFloat3, 0.0f, 1.0f);
	ImGui::End();
	//自キャラの更新
	//player_->Updete();
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

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);
	
	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>
	sprite_->Draw();
	model_->Draw(worldTransform_, viewProjection_, textureHandle_);
	/// 
	
	// スプライト描画後処理
    Sprite::PostDraw();
	delete sprite_;
	delete model_;
#pragma endregion
}
