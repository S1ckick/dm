#include "header.h"
BigNatural::BigNatural()
{
    size = 1;
    coef = new int[1];
    coef[0] = 0;
}

BigNatural::~BigNatural()
{
    delete[] coef;
}

//Получаем на вход массив коэффициентов и его размер
BigNatural::BigNatural(int *coef, int size)
{
    this->size = size;
    this->coef = new int[size];
    memcpy(this->coef, coef, size * sizeof(int));
}

//Операция присваивания
BigNatural &BigNatural::operator=(BigNatural const &BigN)
{
    delete[] coef;
    size = BigN.size;
    coef = new int[size];
    memcpy(coef, BigN.coef, size * sizeof(int));
    return *this;
}

BigNatural::BigNatural(const BigNatural &BigN)
{
    size = BigN.size;
    delete[] coef;
    coef = new int[size];
    memcpy(coef, BigN.coef, size * sizeof(int));
}

BigNatural::BigNatural(int number)
{
    int *tmpCoef = nullptr;
    size = 0;
    while (number != 0)
    {
        tmpCoef = (int *)realloc(tmpCoef, (size + 1) * sizeof(int));
        tmpCoef[size] = number % 10;
        number /= 10;
        size++;
    }
    coef = new int[size];
    memcpy(coef, tmpCoef, size * sizeof(int));
    free(tmpCoef);
}

BigNatural::BigNatural(std::string string)
{
    size = string.length();
    coef = new int[size];
    for (int i = size; i > 0; i--)
    {
        coef[i - 1] = string[abs(size - i)] - '0';
    }
}

std::string BigNatural::ToString()
{
    std::string str;
    for (int i = size; i > 0; i--)
    {
        str += std::to_string(coef[i - 1]);
    }
    return str;
}