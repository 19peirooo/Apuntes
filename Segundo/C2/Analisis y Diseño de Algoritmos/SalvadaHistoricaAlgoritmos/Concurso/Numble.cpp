#include "../assertdomjudge.h"
using namespace std;

void imprimir(int* lista, int n) {
    for (int i = 0; i < n; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;
}

void Numble(int n, int suma, int* nums, int indice) {

    if (suma > n) {
        return;
    }

    if (n == suma && indice == 4) {
        imprimir(nums,4);
        return;
    }

    if (nums[indice] != -1) {
        suma += nums[indice];
        Numble(n,suma,nums,indice+1);
    } else {
        for (int i = 0; i < 10; i++) {
            nums[indice] = i;
            Numble(n,suma+i,nums,indice+1);
            nums[indice] = -1;
        }
    }

}

int main(int argc, char const *argv[])
{
    int nums[4];
    int n;

    for (int i = 0; i < 4; i++) {
        cin >> nums[i];
        assertdomjudge(nums[i] >= -1 && nums[i] <= 9);
    }

    cin >> n;
    Numble(n,0,nums,0);
    return 0;
}
