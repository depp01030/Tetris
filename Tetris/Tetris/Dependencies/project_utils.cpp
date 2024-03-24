#include "project_utils.h"

int getRandom() 
{
	// �ϥ� random_device �Ө��o�H���ƺؤl
	std::random_device rd;

	// �ϥ� Mersenne Twister �����A�����ѤF���~�誺�H���ƥͦ�
	std::mt19937 gen(rd());
	// �ϥ� uniform_int_distribution �өw�q�H���ƪ��d��
	std::uniform_int_distribution<> dis(1, 100); // ���� 1 �� 100 �������H�����
	return dis(gen);
}