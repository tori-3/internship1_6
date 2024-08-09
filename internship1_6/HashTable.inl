#pragma once

template<typename KeyType, typename DataType, size_t(*Hash)(const KeyType&), size_t PacketSize>
size_t HashTable<KeyType, DataType, Hash, PacketSize>::size()const
{
	return m_size;
}

template<typename KeyType, typename DataType, size_t(*Hash)(const KeyType&), size_t PacketSize>
bool HashTable<KeyType, DataType, Hash, PacketSize>::insert(const KeyType& key, const DataType& data)
{
	const size_t index = Hash(key) % PacketSize;

	//‚à‚µ‚àŠù‚ÉƒL[‚ª‚ ‚Á‚½‚çfalse‚ğ•Ô‚µ‚ÄI—¹
	for (const auto& pair : m_table[index])
	{
		if (pair.key == key)
		{
			return false;
		}
	}

	m_table[index].add(Pair{ key,data });
	++m_size;
	return true;
}

template<typename KeyType, typename DataType, size_t(*Hash)(const KeyType&), size_t PacketSize>
bool HashTable<KeyType, DataType, Hash, PacketSize>::remove(const KeyType& key)
{
	const size_t index = Hash(key) % PacketSize;

	auto& list = m_table[index];

	for (auto it = list.begin(); it != list.end(); ++it)
	{
		if ((*it).key == key)
		{
			list.remove(it);
			--m_size;
			return true;
		}
	}

	return false;
}

template<typename KeyType, typename DataType, size_t(*Hash)(const KeyType&), size_t PacketSize>
bool HashTable<KeyType, DataType, Hash, PacketSize>::search(const KeyType& key, DataType& data)const
{
	const size_t index = Hash(key) % PacketSize;

	for (const auto& pair : m_table[index])
	{
		if (pair.key == key)
		{
			data = pair.data;
			return true;;
		}
	}

	return false;
}
