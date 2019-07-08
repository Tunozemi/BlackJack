#pragma once
#include "Player.h"
#include <string>


//----------クラスの定義----------
//このクラスはBlackJackの仕様とか説明書みたいなもの
class Table {
public:
	void CardSumConfirmation();			//合計値表示
	void Partition();					//仕切り

private:
	Table();	//コンストラクタの宣言
	~Table();	//デストラクタの宣言

};