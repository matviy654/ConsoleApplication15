#include <iostream>
#include <stdexcept>
using namespace std;

class Fraction {
private:
    int numerator;   
    int denominator; 


    void reduce() {
        int gcd = GCD(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
    }

    int GCD(int a, int b) const {
        return (b == 0) ? a : GCD(b, a % b);
    }

public:
  
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (den == 0) {
            throw invalid_argument("Знаменник не може бути нульовим");
        }
        reduce();
    }

    void input() {
        cout << "Введіть чисельник: ";
        cin >> numerator;
        cout << "Введіть знаменник: ";
        cin >> denominator;
        if (denominator == 0) {
            throw invalid_argument("Знаменник не може бути нульовим");
        }
        reduce();
    }

    void display() const {
        cout << numerator << "/" << denominator << endl;
    }

    
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Ділення на нуль неможливе");
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }
};

int main() {
    try {
        Fraction f1, f2;
        cout << "Введіть перший дріб:" << endl;
        f1.input();
        cout << "Введіть другий дріб:" << endl;
        f2.input();

        Fraction sum = f1 + f2;
        Fraction diff = f1 - f2;
        Fraction prod = f1 * f2;
        Fraction quot = f1 / f2;

        cout << "Сума: ";
        sum.display();

        cout << "Різниця: ";
        diff.display();

        cout << "Добуток: ";
        prod.display();

        cout << "Частка: ";
        quot.display();
    }
    catch (const exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}
