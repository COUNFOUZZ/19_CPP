#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

class Serializer {
	private:
		Serializer(void);
		Serializer(const Serializer& src);
		~Serializer(void);

		Serializer& operator=(const Serializer& dest);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif