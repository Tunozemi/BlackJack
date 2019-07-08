#include "Table.h"

//----------コンストラクタの定義----------
Table::Table() {
}
//----------デストラクタの定義----------
Table::~Table() {
}

//----------メンバメソッドの定義----------
//カードの合計値表示
void Table::CardSumConfirmation() {
	std::cout << " = " << data._cardSum;
}

//仕切り
void Table::Partition() {
	printf_s("\n--------------------------------------------------\n");
}