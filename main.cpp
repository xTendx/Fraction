#include "operators.h"

int main() {
    Fraction a(2, 5);
    Fraction b(3, 7);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n\n";

    // =================== + ===================
    std::cout << "a + b = " << a + b << "\n";
    std::cout << "a + 2 = " << a + 2 << "\n";
    std::cout << "2 + a = " << 2 + a << "\n\n";

    // =================== - ===================
    std::cout << "a - b = " << a - b << "\n";
    std::cout << "a - 2 = " << a - 2 << "\n";
    std::cout << "2 - a = " << 2 - a << "\n\n";

    // =================== * ===================
    std::cout << "a * b = " << a * b << "\n";
    std::cout << "a * 2 = " << a * 2 << "\n";
    std::cout << "2 * a = " << 2 * a << "\n\n";

    // =================== / ===================
    std::cout << "a / b = " << a / b << "\n";
    std::cout << "a / 2 = " << a / 2 << "\n";
    std::cout << "2 / a = " << 2 / a << "\n\n";

    // =================== ! ===================
    std::cout << "!a = " << !a << "\n\n";

    // =================== == < > ===================
    std::cout << "a == b: " << (a == b) << "\n";
    std::cout << "a < b: " << (a < b) << "\n";
    std::cout << "a > b: " << (a > b) << "\n\n";

    // =================== ++ -- ===================
    Fraction x(1, 2);

    std::cout << "x = " << x << "\n";
    std::cout << "++x = " << ++x << "\n";
    std::cout << "x++ = " << x++ << "\n";
    std::cout << "after x++ = " << x << "\n";

    std::cout << "--x = " << --x << "\n";
    std::cout << "x-- = " << x-- << "\n";
    std::cout << "after x-- = " << x << "\n\n";

    // =================== += ===================
    x = Fraction(1, 2);
    x += b;
    std::cout << "x += b -> " << x << "\n";

    x += 2;
    std::cout << "x += 2 -> " << x << "\n\n";

    // =================== -= ===================
    x = Fraction(3, 4);
    x -= b;
    std::cout << "x -= b -> " << x << "\n";

    x -= 1;
    std::cout << "x -= 1 -> " << x << "\n\n";

    // =================== *= ===================
    x = Fraction(2, 3);
    x *= b;
    std::cout << "x *= b -> " << x << "\n";

    x *= 2;
    std::cout << "x *= 2 -> " << x << "\n\n";

    // =================== /= ===================
    x = Fraction(4, 5);
    x /= b;
    std::cout << "x /= b -> " << x << "\n";

    x /= 2;
    std::cout << "x /= 2 -> " << x << "\n\n";

    // =================== % (potêga) ===================
    Fraction p(2, 3);
    std::cout << "p^3 = " << (p % 3) << "\n\n";

    // =================== float ===================
    std::cout << "float(a) = " << float(a) << "\n\n";

    // =================== input ===================
    Fraction input;
    std::cout << "Enter fraction (np. 3/4): ";
    std::cin >> input;
    std::cout << "You entered: " << input << "\n";

    return 0;


	return 0;
}