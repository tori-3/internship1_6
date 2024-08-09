#include "pch.h"
#include"manualTest.h"
#include"../internship1_6/HashTable.h"
#include"hash.h"

///@brief 型が間違ったハッシュ関数です。
size_t InvalidHash(int) 
{
	return 0;
}

/**********************************************************************************//**
	@brief		ハッシュテーブル　クラスの挙動　不適切なハッシュ関数がテンプレート引数で渡された時
	@details	ID:ハッシュテーブル-0(手動)\n
				ハッシュテーブルの挙動のテストです。
				有効にしてコンパイルエラーになれば成功です。\n
				TEST_HASH_TABLE_BEHAVIOR_INVALID_HASH_FUNCTIONマクロを定義すると有効になります。\n
*//***********************************************************************************/

TEST(TestHashTableBehavior,InvalidHashFunction)
{
#ifdef TEST_HASH_TABLE_BEHAVIOR_INVALID_HASH_FUNCTION
	HashTable < std::string, int, InvalidHash, 100 > table;
#endif
}

/**********************************************************************************//**
	@brief		ハッシュテーブル　データ数の取得　constのメソッドであるか
	@details	ID:ハッシュテーブル-12(手動)\n
				ハッシュテーブルのデータ数の取得のテストです。
				有効にしてコンパイルが通れば成功です。\n
				TEST_HASH_TABLE_SIZE_IS_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/

TEST(TestHashTableSize, IsConst)
{
#ifdef TEST_HASH_TABLE_SIZE_IS_CONST
	const HashTable < std::string, int, Hash, 100 > table;
	table.size();
#endif
}

/**********************************************************************************//**
	@brief		ハッシュテーブル　データの挿入　非constのメソッドであるか
	@details	ID:ハッシュテーブル-18(手動)\n
				ハッシュテーブルのデータの挿入のテストです。
				有効にしてコンパイルエラーになれば成功です。\n
				TEST_HASH_TABLE_INSERT_IS_NOT_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/

TEST(TestHashTableInsert, IsNotConst)
{
#ifdef TEST_HASH_TABLE_INSERT_IS_NOT_CONST
	const HashTable < std::string, int, Hash, 100 > table;
	table.insert("hoge",0);
#endif
}

///**********************************************************************************//**
//	@brief		ハッシュテーブル　データの削除　非constのメソッドであるか
//	@details	ID:ハッシュテーブル-26(手動)\n
//				ハッシュテーブルのデータの削除のテストです。
//				有効にしてコンパイルエラーになれば成功です。\n
//				TEST_HASH_TABLE_REMOVE_IS_NOT_CONSTマクロを定義すると有効になります。\n
//*//***********************************************************************************/

TEST(TestHashTableRemove, IsNotConst)
{
#ifdef TEST_HASH_TABLE_REMOVE_IS_NOT_CONST
	const HashTable < std::string, int, Hash, 100 > table;
	table.remove("hoge");
#endif
}

///**********************************************************************************//**
//	@brief		ハッシュテーブル　データの検索　constメソッドであるか
//	@details	ID:ハッシュテーブル-34(手動)\n
//				ハッシュテーブルのデータの検索のテストです。
//				有効にしてコンパイルが通れば成功です。\n
//				TEST_HASH_TABLE_SERCH_IS_CONSTマクロを定義すると有効になります。\n
//*//***********************************************************************************/

TEST(TestHashTableSerch, IsConst)
{
#ifdef TEST_HASH_TABLE_SERCH_IS_CONST
	const HashTable < std::string, int, Hash, 100 > table;
	int temp;
	table.search("hoge",temp);
#endif
}
