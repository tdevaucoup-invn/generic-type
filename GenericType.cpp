/*
MIT License

Copyright (c) 2019 Théo Devaucoup

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "GenericType.h"

#include <stdexcept>

// init static
std::map<GenericType::Type, std::string> GenericType::__initToString(void)
{
    std::map<GenericType::Type, std::string> vyToString;
    vyToString.insert(std::pair<GenericType::Type, std::string>(GenericType::Unsigned, "unsigned"));
    vyToString.insert(std::pair<GenericType::Type, std::string>(GenericType::Int, "int"));
    vyToString.insert(std::pair<GenericType::Type, std::string>(GenericType::Boolean, "bool"));
    vyToString.insert(std::pair<GenericType::Type, std::string>(GenericType::Double, "double"));
    vyToString.insert(std::pair<GenericType::Type, std::string>(GenericType::String, "char*"));
    return vyToString;
}
const std::map<GenericType::Type, std::string> GenericType::__yToString = __initToString();
//

GenericType::GenericType(void)
: __type(GenericType::None)
{
    ;
}

GenericType::GenericType(GenericType const &axObject)
: __type(axObject.__type)
, __realTypes(axObject.__realTypes)
{
    ;
}

GenericType& GenericType::operator=(GenericType const &axObject)
{
    __type = axObject.__type;
    __realTypes = axObject.__realTypes;
    return *this;
}

GenericType::~GenericType(void)
{
    ;
}

GenericType::Type GenericType::type(void) const
{
    return __type;
}

bool GenericType::isType(GenericType::Type aType) const
{
    return __type == aType;
}

void GenericType::__check(GenericType::Type aType) const
{
    if(!isType(aType)) {
        throw std::invalid_argument("[GenericType::__check] The GenericType needs to be " + __yToString.at(aType));
    }
}

bool operator==(const GenericType& axL, const GenericType& axR)
{
    bool vResult = axL.isType(axR.type());
    if (vResult) {
        switch (axL.type()) {
            case GenericType::Boolean:
            vResult = static_cast<bool>(axL) == static_cast<bool>(axR);
            break;

            case GenericType::Unsigned:
            vResult = static_cast<unsigned>(axL) == static_cast<unsigned>(axR);
            break;

            case GenericType::Int:
            vResult = static_cast<int>(axL) == static_cast<int>(axR);
            break;

            case GenericType::Double:
            vResult = static_cast<double>(axL) == static_cast<double>(axR);
            break;

            case GenericType::String:
            vResult = static_cast<std::string>(axL) == static_cast<std::string>(axR);
            break;

            default:
            vResult = false;
        }
    }
    return vResult;
}

std::ostream& operator<<(std::ostream &axStream, const GenericType& axGeneric)
{
        switch (axGeneric.type()) {
            case GenericType::Boolean:
            axStream << static_cast<bool>(axGeneric);
            break;

            case GenericType::Unsigned:
            axStream << static_cast<unsigned>(axGeneric);
            break;

            case GenericType::Int:
            axStream << static_cast<int>(axGeneric);
            break;

            case GenericType::Double:
            axStream << static_cast<double>(axGeneric);
            break;

            case GenericType::String:
            axStream << static_cast<std::string>(axGeneric);
            break;

            default:
            throw std::invalid_argument("[GenericType::operator<<] Operation not supported");
        }
        return axStream;
}

bool operator==(const char* axL, const GenericType& axR)
{
    axR.__check(GenericType::String);
    return static_cast<std::string>(axL) == static_cast<std::string>(axR);
}
