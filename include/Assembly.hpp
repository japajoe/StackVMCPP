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
		std::vector<Type> types;

        Assembly()
        {

        }
	};
}

#endif