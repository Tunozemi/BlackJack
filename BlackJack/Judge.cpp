#include "Judge.h"

//----------�R���X�g���N�^�̒�`----------
Judge::Judge() {}
//----------�f�X�g���N�^�̒�`----------
Judge::~Judge() {}

//----------�����o���\�b�h�̒�`----------
//�o�[�X�g����
bool Judge::BurstJudge(int cardsum){
	bool truth;
	if (cardsum > 21)
	{
		truth = false;
	}
	else { truth = true; }
	return truth;
}

//��������F������enum���g���Ė��O�ł��Ԃ��ׂ����낤����������킩���
int Judge::VictoryJudge(int cardsum1, int cardsum2){
	int win = 0;
	if (cardsum1 < cardsum2)
	{
		win = 1;
	}
	else if (cardsum1 == cardsum2)
	{
		win = -1;
	}
	return win;
}