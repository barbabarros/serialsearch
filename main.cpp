#include <iostream>
#include <cstring>
#include <chrono>

using namespace std;

struct teste {
    int codigo;
    string nome;
};

void leitura (teste t[]) {
    for (int i = 0; i < 5; i++) {
        cout << "Digite o codigo: ";
        cin >> t[i].codigo;
        cout << "Digite o nome: ";
        cin >> t[i].nome;
    }
}

void serial(teste t[]) {
    int busca;
    cout << "Qual o codigo? ";
    cin >> busca;
    auto inicio = chrono::high_resolution_clock::now();
    int i = 0;
    for (; busca > t[i].codigo; i++) {}
    if (busca == t[i].codigo) {
        cout << "for(vazio) ACHEI! Codigo: " << t[i].codigo << " Nome: " << t[i].nome << endl;
    } else cout << "for(vazio) NAO ACHEI!" << endl;
    auto final = chrono::high_resolution_clock::now();
    auto tempo = chrono::duration_cast<chrono::microseconds>(final - inicio);
    cout << "Tempo decorrido: " << tempo.count() << " microssegundos" << endl;
}

void serial1(teste t[]) {
    int busca;
    cout << "Qual o codigo? ";
    cin >> busca;
    auto inicio = chrono::high_resolution_clock::now();
    int i = 0;
    for (; busca >= t[i].codigo; i++) {
        if (busca == t[i].codigo) {
            cout << "for() ACHEI! Codigo: " << t[i].codigo << " Nome: " << t[i].nome << endl;
        } else cout << "for() NAO ACHEI!" << endl;  
    }
    auto final = chrono::high_resolution_clock::now();
    auto tempo = chrono::duration_cast<chrono::microseconds>(final - inicio);
    cout << "Tempo decorrido: " << tempo.count() << " microssegundos" << endl;
}

void serial2(teste t[]) {
    int busca;
    cout << "Qual o codigo? ";
    cin >> busca;
    auto inicio = chrono::high_resolution_clock::now();
    int i = 0;
    while (busca > t[i].codigo) {
        i++;
    }
    if (busca == t[i].codigo) {
        cout << "while() ACHEI! Codigo: " << t[i].codigo << " Nome: " << t[i].nome << endl;
    } else cout << "while() NAO ACHEI!" << endl;
    auto final = chrono::high_resolution_clock::now();
    auto tempo = chrono::duration_cast<chrono::microseconds>(final - inicio);
    cout << "Tempo decorrido: " << tempo.count() << " microssegundos" << endl;
}


int main() {
    teste t[10];
    leitura(t);
    serial(t);
    serial1(t);
    serial2(t);
    
}