#pragma once
#include"List.h"
#include <functional>
#include <array>


///@brief �n�b�V���e�[�u���̃N���X�ł��B
///@tparam KeyType �L�[�̌^
///@tparam DataType �l�̌^
///@tparam Hash �n�b�V���֐�
///@tparam packetSize �p�P�b�g�̃T�C�Y
template<typename KeyType,typename DataType, size_t (*Hash)(const KeyType&),size_t PacketSize>
class HashTable
{
private:

	struct Pair 
	{
		KeyType key;

		DataType data;
	};


public:

	///@brief �R���X�g���N�^�ł��B
	HashTable() = default;

	///@brief �f�[�^����Ԃ��܂��B
	///@return �f�[�^�̐�
	size_t size()const;

	///@brief �n�b�V���e�[�u���ɐV���ȗv�f��ǉ����܂��B
	///@param key �ǉ�����L�[
	///@param data �ǉ�����f�[�^
	///@return �ǉ��ɐ���������true ���s������false
	///@detail ���ɑ��݂���L�[��n���Ǝ��s���܂��B
	bool insert(const KeyType& key, const DataType& data);

	///@brief �n�b�V���e�[�u������v�f���폜���܂��B
	///@param key �폜����L�[
	///@return �폜�ɐ���������true ���s������false
	///@detail ���݂��Ȃ��L�[��n���Ǝ��s���܂��B
	bool remove(const KeyType& key);

	///@brief �n�b�V���e�[�u���̗v�f���������܂��B
	///@param key ��������L�[
	///@param data ���������f�[�^���󂯎��ϐ�
	///@return �����ɐ���������true ���s������false
	///@detail ���݂��Ȃ��L�[��n���Ǝ��s���܂��B
	bool search(const KeyType& key, DataType& data)const;

private:

	//! �f�[�^�����郊�X�g�̔z��
	std::array<List<Pair>,PacketSize>m_table;

	//! �f�[�^�̐�
	size_t m_size = 0;

};

#include"HashTable.inl"
