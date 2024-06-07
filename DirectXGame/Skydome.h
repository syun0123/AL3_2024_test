#pragma once
#include "WorldTransform.h"
#include "Model.h"
//<summary>
//天球
//</summary>
class Skydome {
public:
	//<summary>
	//初期化
	//</summary>
	void Initialize(Model* model, ViewProjection* viewProjection);
	//<summary>
	//初期化
	//</summary>
	void Update();
	//<summary>
	//描画
	//</summary>
	void Draw();

private:
	//ワールド変換データ
	WorldTransform worldTransform_;
	//モデル
	Model* model_ = nullptr;
	ViewProjection* viewProjection_ = nullptr;
};
