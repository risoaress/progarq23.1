#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int opcao;

    cout << "Selecione o arquivo a ser lido:" << endl;
    cout << "1. arquivo1.txt" << endl;
    cout << "2. arquivo2.txt" << endl;
    cout << "3. arquivo3.txt" << endl;
    cin >> opcao;

    ifstream arquivo;

    switch (opcao) {
        case 1:
            arquivo.open("arquivo1.txt");
            break;
        case 2:
            arquivo.open("arquivo2.txt");
            break;
        case 3:
            arquivo.open("arquivo3.txt");
            break;
        default:
            cout << "Opção inválida." << endl;
            return 1;
    }

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    string linha;
    while (getline(arquivo, linha)) {
        cout << linha << endl;
    }

    arquivo.close();

    return 0;
}
