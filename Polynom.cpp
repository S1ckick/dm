#include "header.h"
using namespace std;
Polynom::Polynom()
{
    coef = new RationalFraction[1];
    coef[0] = RationalFraction();
    degree = 0;
}

Polynom::~Polynom()
{
    delete[] coef;
}

Polynom::Polynom(const Polynom &polynom)
{
    degree = polynom.degree;
    delete[] coef;
    coef = new RationalFraction[degree + 1];
    for (int i = 0; i <= degree; i++)
        coef[i] = RationalFraction(polynom.coef[i]);
}

Polynom::Polynom(RationalFraction *coef, int degree)
{
    this->degree = degree;
    this->coef = new RationalFraction[degree + 1];
    for (int i = 0; i <= degree; i++)
        this->coef[i] = coef[i];
}

Polynom &Polynom::operator=(Polynom const &polynom)
{
    degree = polynom.degree;
    delete[] coef;
    coef = new RationalFraction[degree + 1];
    for (int i = 0; i <= degree; i++)
        coef[i] = RationalFraction(polynom.coef[i]);
    return *this;
}

Polynom::Polynom(poly pol, int degree)
{
    this->degree = degree;
    delete[] coef;
    coef = new RationalFraction[degree + 1];
    for (int i = 0; i <= degree; i++)
        coef[i] = RationalFraction(pol[i].first, pol[i].second);
}
poly Polynom::ToString()
{
    poly pol;
    for (int i = 0; i <= degree; i++)
        pol.push_back(make_pair(coef[i].numenator.ToString(), coef[i].denominator.ToString()));
    pol.push_back(make_pair("end", "end"));
    return pol;
}
