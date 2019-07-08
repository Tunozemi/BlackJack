#include "CardData.h"
#define CARD (52)

//----------�R���X�g���N�^�̒�`----------
//�I�u�W�F�N�g���������ꂽ���Ɏ����I�ɌĂяo����郁�\�b�h
CardData::CardData() {
	srand((unsigned int)time(NULL));		//�����_������
	CardShuffle();
}
//----------�f�X�g���N�^�̒�`----------
//�I�u�W�F�N�g����ڂ��I�������Ɏ����I�ɌĂяo����郁�\�b�h
CardData::~CardData() {}

//----------�����o���\�b�h�̒�`----------
//----------�J�[�h���----------
void CardData::CardShuffle() {
	_deckCard.clear();
	int i = 0;
	while (i < CARD) 
	{
		bool flag = true;
		int card = RandomCard(0, 51);		//�J�[�h�V���b�t��

		for (int j = 0; j < (int)_deckCard.size(); j++)
		{
			//���ɏ�ɂ���J�[�h�ƏƂ炵���킹��
			if (card == (int)_deckCard[j]) 
			{
				flag = false;
				break;
			}
		}
		if (flag) 
		{
			SetCard(card);
			i++;
		}
	}
}

//min�`max�̃����_���Ȑ�����Ԃ�
int CardData::RandomCard(int min, int max){
	return min + (int)(rand()*(max - min + 1.0) / (1.0 + RAND_MAX));
}

//�R�D����J�[�h�����o��
int CardData::GetCard() {
	int drawCard = _deckCard.back();
	_deckCard.pop_back();
	return drawCard;
}

//0�`51�̃J�[�h���g�����v�Ɋ��蓖�Ă�
void CardData::ConversionCard(int remainder, int quotient) {

	//10���h���[
	if (remainder == 9) 
	{
		std::cout << "[" << CardData::_cardSymbol[quotient] << "10" << "] ";
	}
	else 
	{
		std::cout << "[" << CardData::_cardSymbol[quotient] << CardData::_cardNum[remainder] << "] ";
	}
}

//static�ϐ�������
const char CardData::_cardSymbol[5] = { "SHDC" };
const char CardData::_cardNum[14] = { "A23456789XJQK" };
