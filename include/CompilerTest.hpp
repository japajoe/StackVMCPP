#ifndef STACKVM_COMPILERTEST_HPP
#define STACKVM_COMPILERTEST_HPP

#include "Specification.hpp"
#include "Instruction.hpp"
#include "Assembly.hpp"
#include "StringUtility.hpp"
#include "CompilerUtility.hpp"
#include <map>
#include <vector>
#include <string>
#include <iostream>

namespace StackVM
{
    class CompilerTest
    {
    private:
        Assembly* assembly;
        std::map<std::string, uint32_t> dataMap;
        std::map<std::string, uint32_t> labelMap;
        void WriteError(int lineNumber, const std::string& error);
        bool ProcessToken(std::vector<Token>& tokens, size_t index);
    public:
        CompilerTest();
        bool Compile(const std::string& source, Assembly& assembly);        
    };
}
#endif