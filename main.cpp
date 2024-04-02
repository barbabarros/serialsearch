#include <iostream>
#include <cstring>
#include <chrono>

using namespace std;

struct teste {
    int codigo;
    string nome;
};

/*void leitura (teste t[]) {
    for (int i = 0; i < 5; i++) {
        cout << "Digite o codigo: ";
        cin >> t[i].codigo;
        cout << "Digite o nome: ";
        cin >> t[i].nome;
    }
}*/

void serial(teste t[]) {
    int busca;
    cout << "Qual o codigo? for(vazio) ";
    cin >> busca;
    auto inicio = chrono::high_resolution_clock::now();

    int i = 0;
    for (; busca > t[i].codigo && i < 10; i++) {}
    if (busca == t[i].codigo) {
        cout << "for(vazio) " << i+1 << "x" << " Codigo: " << t[i].codigo << " Nome: " << t[i].nome << endl << endl;
    }

    auto final = chrono::high_resolution_clock::now();
    auto tempo = chrono::duration_cast<chrono::microseconds>(final - inicio);
    cout << "Tempo decorrido: " << tempo.count() << " microssegundos" << endl << endl;
}

void serial1(teste t[]) {
    int busca;
    cout << "Qual o codigo? for() ";
    cin >> busca;
    auto inicio = chrono::high_resolution_clock::now();

    int i = 0;
    for (; busca >= t[i].codigo && i < 10; i++) {
        if (busca == t[i].codigo) {
            cout << "for() " << i+1 << "x" << " Codigo: " << t[i].codigo << " Nome: " << t[i].nome << endl << endl;
        }
    }

    auto final = chrono::high_resolution_clock::now();
    auto tempo = chrono::duration_cast<chrono::microseconds>(final - inicio);
    cout << "Tempo decorrido: " << tempo.count() << " microssegundos" << endl << endl;
}

void serial2(teste t[]) {
    int busca;
    cout << "Qual o codigo? while() ";
    cin >> busca;
    auto inicio = chrono::high_resolution_clock::now();

    int i = 0;
    while (busca > t[i].codigo && i < 10) i++;
    if (busca == t[i].codigo) {
        cout << "while() " << i+1 << "x" << " Codigo: " << t[i].codigo << " Nome: " << t[i].nome << endl << endl;
    }

    auto final = chrono::high_resolution_clock::now();
    auto tempo = chrono::duration_cast<chrono::microseconds>(final - inicio);
    cout << "Tempo decorrido: " << tempo.count() << " microssegundos" << endl << endl;
}


int main() {
    teste t[10] = {
        {2,"aa"},
        {3,"aa"},
        {4,"aa"},
        {5,"aa"},
        {8,"aa"},
        {11,"aa"},
        {21,"aa"},
        {22,"aa"},
        {330,"aa"},
        {5600,"aa"},
    };
    //leitura(t);
    serial(t);
    serial1(t);
    serial2(t);
}
