#include "CentralControl.h"
#include "BlackJack.h"
#include <iostream>

//----------コンストラクタの定義----------
//オブジェクトが生成された時に自動的に呼び出されるメソッド
CentralControl::CentralControl() {

}

//----------デストラクタの定義----------
//オブジェクトが役目を終えた時に自動的に呼び出されるメソッド
CentralControl::~CentralControl() {

}

//----------メンバメソッドの定義----------
//ゲーム選択メソッド
bool CentralControl::GameStart() {

	//ゲーム選択メソッドを作って、BJを呼び出すか選択できるような作りにする
	bool endSelect = true;

	while (GameSelect(endSelect)) {

	}
	return false;
}

//ゲーム選択
bool CentralControl::GameSelect(bool truth){
	//クラスをSwitch文で選択性にして、ゲームを全てStartメソッドで統一しておく
	BlackJack blackjack;

	std::cout <<"BJスタート\n";
	std::cout << "----------------------------------------\n";
	truth = blackjack.Start();

	return truth;
}