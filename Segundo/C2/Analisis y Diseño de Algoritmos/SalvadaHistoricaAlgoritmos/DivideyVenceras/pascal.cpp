#include "../assertdomjudge.h"
using namespace std;

int** generarPascal(int n){
    int** pascal = new int*[n];
    for (int i = 0; i < n; i++){
        pascal[i] = new int[i+1];
        for (int j = 0; j < i+1; j++) {
            if (j == 0 || j == i) {
                pascal[i][j] = 1;
            } else {
                pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
            }
        }
    }
    return pascal;
}

int main(int argc, char const *argv[])
{
    int tam;
    int n = 1;
    int r;

    cin >> tam;
    assertdomjudge(tam > 0);
    int** pascal = generarPascal(tam);
    while (n >= 0) {
        cin >> n;
        cin >> r;
        
        if (n >= 0) {
            assertdomjudge(tam > n && r >= 0 && n >= r);
            cout << pascal[n][r] << endl;
        }
    }
    
    return 0;
}
