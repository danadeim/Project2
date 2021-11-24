#include <iostream>
using namespace std;

class Frac {
private:
	int num;
	int den;


public:
	Frac(int n = 0, int d = 1) {
		if (d == 0) {
			n = 0;
			d = 1;
			exit(0);
		}
		else {
			num = n;
			den = d;
		}
	}


	Frac() {
		num = 0;
		den = 0;
	}

	friend Frac operator+(const Frac& x, const Frac& y);
	friend Frac operator-(const Frac& x, const Frac& y);
	friend Frac operator*(const Frac& x, const Frac& y);
	friend Frac operator/(const Frac& x, const Frac& y);

	friend ostream& operator<<(ostream& os, const Frac& f1) {
		os << f1.num << '/' << f1.den;
		return os;
	}
};

int gcd(int n, int d) {
	int rem;
	while (d != 0) {
		rem = n % d;
		n = d;
		d = rem;
	}
	return n;
}

Frac operator+(const Frac& x, const Frac& y) {
	int n = x.num * y.den + x.den * y.num;
	int d = x.den * y.den;
	return Frac(n / gcd(n, d), d / gcd(n, d));
}


Frac operator-(const Frac& x, const Frac& y) {
	int n = x.num * y.den - x.den * y.num;
	int d = x.den * y.den;
	return Frac(n / gcd(n, d), d / gcd(n, d));
}


Frac operator*(const Frac& x, const Frac& y) {
	int n = x.num * y.num;
	int d = x.den * y.den;
	return Frac(n / gcd(n, d), d / gcd(n, d));
}


Frac operator/(const Frac& x, const Frac& y) {
	int n = x.num * y.den;
	int d = x.den * y.num;
	return Frac(n / gcd(n, d), d / gcd(n, d));
}

int main() {
	Frac a(2), b(4, 10), c(24, -15), x(1, -3), y(2, 6);

	std::cout << -2 * ((a + b) * 5 - 4) / c << " "
		<< (7 + x + y * 1114 / 111) << std::endl;
}