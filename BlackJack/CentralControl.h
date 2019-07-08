#pragma once

//----------クラスの定義----------
//カード情報
class CentralControl{
public:
	CentralControl();	//コンストラクタの宣言
	~CentralControl();	//デストラクタの宣言

	bool GameStart();
	bool GameSelect(bool truth);
};