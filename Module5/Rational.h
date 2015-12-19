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

  Rational();
  // Constructor that only takes only one number
  Rational(Tint P);

  // Constructor that takes two numbers
  Rational(Tint P, Tint Q);

  // Copy constructor
  Rational(const Rational<int>& rhs);
  Rational(const Rational<short>& rhs);



  //############## Arithmetic operatins ##################
  // Addition operator
  Rational operator+(const Rational<Tint> &rhs) const
  {
    Rational<Tint> temp;
    if (denom == rhs.denom) {
      temp.nom = static_cast<Tint> (nom + rhs.nom);
      temp.denom = denom;
    } else {
      temp.nom = ((nom*rhs.denom) + (denom*rhs.nom));
      temp.denom = (denom*rhs.denom);
    }

    Reduce(temp.nom, temp.denom);

    return temp;
  }

  // Addition equal operator
  Rational operator+=(const Rational<Tint> &rhs) const
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
  Rational operator=(const Rational<int>& rhs)
  {
    nom = rhs.nom;
    denom = rhs.denom;
    return *this;
  }

  Rational operator=(const Rational<short>& rhs)
  {
    nom = rhs.nom;
    denom = rhs.denom;
    return *this;
  }

  Rational operator=(const Rational<long>& rhs)
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

//######### Constructors ###############
// Empty constructor
template <typename Tint>
Rational<Tint>::Rational() : nom(0), denom(1) {};

// Constructor that only takes only one number
template <typename Tint>
Rational<Tint>::Rational(Tint P) : nom(P), denom(1) {};

// Constructor that takes two numbers
template <typename Tint>
Rational<Tint>::Rational(Tint P, Tint Q) : nom(P), denom(Q)
{
  Reduce(nom, denom);
}

// Copy constructor
template <typename Tint>
Rational<Tint>::Rational(const Rational<int>& rhs) : nom(rhs.nom), denom(rhs.denom) {};

// Copy constructor
template <typename Tint>
Rational<Tint>::Rational(const Rational<short>& rhs) : nom(rhs.nom), denom(rhs.denom) {};
