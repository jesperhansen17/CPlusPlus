#include <iostream>
#include "GCD.h"
#include "RelOps.h"

template <typename Tint>
class Rational
{
public:
  Tint nom, denom;

  // For printing to the terminal
  friend std::ostream& operator << (std::ostream & cout, Rational<Tint> &R)
  {
    cout << R.nom << '/' << R.denom;
    return cout;
  }

  // For reading to from the terminal
  friend std::istream& operator >> (std::istream & cin, Rational<Tint> &R)
  {
    cin >> R.nom >> R.denom;
    return cin;
  }

  //######### Constructors ###############
  // Empty constructor
  Rational() : nom(0), denom(1) {};

  // Constructor that only takes only one number
  Rational(Tint P) : nom(P), denom(1) {};

  // Constructor that takes two numbers
  Rational(Tint P, Tint Q) : nom(P), denom(Q)
  {
    Reduce(nom, denom);
  }

  // ######### Copy constructors ###############
  template <typename T>
  Rational(const Rational<T>& rhs) : nom(rhs.nom), denom(rhs.denom) {};


  //############## Arithmetic operatins ##################
  // Addition equal operator
  Rational& operator+=(const Rational<Tint> &rhs) const
  {
    Rational<Tint> temp;
    if (denom == rhs.denom) {
      temp.nom = nom + rhs.nom;
      temp.denom = denom;
    } else {
      temp.nom = ((nom*rhs.denom) + (denom*rhs.nom));
      temp.denom = (denom*rhs.denom);
    }

    Reduce(temp.nom, temp.denom);

    return temp;
  }

  // Addition operator
  Rational operator+(const Rational<Tint> &rhs) const
  {
    return (Rational)*this += rhs;
  }

  // Subtraction operator
  Rational operator-(const Rational<Tint> rhs) const
  {
    Rational<Tint> temp;
    if (denom == rhs.denom) {
      temp.nom = nom - rhs.nom;
      temp.denom = denom;
    } else {
      temp.nom = ((nom*rhs.denom) - (denom*rhs.nom));
      temp.denom = (denom*rhs.denom);
    }

    Reduce(temp.nom, temp.denom);

    return temp;
  }

  // Multiplicaton operator
  Rational operator*(const Rational<Tint> rhs) const
  {
    Rational<Tint> temp;
    temp.nom = nom * rhs.nom;
    temp.denom = denom * rhs.denom;

    Reduce(temp.nom, temp.denom);

    return temp;
  }

  // Division operator
  Rational operator/(const Rational<Tint> rhs) const
  {
    Rational<Tint> temp;
    temp.nom = nom * rhs.denom;
    temp.denom = denom * rhs.nom;

    Reduce(temp.nom, temp.denom);

    return temp;
  }

  //########## Assignment operators #####################################
  template <typename T>
  Rational operator=(const Rational<T>& rhs)
  {
    nom = rhs.nom;
    denom = rhs.denom;
    return *this;
  }
  //########## Comparative operators ####################################

  // Compare a Rational number with an Rational number
  friend bool operator==(const Rational<Tint> lhs, const Rational<Tint> rhs)
  {
    return ((lhs.nom == rhs.nom) && (lhs.denom == rhs.denom));
  }

  // Compare a Rational number with an regular number
  friend bool operator==(const Rational<Tint> lhs, const int rhs)
  {
    return (lhs.nom == rhs);
  }

};
