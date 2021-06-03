#ifndef STACKVM_ASSEMBLY_HPP
#define STACKVM_ASSEMBLY_HPP

#include "Specification.hpp"
#include "Instruction.hpp"
#include <vector>
#include <cstdint>

namespace StackVM
{
	class Assembly
	{
	public:
		std::vector<Instruction> instructions;
		std::vector<byte> data;
		std::vector<uint32_t> indices;
		std::vector<Type> types;

        Assembly()
        {

        }
		
		byte* GetDataAtIndex(uint32_t index)
		{
			return index >= indices.size() ? nullptr : &data[indices[index]];
		}

		byte* GetDataAtIndex(uint32_t index, Type& type)
		{
			if(index >= indices.size())
				return nullptr;
			type = types[index];

			return &data[indices[index]];
		}
	};
}

#endif