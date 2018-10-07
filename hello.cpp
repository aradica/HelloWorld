#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Fraction{
    //  n/d
    int n, d;
    Fraction(int numerator = 0, int denomintaor = 1){
        //if both are negative they cancel out OR if d < 0 then pass it to n for easier computation
        if((numerator < 0 && denomintaor < 0) || (denomintaor < 0)){

            numerator *= -1;
            denomintaor *= -1;
        }
        int g = abs(__gcd(numerator, denomintaor));
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
        Fraction f2 = other.inverse();
        int g1 = __gcd(n, other.d);
        int g2 = __gcd(other.n, d);
        return Fraction((n/g1) * (f2.n/g2), (d/g2) * (f2.d/g1));
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
    Fraction f1(2, 5);
    Fraction f2(-1, 5);
    Fraction f3 = f1+f2;
    f3.print();
    return 0;
}
