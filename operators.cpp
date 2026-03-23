#include "operators.h"

int gcd(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}



void Fraction::normalize()
{
	if (denominator == 0) {
		throw std::logic_error("Denominator is equal to 0!");
	}

	// move minus to numerator
	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}

	// handle zero numerator
	if (numerator == 0) {
		denominator = 1;
		return;
	}

	// reduce fraction
	int g = gcd(numerator, denominator);
	numerator /= g;
	denominator /= g;
}



Fraction::Fraction(int numerator, int denominator)
{
	if (denominator == 0) {
		throw std::logic_error("Denominator is equal to 0!");
	}

	this->numerator = numerator;
	this->denominator = denominator;
	normalize();
}

//Fraction::~Fraction()
//{
//	std::cout << "===================================\n";
//	std::cout << "Deleted: " << *this << "\n";
//	std::cout << "===================================\n";
//
//}


Fraction Fraction::operator!() const {
	if (numerator == 0) {
		throw std::logic_error("Cannot invert fraction with numerator 0!");
	}
	return Fraction(denominator, numerator);
}


Fraction::operator float() const
{
	return float(numerator) / denominator;
}



void Fraction::setDenominator(int denominator)
{
	if (denominator == 0) {
		throw std::logic_error("Denominator is equal to 0!");
	}
	this->denominator = denominator;

	normalize();
}

//=========================================================================================================================================


Fraction Fraction::operator+(const Fraction& F) const
{
	int newDenominator = lcm(denominator, F.denominator);

	int n1 = numerator * (newDenominator / denominator);
	int n2 = F.numerator * (newDenominator / F.denominator);

	int newNumerator = n1 + n2;

	int g = gcd(newNumerator, newDenominator);

	return Fraction(newNumerator / g, newDenominator / g);
}

Fraction Fraction::operator+(int x) const
{
	return *this + Fraction(x);
}

Fraction operator+(int x, const Fraction& F)
{
	return F + x;
}

//=========================================================================================================================================

Fraction Fraction::operator-(const Fraction& F) const
{
	int newDenominator = lcm(denominator, F.denominator);

	int n1 = numerator * (newDenominator / denominator);
	int n2 = F.numerator * (newDenominator / F.denominator);

	int newNumerator = n1 - n2;

	int g = gcd(newNumerator, newDenominator);

	return Fraction(newNumerator / g, newDenominator / g);
}

Fraction Fraction::operator-(int x) const
{
	return *this - Fraction(x);
}

Fraction operator-(int x, const Fraction& F)
{
	return F - x;
}

//=========================================================================================================================================


Fraction Fraction::operator*(const Fraction& F) const
{
	int n1 = numerator * F.numerator;
	int d1 = denominator * F.denominator;
	int g = gcd(n1, d1);
	return Fraction(n1 / g, d1 / g);
}

Fraction Fraction::operator*(int x) const
{
	return *this * Fraction(x);
}

Fraction operator*(int x, const Fraction& F)
{
	return F * x;
}


//=========================================================================================================================================

Fraction Fraction::operator/(const Fraction& F) const
{
	if (F.numerator == 0) {
		throw std::logic_error("Denominator is equal to 0!");
	}
	return Fraction(*this * !F);
}

Fraction Fraction::operator/(int x) const
{
	if (x == 0) {
		throw std::logic_error("Denominator is equal to 0!");
	}
	return *this / Fraction(x);
}

Fraction operator/(int x, const Fraction& F)
{
	if (x == 0) {
		throw std::logic_error("Denominator is equal to 0!");
	}
	return F / x;
}


//=========================================================================================================================================

bool Fraction::operator==(const Fraction& F) const
{
	return numerator * F.denominator == F.numerator * denominator;
}

bool Fraction::operator<(const Fraction& F) const
{
	return numerator * F.denominator < F.numerator * denominator;
}

bool Fraction::operator>(const Fraction& F) const
{
	return F < *this;
}

//=========================================================================================================================================

Fraction& Fraction::operator++()
{
	numerator += denominator;
	return *this;
}

Fraction& Fraction::operator--() {
	numerator -= denominator;
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction temp = *this;
	numerator += denominator;
	return temp;
}

Fraction Fraction::operator--(int) {
	Fraction temp = *this;
	numerator -= denominator;
	return temp;
}

//=========================================================================================================================================

Fraction& Fraction::operator+=(const Fraction& F)
{
	*this = *this + F;
	return *this;
}

Fraction& Fraction::operator+=(int x)
{
	*this = *this + x;
	return *this;
}


Fraction& Fraction::operator-=(const Fraction& F)
{
	*this = *this - F;
	return *this;
}

Fraction& Fraction::operator-=(int x) {
	*this = *this - x;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& F)
{
	*this = *this * F;
	return *this;
}

Fraction& Fraction::operator*=(int x)
{
	*this = *this * Fraction(x);
	return *this;
}


Fraction& Fraction::operator/=(const Fraction& F)
{
	if (F.numerator == 0) {
		throw std::logic_error("Denominator is equal to 0!");
	}
	*this = *this / F;
	return *this;
}

Fraction& Fraction::operator/=(int x)
{
	if (x == 0) {
		throw std::logic_error("Denominator is equal to 0!");
	}
	*this = *this / x;
	return *this;
}



Fraction Fraction::operator%(int pow) const
{
	if (pow < 0) throw std::logic_error("Negative power not supported");
	int x = 1;
	int y = 1;

	for (int i = 0; i < pow; ++i) {
		x *= numerator;
		y *= denominator;
	}

	return Fraction(x, y);
}


std::ostream& operator<<(std::ostream& os, const Fraction& F)
{
	os << F.numerator << "/" << F.denominator;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& F)
{
	char slash;
	is >> F.numerator >> slash >> F.denominator;
	return is;
}

