#include <iostream>
#include <algorithm>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int den) : numerator(num), denominator(den) {
        simplify();
    }

    // Hàm rút gọn phân số
    void simplify() {
        int gcd = std::__gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    // Hàm in ra phân số
    void print() {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    // Phép cộng hai phân số
    Fraction operator+(const Fraction &other) {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    // Phép trừ hai phân số
    Fraction operator-(const Fraction &other) {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    // Phép nhân hai phân số
    Fraction operator*(const Fraction &other) {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    // Phép chia hai phân số
    Fraction operator/(const Fraction &other) {
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }
};

int main() {
    Fraction f1(2, 3);
    Fraction f2(3, 4);

    Fraction sum = f1 + f2;
    Fraction difference = f1 - f2;
    Fraction product = f1 * f2;
    Fraction quotient = f1 / f2;

    std::cout << "Sum: ";
    sum.print();
    std::cout << "Difference: ";
    difference.print();
    std::cout << "Product: ";
    product.print();
    std::cout << "Quotient: ";
    quotient.print();

    return 0;
}
