#include "CentralControl.h"
#include "BlackJack.h"
#include <iostream>

//----------�R���X�g���N�^�̒�`----------
//�I�u�W�F�N�g���������ꂽ���Ɏ����I�ɌĂяo����郁�\�b�h
CentralControl::CentralControl() {

}

//----------�f�X�g���N�^�̒�`----------
//�I�u�W�F�N�g����ڂ��I�������Ɏ����I�ɌĂяo����郁�\�b�h
CentralControl::~CentralControl() {

}

//----------�����o���\�b�h�̒�`----------
//�Q�[���I�����\�b�h
bool CentralControl::GameStart() {

	//�Q�[���I�����\�b�h������āABJ���Ăяo�����I���ł���悤�ȍ��ɂ���
	bool endSelect = true;

	while (GameSelect(endSelect)) {

	}
	return false;
}

//�Q�[���I��
bool CentralControl::GameSelect(bool truth){
	//�N���X��Switch���őI�𐫂ɂ��āA�Q�[����S��Start���\�b�h�œ��ꂵ�Ă���
	BlackJack blackjack;

	std::cout <<"BJ�X�^�[�g\n";
	std::cout << "----------------------------------------\n";
	truth = blackjack.Start();

	return truth;
}