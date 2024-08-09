#pragma once
#include"List.h"
#include <functional>
#include <array>


///@brief ハッシュテーブルのクラスです。
///@tparam KeyType キーの型
///@tparam DataType 値の型
///@tparam Hash ハッシュ関数
///@tparam packetSize パケットのサイズ
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

	///@brief コンストラクタです。
	HashTable() = default;

	///@brief データ数を返します。
	///@return データの数
	size_t size()const;

	///@brief ハッシュテーブルに新たな要素を追加します。
	///@param key 追加するキー
	///@param data 追加するデータ
	///@return 追加に成功したらtrue 失敗したらfalse
	///@detail 既に存在するキーを渡すと失敗します。
	bool insert(const KeyType& key, const DataType& data);

	///@brief ハッシュテーブルから要素を削除します。
	///@param key 削除するキー
	///@return 削除に成功したらtrue 失敗したらfalse
	///@detail 存在しないキーを渡すと失敗します。
	bool remove(const KeyType& key);

	///@brief ハッシュテーブルの要素を検索します。
	///@param key 検索するキー
	///@param data 検索したデータを受け取る変数
	///@return 検索に成功したらtrue 失敗したらfalse
	///@detail 存在しないキーを渡すと失敗します。
	bool search(const KeyType& key, DataType& data)const;

private:

	//! データを入れるリストの配列
	std::array<List<Pair>,PacketSize>m_table;

	//! データの数
	size_t m_size = 0;

};

#include"HashTable.inl"
