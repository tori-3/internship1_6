#include "pch.h"
#include"manualTest.h"
#include"../internship1_6/HashTable.h"
#include"hash.h"

///@brief �^���Ԉ�����n�b�V���֐��ł��B
size_t InvalidHash(int) 
{
	return 0;
}

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u���@�N���X�̋����@�s�K�؂ȃn�b�V���֐����e���v���[�g�����œn���ꂽ��
	@details	ID:�n�b�V���e�[�u��-0(�蓮)\n
				�n�b�V���e�[�u���̋����̃e�X�g�ł��B
				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
				TEST_HASH_TABLE_BEHAVIOR_INVALID_HASH_FUNCTION�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/

TEST(TestHashTableBehavior,InvalidHashFunction)
{
#ifdef TEST_HASH_TABLE_BEHAVIOR_INVALID_HASH_FUNCTION
	HashTable < std::string, int, InvalidHash, 100 > table;
#endif
}

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u���@�f�[�^���̎擾�@const�̃��\�b�h�ł��邩
	@details	ID:�n�b�V���e�[�u��-12(�蓮)\n
				�n�b�V���e�[�u���̃f�[�^���̎擾�̃e�X�g�ł��B
				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
				TEST_HASH_TABLE_SIZE_IS_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/

TEST(TestHashTableSize, IsConst)
{
#ifdef TEST_HASH_TABLE_SIZE_IS_CONST
	const HashTable < std::string, int, Hash, 100 > table;
	table.size();
#endif
}

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u���@�f�[�^�̑}���@��const�̃��\�b�h�ł��邩
	@details	ID:�n�b�V���e�[�u��-18(�蓮)\n
				�n�b�V���e�[�u���̃f�[�^�̑}���̃e�X�g�ł��B
				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
				TEST_HASH_TABLE_INSERT_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/

TEST(TestHashTableInsert, IsNotConst)
{
#ifdef TEST_HASH_TABLE_INSERT_IS_NOT_CONST
	const HashTable < std::string, int, Hash, 100 > table;
	table.insert("hoge",0);
#endif
}

///**********************************************************************************//**
//	@brief		�n�b�V���e�[�u���@�f�[�^�̍폜�@��const�̃��\�b�h�ł��邩
//	@details	ID:�n�b�V���e�[�u��-26(�蓮)\n
//				�n�b�V���e�[�u���̃f�[�^�̍폜�̃e�X�g�ł��B
//				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
//				TEST_HASH_TABLE_REMOVE_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
//*//***********************************************************************************/

TEST(TestHashTableRemove, IsNotConst)
{
#ifdef TEST_HASH_TABLE_REMOVE_IS_NOT_CONST
	const HashTable < std::string, int, Hash, 100 > table;
	table.remove("hoge");
#endif
}

///**********************************************************************************//**
//	@brief		�n�b�V���e�[�u���@�f�[�^�̌����@const���\�b�h�ł��邩
//	@details	ID:�n�b�V���e�[�u��-34(�蓮)\n
//				�n�b�V���e�[�u���̃f�[�^�̌����̃e�X�g�ł��B
//				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł��B\n
//				TEST_HASH_TABLE_SERCH_IS_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
//*//***********************************************************************************/

TEST(TestHashTableSerch, IsConst)
{
#ifdef TEST_HASH_TABLE_SERCH_IS_CONST
	const HashTable < std::string, int, Hash, 100 > table;
	int temp;
	table.search("hoge",temp);
#endif
}
