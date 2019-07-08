#ifndef UIRE_HPP
#define UIRE_HPP
#include <stdio.h>

//----------クラスの定義----------
class UiRe
{
public:
	static void Partition()	{
		printf_s("\n--------------------------------------------------\n");	}	//仕切り

private:
	UiRe();	//コンストラクタの宣言
	~UiRe();	//デストラクタの宣言
};
#endif