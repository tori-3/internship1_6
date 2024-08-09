#pragma once
#include<string>

///@brief 簡易的なハッシュ関数
///@param key ハッシュ値を求めたい文字列
///@return ハッシュ値
size_t Hash(const std::string& key);
