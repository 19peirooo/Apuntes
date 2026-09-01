
#include "../assertdomjudge.h"
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    assertdomjudge(n >= 0);
    cout << fibonacci(n) << endl; 
    return 0;
}
