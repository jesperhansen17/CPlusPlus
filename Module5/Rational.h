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

  template <typename T>
  explicit operator T() 
  {
    return static_cast<T>(nom/denom);
  }


  //############## Arithmetic operatins ##################
  // Addition equal operator
  Rational& operator+=(const Rational<Tint> &rhs)
  {
    if (denom == rhs.denom) {
      nom = nom + rhs.nom;
      denom = denom;
    } else {
      nom = ((nom*rhs.denom) + (denom*rhs.nom));
      denom = (denom*rhs.denom);
    }
    Reduce(nom, denom);
    return *this;
  }

  // Addition operator
  Rational<Tint> operator+(const Rational<Tint> &rhs) const
  {
    return (Rational)*this += rhs;
  }

  // Increment prefix operator (++)
  Rational<Tint> operator++()
  {
    nom += denom;
    Reduce(nom, denom);
    return *this;
  }

  // Increment postfix operator (++)
  Rational<Tint> operator++(int)
  {
    Rational<Tint> temp = *this;
    nom += denom;
    Reduce(nom, denom);
    return temp;
  }

  // Subtraction operator
  Rational<Tint> operator-()
  {
    return Rational(-nom, denom);
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
