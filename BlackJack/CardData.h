#ifndef CARDDATA_HPP
#define CARDDATA_HPP
#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#include <iostream>

//----------�N���X�̒�`----------
//�J�[�h���
class CardData {
public:	
	CardData();										//�R���X�g���N�^�̐錾
	~CardData();									//�f�X�g���N�^�̐錾

	void	CardShuffle();									//�J�[�h���V���b�t������
	void	SetCard(int card) { _deckCard.push_back(card); }//�R�D�ɃJ�[�h���Z�b�g
	int		GetCard();										//�R�D�̃J�[�h�����o��

	static void	ConversionCard(int remainder, int quotient);//0�`51�̃J�[�h�����ۂ̃J�[�h�Ɋ���
	int		RandomCard(int min, int max);					//0�`51�̃����_���Ȑ��l���擾

private:
	const static char _cardSymbol[5];			//�J�[�h�L�� �X�y�[�h�A�n�[�g�A�_�C�A�A�N���[�o�[
	const static char _cardNum[14];			//�J�[�h�ԍ�
	std::vector<int> _deckCard;			//�R�D�̃J�[�h
};
#endif