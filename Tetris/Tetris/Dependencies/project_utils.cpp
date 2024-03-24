#include "project_utils.h"

int getRandom() 
{
	// 使用 random_device 來取得隨機數種子
	std::random_device rd;

	// 使用 Mersenne Twister 引擎，它提供了高品質的隨機數生成
	std::mt19937 gen(rd());
	// 使用 uniform_int_distribution 來定義隨機數的範圍
	std::uniform_int_distribution<> dis(1, 100); // 產生 1 到 100 之間的隨機整數
	return dis(gen);
}