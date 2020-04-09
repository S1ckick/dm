#ifndef UNTITLED3_HEADER_H
#define UNTITLED3_HEADER_H

#include <string>
#include <vector>

typedef std::vector<std::pair<std::string, std::string>> poly;
// BigNatural
/*******************************************************************/
struct BigNatural
{
    int *coef = nullptr; //адрес массива с коэффициентами
    int size; //номер старшей позиции массива
    BigNatural();
    ~BigNatural();
    BigNatural &operator=(BigNatural const &BigN);
    BigNatural(const BigNatural &BigN);
    BigNatural(int *coef, int size);
    explicit BigNatural(std::string string);
    explicit BigNatural(int number);
    std::string ToString();
};
/*******************************************************************/
enum Sign
{
    plus_sign,
    minus_sign
};
// BigInteger
struct BigInteger
{
    Sign sign; //Знак числа
    BigNatural number; //Число
    BigInteger();
    ~BigInteger() = default;
    BigInteger(const BigInteger &BigInt);
    BigInteger &operator=(BigInteger const &BigInt);
    explicit BigInteger(int number);
    explicit BigInteger(std::string string);
    std::string ToString();
};
/*******************************************************************/
struct RationalFraction //Рациональная дробь
{
    BigInteger numenator; //Числитель
    BigNatural denominator; //Знаменатель

    RationalFraction();
    ~RationalFraction() = default;
    RationalFraction &operator=(RationalFraction const &RacF);
    RationalFraction(const RationalFraction &RacF);
    RationalFraction(std::string numenator, std::string denominator);
    std::pair<std::string, std::string> ToString();
};
/*******************************************************************/
struct Polynom //Многочлен
{
    int degree; //Степень многочлена
    RationalFraction *coef = nullptr; //Массив коэффициентов
    Polynom();
    ~Polynom();
    Polynom(RationalFraction *coef, int degree);
    Polynom(const Polynom &polynom);
    Polynom& operator=(Polynom const& polynom);
    Polynom(poly pol, int degree);
    poly ToString();
};
#endif //UNTITLED3_HEADER_H
