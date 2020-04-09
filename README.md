##  **Документация по структурам больших чисел**
####  **1. Натуральные числа** BigNatural
#### **Структура**
Структура натурального числа состоит из двух объектов.
```cpp
int *coef; // динамический массив, где каждая ячейка это цифра в натуральном большом числе
int size; // количество цифр в числе
```
##### **ВАЖНО!!!** **В массиве `coef` цифры хранятся от младших разрядов к старшим.**

Создав экземпляр данной структуры, к ее данным вы можете обращаться следующим образом:
```cpp
BigNatural BigN();
/*
*работа с числом
*/
cout<<BigN.size; //выводит количество цифр в числе
cout<<BigN.coef[i] // выведет i-ю цифру отсчитывая от младшей степени
```
Конструкторы:
```cpp
BigNatural(const BigNatural & BigN); // передать другой объект BigNatural
BigNatural(int * coef, int size); // адрес на массив с цифрами(от меньшего разряда к большему), количество цифр
BigNatural(std::string string);//строка - число
BigNatural(int number); //передаем не длинное число
 //операция присваивания
BigNatural& operator=(BigNatural const& BigN);
```
#### **Методы**
```cpp
std::string ToString(); // возвращает строку, в котором хранится большое число
cout<<BigN.ToString();
```

####  **2. Целые числа** BigInteger
#### **Структура**
```cpp
    Sign sign; //Знак числа
    BigNatural number; //Модуль числа
```
Если наше число положительно, то `sign` возвращает `plus_sign`, если отрицательное `minus_sign`.
Конструкторы:
```cpp
BigInteger(const BigInteger & BigInt);//передаем другой объект BigInteger
BigInteger(int number); // передаем целое число
BigInteger(std::string string); // передаем число в виде строки
//операция присваивания
BigInteger& operator=(BigInteger const& BigInt);
```
#### **Методы**
```cpp
std::string ToString(); // возвращает строку с целым числом
```
####  **3. Рациональная дробь** RationalFraction
#### **Структура**
```cpp
BigInteger numenator; //числитель - целое число
BigNatural denominator; //знаменатель - натуральное число
```
Конструкторы:
```cpp
RationalFraction(const RationalFraction & RacF);//передаем другую рациональную дробь
RationalFraction(std::string numenator, std::string denominator); // передаем два string - числитель и знаменатель
//операция присваивания
RationalFraction& operator=(RationalFraction const& RacF);
```
#### **Методы**
```cpp
std::pair<std::string,std::string> ToString();//возвращает значения числителя и знаменателя с помощью конструктора pair.
```
```cpp
pair.first;//обращение к первому элементу пары
pair.second;//обращение ко второму элементу пары
```
####  **4. Многочлен** Polynom
#### **Структура**
```cpp
int degree;//степень многочлена
RationalFraction* coef;//динамический массив, элементы которого - RationalFraction т.к. коэффициенты многочлена - это рациональные дроби
```
Коэффициенты в массиве хранятся от большей степени к меньшей, а не наоборот, как это было сделано для натуральных чисел.

Конструкторы:
```cpp
    Polynom(RationalFraction* coef, int degree);//массив из RationalFraction, степень многочлена
    Polynom(const Polynom & polynom);//другой полином
    Polynom(std::vector<std::pair<std::string,std::string>> pol, int degree);//есть возможность задать многочлен как вектор пар числителя и знаменателя
    //операция присваивания
    Polynom& operator=(Polynom const& polynom);
```
#### **Методы**
```cpp
std::vector<std::pair<std::string,std::string>> ToString();//возвращаем векторы пар числителя и знаменателя, последний элемент вектора - пара <"end","end">, для того, чтобы понять, до какого элемента делать вывод.
```