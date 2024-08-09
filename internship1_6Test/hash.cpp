#include "pch.h"
#include"hash.h"

size_t Hash(const std::string& key)
{
	size_t sum = 0;
	for (char c : key) {
		sum += c;
	}
	return sum;
}
