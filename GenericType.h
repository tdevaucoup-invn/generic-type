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

#ifndef GENERIC_TYPE_H
#define GENERIC_TYPE_H

#include <string>
#include <map>
#include <iostream>

/**
* \class GenericType
* \brief Store any fundamental types
*/
class GenericType
{
public:
    /**
    * \brief Enumerator to define a type
    */
    enum Type {
        None,        /*!< No type, the default */
        Boolean,     /*!< Type bool */
        Unsigned,    /*!< Type unsigned */
        Int,         /*!< Type int */
        Double,      /*!< Type double */
        String,      /*!< Type const char* */
    };

    /**
    * \brief Default constructor
    */
    GenericType(void);

    /**
    * \brief Copy constructor
    * \param[in] axObject: an other object
    */
    GenericType(GenericType const &axObject);

    /**
    * \brief Assignment constructor
    * \param[in] axObject: an other object
    */
    GenericType& operator=(GenericType const &axObject);

    /**
    * \brief Default destructor
    */
    ~GenericType(void);

    Type type(void) const; //!< getter
    bool isType(Type aType) const; //!< check if type is the current type

    /**
    * \brief Equality operator
    * \param axL: left
    * \param axR: right
    */
    friend bool operator==(const GenericType& axL, const GenericType& axR);

    /**
    * \brief Inequality operator
    * \param axL: left
    * \param axR: right
    */
    friend bool operator!=(const GenericType& axL, const GenericType& axR) { return !(axL == axR); }

    /**
    * \brief Stream output operator
    * \param axStream: the stream
    * \param axGeneric: the GenericType
    * \return the stream including the GenericType
    * \throw std::invalid_argument if this operation are not supported
    */
    friend std::ostream& operator<<(std::ostream &axStream, const GenericType& axGeneric);

    #define CONVERSIONS(TYPE, ENUM, MEMBER) \
    explicit GenericType(TYPE aVal) : __type(ENUM) \
    { \
        __realTypes.MEMBER = aVal; \
    } \
    operator TYPE & () \
    { \
        __check(ENUM); \
        return __realTypes.MEMBER; \
    } \
    operator TYPE const & () const \
    { \
        __check(ENUM); \
        return __realTypes.MEMBER; \
    } \
    GenericType& operator=(TYPE aVal) \
    { \
        __type = ENUM;  \
        __realTypes.MEMBER = aVal; \
        return *this; \
    }

    #define OVERLOADS(TYPE, ENUM, MEMBER) \
    friend bool operator==(const TYPE& axL, const GenericType& axR) \
    { \
        axR.__check(ENUM); \
        return axL == static_cast<TYPE>(axR); \
    }

    /**
    * \brief Convert bool to GenericType
    */
    CONVERSIONS(bool, Boolean, b);
    OVERLOADS(bool, Boolean, b);
    /**
    * \brief Convert unsigned int to GenericType
    */
    CONVERSIONS(unsigned, Unsigned, u);
    OVERLOADS(unsigned, Unsigned, u);
    /**
    * \brief Convert int to GenericType
    */
    CONVERSIONS(int, Int, i);
    OVERLOADS(int, Int, i);
    /**
    * \brief Convert double to GenericType
    */
    CONVERSIONS(double, Double, d);
    OVERLOADS(double, Double, d);
    /**
    * \brief Convert string to GenericType
    */
    CONVERSIONS(const char*, String, s);
    friend bool operator==(const char* axL, const GenericType& axR);

private:
    Type __type; /*!< the current type stored */

    /**
    * \brief The real types stored
    */
    union COMMON_TYPES {
        bool b;             /*!< Type bool */
        unsigned u;         /*!< Type unsigned */
        int i;              /*!< Type int */
        double d;           /*!< Type double */
        const char* s;      /*!< Type const char* */
    } __realTypes;

    /**
    * \brief Check if the class takes the type into account
    * \param aType: the desired type
    * \throw std::invalid_argument if not
    */
    void __check(Type aType) const;

    static const std::map<Type, std::string> __yToString; /*!< Map to convert GenericType::Type to std::string */
    static std::map<Type, std::string> __initToString(void); /*!< Method to initiate the __yToString map */
};

#endif // GENERIC_TYPE_H
