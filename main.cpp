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

int main(void)
{
    std::clog << "Tests with fundamental types:" << std::endl;
    GenericType vGeneric;

    {
        std::clog << "\tbool:" << std::endl;
        bool vReal = true;
        vGeneric = vReal;
        std::clog << "\t\tReal: " << vReal << std::endl;
        std::clog << "\t\tGenericType: " << vGeneric << std::endl;
        std::clog << "\t\tVerification: " << (vReal == vGeneric) << std::endl;
    }
    {
        std::clog << "\tunsigned:" << std::endl;
        unsigned vReal = 10;
        vGeneric = vReal;
        std::clog << "\t\tReal: " << vReal << std::endl;
        std::clog << "\t\tGenericType: " << vGeneric << std::endl;
        std::clog << "\t\tVerification: " << (vReal == vGeneric) << std::endl;
    }
    {
        std::clog << "\tint:" << std::endl;
        int vReal = -10;
        GenericType vGeneric;
        vGeneric = vReal;
        std::clog << "\t\tReal: " << vReal << std::endl;
        std::clog << "\t\tGenericType: " << vGeneric << std::endl;
        std::clog << "\t\tVerification: " << (vReal == vGeneric) << std::endl;
    }
    {
        std::clog << "\tdouble:" << std::endl;
        double vReal = 10.10;
        GenericType vGeneric;
        vGeneric = vReal;
        std::clog << "\t\tReal: " << vReal << std::endl;
        std::clog << "\t\tGenericType: " << vGeneric << std::endl;
        std::clog << "\t\tVerification: " << (vReal == vGeneric) << std::endl;
    }
    {
        std::clog << "\tchar*:" << std::endl;
        const char* vReal = "ok";
        GenericType vGeneric;
        vGeneric = vReal;
        std::clog << "\t\tReal: " << vReal << std::endl;
        std::clog << "\t\tGenericType: " << vGeneric << std::endl;
        std::clog << "\t\tVerification: " << (vReal == vGeneric) << std::endl;
    }

    return 0;
}
