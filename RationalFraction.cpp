#include "header.h"

RationalFraction::RationalFraction()
{
    numenator = BigInteger();
    denominator = BigNatural();
    denominator.coef[0] = 1;
}

RationalFraction &RationalFraction::operator=(RationalFraction const &RacF)
{
    numenator = BigInteger(RacF.numenator);
    denominator = BigNatural(RacF.denominator);
    return *this;
}

RationalFraction::RationalFraction(const RationalFraction &RacF)
{
    numenator = BigInteger(RacF.numenator);
    denominator = BigNatural(RacF.denominator);
}
RationalFraction::RationalFraction(std::string numenator, std::string denominator)
{
    this->numenator = BigInteger(numenator);
    this->denominator = BigNatural(denominator);
}
std::pair<std::string, std::string> RationalFraction::ToString()
{
    return std::make_pair(numenator.ToString(), denominator.ToString());
}
