#include <iostream>
#include "../assertdomjudge.h"

using namespace std;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n*factorial(n-1);
    }
}

int combinacion(int n, int r) {
    return factorial(n)/(factorial(r)*factorial(n-r));
}

int main() {
    int n = 0;
    int r = 0;
    while (n>=0){
        

        std::cin>>n;
        std::cin>>r;
        
        if (n >= 0) {
            assertdomjudge(r >= 0 && n >= r);
            int result = (factorial(n))/((factorial(r))*(factorial(n-r)));
            std::cout << result << std::endl;
        }
    }
}