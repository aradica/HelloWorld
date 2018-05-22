#include <iostream>
using namespace std;

int gcd(int a, int b){
    while (b != 0){
        a, b = b, a%b;
    return a;
    }
}

int main(){
    int n, m;
    cout << "Hello, World!\nGive me two numbers, please: " << endl;
    scanf("%i %i", &n, &m);
    cout << gcd(n, m) << " is the greatest common divisor. Have a nice day!" << endl;
    system("PAUSE");
    return 0;
}