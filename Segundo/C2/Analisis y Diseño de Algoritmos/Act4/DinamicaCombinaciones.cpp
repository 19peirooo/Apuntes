#include <iostream>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

int** calcularTriangulo() {
    int** pascal = new int*[10];
    for (int i = 0; i < 10; i++){
        pascal[i] = new int[i+1];
        for (int j = 0; j <= i; j++){
            if (j == 0 || j == i) {
                pascal[i][j] = 1;
            } else {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
    }
    return pascal;
}

int main(){
    int n=0,r=0,result=0;

    while (n>=0){
        std::cin>>n;
        std::cin>>r;
        int** trianguloPascal = calcularTriangulo();
        if (n >= 0) {
            assertdomjudge(r >= 0 && n >= r);
            std::cout << trianguloPascal[n][r] << std::endl;
        }
    }
}