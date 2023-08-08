#include<iostream>
#include<vector>

using namespace std;

vector<int> primeFactors(int n) {
    vector<int> factors;
    int divisor = 2;
    while(n>1){
        while(n%divisor==0){
            factors.push_back(divisor);
            n/=divisor;
        }
        divisor += 1;
    }
    return factors;
}

int GCD(int a, int b){
    if(b==0){
        return a;
    }
    return GCD(b, a%b);
}

long long LCM(int x, int y) {
    return ((x*y)/GCD(x,y));
}

int main(){
    int x, y;
    return 0;
}