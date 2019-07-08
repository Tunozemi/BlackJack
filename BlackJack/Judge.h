#ifndef JUDGE_HPP
#define JUDGE_HPP

//----------クラスの定義----------
//このクラスはBlackJackの仕様とか説明書みたいなもの
class Judge{
public:
	static bool BurstJudge(int cardsum);					//バースト判定
	static int	VictoryJudge(int cardsum1, int cardsum2);	//勝利判定

private:
	Judge();	//コンストラクタの宣言
	~Judge();	//デストラクタの宣言
};
#endif