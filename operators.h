#ifndef OPERATORS_H
#define OPERTORS_H

#include <iostream>
#include <ostream>
#include <stdexcept>


class Fraction {
	int numerator;
	int denominator;
public:
	explicit Fraction(int numerator = 0, int denominator = 1);
	//~Fraction();

	void normalize();

	int getNumerator() const { return numerator; }
	int getDenominator() const { return denominator; }
	void setNumerator(int numerator) { this->numerator = numerator; }
	void setDenominator(int denomirator);

	Fraction operator!() const;
	operator float() const;

	//=========================================================================================================================================

	Fraction operator+(const Fraction& F) const;
	Fraction operator+(int x) const;
	friend Fraction operator+(int x, const Fraction& F);

	//=========================================================================================================================================

	Fraction operator-(const Fraction& F) const;
	Fraction operator-(int x) const;
	friend Fraction operator-(int x, const Fraction& F);

	//=========================================================================================================================================

	Fraction operator*(const Fraction& F) const;
	Fraction operator*(int x) const;
	friend Fraction operator*(int x, const Fraction& F);

	//=========================================================================================================================================

	Fraction operator/(const Fraction& F) const;
	Fraction operator/(int x) const;
	friend Fraction operator/(int x, const Fraction& F);

	//=========================================================================================================================================

	bool operator==(const Fraction& F) const;
	bool operator<=(const Fraction& F) const;
	bool operator>=(const Fraction& F) const;
	bool operator<(const Fraction& F) const;
	bool operator>(const Fraction& F) const;

	//=========================================================================================================================================

	Fraction& operator++();
	Fraction& operator--();

	Fraction operator++(int);
	Fraction operator--(int);

	Fraction& operator+=(const Fraction& F);
	Fraction& operator+=(int x);

	Fraction& operator-=(const Fraction& F);
	Fraction& operator-=(int x);

	Fraction& operator*=(const Fraction& F);
	Fraction& operator*=(int x);

	Fraction& operator/=(const Fraction& F);
	Fraction& operator/=(int x);

	friend std::ostream& operator<<(std::ostream& os, const Fraction& F);
	friend std::istream& operator>>(std::istream& is, Fraction& F);
	//===========================================================================================
	Fraction operator%(int x) const;f
};

//new update
//<< >> ++ -- +=















#endif 
