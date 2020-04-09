#include "header.h"

BigInteger::BigInteger()
{
    sign = plus_sign;
    number = BigNatural();
}

BigInteger &BigInteger::operator=(BigInteger const &BigInt)
{
    sign = BigInt.sign;
    number = BigNatural(BigInt.number);
    return *this;
}

BigInteger::BigInteger(int number)
{
    if (number < 0)
    {
        number = -number;
        sign = minus_sign;
    }
    else
        sign = plus_sign;
    this->number = BigNatural(number);
}

BigInteger::BigInteger(const BigInteger &BigInt)
{
    sign = BigInt.sign;
    number = BigNatural(BigInt.number);
}

BigInteger::BigInteger(std::string string)
{
    if (string[0] == '-')
    {
        sign = minus_sign;
        number = BigNatural(string.erase(0, 1));
    }
    else
    {
        sign = plus_sign;
        number = BigNatural(string);
    }
}
std::string BigInteger::ToString()
{
    if (sign == minus_sign)
    {
        std::string strBigN;
        strBigN += '-';
        strBigN += number.ToString();
        return strBigN;
    }
    else
        return number.ToString();
}
