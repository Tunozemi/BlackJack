#ifndef JUDGE_HPP
#define JUDGE_HPP

//----------�N���X�̒�`----------
//���̃N���X��BlackJack�̎d�l�Ƃ��������݂����Ȃ���
class Judge{
public:
	static bool BurstJudge(int cardsum);					//�o�[�X�g����
	static int	VictoryJudge(int cardsum1, int cardsum2);	//��������

private:
	Judge();	//�R���X�g���N�^�̐錾
	~Judge();	//�f�X�g���N�^�̐錾
};
#endif