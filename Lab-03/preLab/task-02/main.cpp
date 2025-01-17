#include <iostream>
#include <cmath>
using namespace std;

class Polynomial {
private:
    int* coefficients;
    int maxDegree;

public:
    Polynomial(int max_degree) 
    {
        maxDegree = max_degree;
        coefficients = new int[maxDegree + 1]();
    }

    Polynomial(const Polynomial& obj) 
    {
        maxDegree = obj.maxDegree;
        coefficients = new int[maxDegree + 1];
        for (int i = 0; i <= maxDegree; i++) 
        {
            coefficients[i] = obj.coefficients[i];
        }
    }

    ~Polynomial() 
    {
        delete[] coefficients;
    }

    int get_degree() const 
    {
        for (int i = maxDegree; i >= 0; i--) 
        {
            if (coefficients[i] != 0) 
            {
                return i;
            }
        }
        return 0;
    }

    Polynomial& operator = (const Polynomial& other) 
    {
        if (this == &other) return *this;
        delete[] coefficients;
        maxDegree = other.maxDegree;
        coefficients = new int[maxDegree + 1];
        for (int i = 0; i <= maxDegree; i++) 
        {
            coefficients[i] = other.coefficients[i];
        }
        return *this;
    }

    void add_term(int coefficient, int degree) 
    {
        if (degree > maxDegree) throw out_of_range("Degree exceeds max limit.");
        coefficients[degree] = coefficient;
    }

    void remove_term(int degree) 
    {
        if (degree > maxDegree) throw out_of_range("Degree exceeds max limit.");
        coefficients[degree] = 0;
    }

    void set_coefficient(int coefficient, int degree) 
    {
        if (degree > maxDegree) throw out_of_range("Degree exceeds max limit.");
        coefficients[degree] = coefficient;
    }

    friend ostream& operator << (ostream& os, const Polynomial& poly) 
    {
        bool firstTerm = true;
        for (int i = poly.maxDegree; i >= 0; i--) 
        {
            if (poly.coefficients[i] != 0) 
            {
                if (!firstTerm) os << " + ";
                os << poly.coefficients[i] << "x^" << i;
                firstTerm = false;
            }
        }
        if (firstTerm) os << "0";
        return os;
    }

    double operator()(double x) const  
    {
        double result = 0;
        for (int i = 0; i <= maxDegree; i++) 
        {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    Polynomial operator+(const Polynomial& other) 
    {
        int newDegree = max(maxDegree, other.maxDegree);
        Polynomial result(newDegree);
        for (int i = 0; i <= newDegree; i++) 
        {
            result.coefficients[i] = this->coefficients[i] + other.coefficients[i];
        }
        return result;
    }

    Polynomial operator*(const Polynomial& other) 
    {
        int newDegree = maxDegree + other.maxDegree;
        Polynomial result(newDegree);
        for (int i = 0; i <= maxDegree; i++) 
        
        {
            for (int j = 0; j <= other.maxDegree; j++) 
            {
                result.coefficients[i + j] += this->coefficients[i] * other.coefficients[j];
            }
        }
        return result;
    }
};

int main() {
    Polynomial p1(4);
    p1.add_term(5, 4);
    p1.add_term(3, 2);
    p1.add_term(1, 0);
    cout << "Polynomial p1: " << p1 << endl;

    Polynomial p2(4);
    p2.add_term(2, 3);
    p2.add_term(1, 1);
    cout << "Polynomial p2: " << p2 << endl;

    Polynomial sum = p1 + p2;
    cout << "Sum of p1 and p2: " << sum << endl;

    Polynomial product = p1 * p2;
    cout << "Product of p1 and p2: " << product << endl;

    double eval = p1(2);
    cout << "Evaluation of p1 at x=2: " << eval << endl;

    return 0;
}