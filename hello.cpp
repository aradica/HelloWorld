#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;


struct Fraction{
    //  n/d
    long int n, d;
    Fraction(long int numerator = 0, long int denomintaor = 1){
        //if both are negative they cancel out OR if d < 0 then pass it to n for easier computation
        if((n < 0 && d < 0) || (d < 0)){
            n = -1*n;
            d = -1*d;
        }
        int g = __gcd(numerator, denomintaor);
        if (g == 1){
            n = numerator;
            d = denomintaor;
        }
        else{
            n = numerator / g;
            d = denomintaor / g;
        }

    }

    Fraction operator + (Fraction const &other){
        if (d == other.d){
            return Fraction(n+other.n, d);
        }
        else{
            int g = __gcd(d, other.d);
            if (g == 1){
                return Fraction(n*other.d + other.n*d, d*other.d);
            }
            else{
                if (d > other.d){
                    return Fraction(n + other.n*(d/other.d), d);
                }
                else{
                    return Fraction(other.n + n*(other.d/d), other.d);
                }
            }
        }
    }

    Fraction operator * (Fraction const &other){
        int g1 = __gcd(n, other.d);
        int g2 = __gcd(other.n, d);
        return Fraction((n/g1) * (other.n/g2), (d/g2) * (other.d/g1));
    }

    Fraction inverse(){
        return Fraction (d, n);
    }

    //todo: make this better
    Fraction operator / (Fraction other){ 
        Fraction f1(n, d);
        Fraction f2 = other.inverse();
        return f1 * f2;
    }
    void print(){
        cout << n << "/" << d << "\n";
    }
    string sign(){
        if (n < 0){
            return "-";
        }
        else if (n == 0){
            return "undefined";
        }
        else{
            return "+";
        }
    }
};


int main(){
    long int N, D;
    cout << "Numerator: ";
    cin >> N;
    cout << "Denominator: ";
    cin >> D;
    Fraction f(N, D);
    f.print();
    cout << f.sign() << "\n";
    return 0;
}
