#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();
	//	ワールドトランスフォーム
	WorldTransform worldTransform_;
	// ビュープロダクション
	ViewProjection viewProjection_;
	//ImGuiで値を入力する変数
	float inputFloat3[3] = {0, 0, 0};

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
    /// 
 

	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
	//テクスチャハンドル
	uint32_t textureHandle_ = 0;
	
	//スプライト
	//Sprite* sprite_ = nullptr;
	Model* model_ = nullptr;

};
