#pragma once
#include <cstdint>
#include <vector>
#include "Model.h"
#include "WorldTransform.h"
//</summary>
///マップチップフィールド
//</summary>
enum class MapChipType {
	kBlank, // 空白
	kBlock, // ブロック
	};
struct MapChipData {
	std::vector<std::vector<MapChipType>> data;
};


class MapChipField {
 public:
	void ResetMapChip();
	void LoadMapChipCsv(const std::string& filePath);
	MapChipType GetMapChipTypeByIndex(uint32_t xIndex, uint32_t yIndex);
	Vector3 GetMapChipPostingByIndex(uint32_t xIndex,uint32_t yIndex);
	void ResetMapChipData();
int32_t GetkNumBlockVirtical() const { return kNumBlockVirtical; }
uint32_t GetkNumBlockHorizonal() const { return kNumBlockHorizonal; }
private:
	//1ブロックのサイズ
	static inline const float kBlockWidth = 1.0f;
	static inline const float kBlockHeight = 1.0f;
	//ブロックの個数　
	static inline const uint32_t kNumBlockVirtical = 20;
	static inline const uint32_t kNumBlockHorizonal = 100;

	MapChipData mapChipData_;

};
