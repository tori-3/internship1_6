#include<iostream>
#include"HashTable.h"

#include <string>

///@brief 簡易的なハッシュ関数
///@param key ハッシュ値を求めたい文字列
///@return ハッシュ値
size_t Hash(const std::string& key)
{
	size_t sum = 0;
	for (char c : key) {
		sum += c;
	}
	return sum;
}


int main()
{

	HashTable < std::string, int, Hash, 100 > table;

	table.insert("aaa", 10);
	table.insert("bbb", 20);
	table.insert("ccc", 30);

	table.remove("ccc");

	int temp;
	table.search("bbb", temp);
	std::cout<< temp<< std::endl;

}