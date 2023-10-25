#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Data {
private:
    int dia, mes, ano;

public:
    Data(int _dia, int _mes, int _ano) : dia(_dia), mes(_mes), ano(_ano) {}

    string toString() const {
        string ret = "";
        ret.append(to_string(dia));
        ret.append("/");
        ret.append(to_string(mes));
        ret.append("/");
        ret.append(to_string(ano));
        return ret;
    }

    bool operator<(const Data& outraData) const {
        if (ano < outraData.ano)
            return true;
        if (ano > outraData.ano)
            return false;
        if (mes < outraData.mes)
            return true;
        if (mes > outraData.mes)
            return false;
        return dia < outraData.dia;
    }

    bool operator>(const Data& outraData) const {
        return outraData < *this;
    }
};

class Lista {
public:
    virtual void entradaDeDados() = 0;
    virtual void mostraMediana() = 0;
    virtual void mostraMenor() = 0;
    virtual void mostraMaior() = 0;
    virtual ~Lista() {}

    template<typename T>
    T encontraMediana(vector<T> valores) {
        sort(valores.begin(), valores.end());

        int meio = valores.size() / 2;
        if (valores.size() % 2 == 0) {
            return (valores[meio - 1] + valores[meio]) / 2;
        } else {
            return valores[meio];
        }
    }

    string encontraMediana(vector<string> valores) {
        sort(valores.begin(), valores.end());

        int meio = valores.size() / 2;
        if (valores.size() % 2 == 0) {
            return valores[meio - 1];
        } else {
            return valores[meio];
        }
    }

    Data encontraMediana(vector<Data> valores) {
        sort(valores.begin(), valores.end());

        int meio = valores.size() / 2;
        if (valores.size() % 2 == 0) {
            return valores[meio - 1];
        } else {
            return valores[meio];
        }
    }

    template<typename T>
    T encontraMenor(vector<T> valores) {
        T menor = valores[0];
        for (const T& valor : valores) {
            if (valor < menor) {
                menor = valor;
            }
        }
        return menor;
    }

    template<typename T>
    T encontraMaior(vector<T> valores) {
        T maior = valores[0];
        for (const T& valor : valores) {
            if (valor > maior) {
                maior = valor;
            }
        }
        return maior;
    }

    template<typename T>
    void inserirDados(vector<T>& lista) {
        T elemento;
        string entrada;
        cin.ignore();
        while (true) {
            getline(cin, entrada);
            transform(entrada.begin(), entrada.end(), entrada.begin(), ::tolower);
            if (entrada == "fim") break;
            istringstream ss(entrada);
            ss >> elemento;
            if (ss.fail()) {
                cout << "Erro ao converter o valor. Por favor, insira um valor valido." << endl;
                continue;
            }
            lista.push_back(elemento);
        }
    }

    void inserirData(vector<Data>& lista) {
        string entrada;
        int dia, mes, ano;
        cout << "Insira as datas [dd/mm/aaaa] (digite 'FIM' para terminar): " << endl;
        while (true) {
            getline(cin, entrada);            
            transform(entrada.begin(), entrada.end(), entrada.begin(), ::tolower);
            if (entrada == "fim") break;
            stringstream ss(entrada);
            char barra1, barra2;
            if (ss >> dia >> barra1 >> mes >> barra2 >> ano && barra1 == '/' && barra2 == '/') {
                if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && ano >= 0) {
                    lista.emplace_back(dia, mes, ano);
                } else {
                    cout << "Data invalida. Tente novamente." << endl;
                }
            }
        }
    }
};

class ListaNomes : public Lista {
private:
    vector<string> lista;

public:
    void entradaDeDados() override {
        cout << "Insercao de nomes (digite 'FIM' para terminar):" << endl;
        inserirDados(lista);
    }

    void mostraMediana() override {
        cout << "A mediana da lista de nomes e: " << encontraMediana(lista) << endl;
    }

    void mostraMenor() override {
        cout << "O primeiro nome alfabeticamente e: " << encontraMenor(lista) << endl;
    }

    void mostraMaior() override {
        cout << "O ultimo nome alfabeticamente e: " << encontraMaior(lista) << endl;
    }
};

class ListaDatas : public Lista {
private:
    vector<Data> lista;

public:
    void entradaDeDados() override {
        cout << "Insercao de datas (digite 'FIM' para terminar):" << endl;
        inserirData(lista);
    }

    void mostraMediana() override {
        cout << "A mediana da lista de datas e: " << encontraMediana(lista).toString() << endl;
    }

    void mostraMenor() override {
        cout << "A primeira data cronologicamente e: " << encontraMenor(lista).toString() << endl;
    }

    void mostraMaior() override {
        cout << "A ultima ultima data cronologicamente e: " << encontraMaior(lista).toString() << endl;
    }
};

class ListaSalarios : public Lista {
private:
    vector<float> lista;

public:
    void entradaDeDados() override {
        cout << "Insercao de salarios (digite 'FIM' para terminar):" << endl;
        inserirDados(lista);
    }

    void mostraMediana() override {
        cout << "A mediana da lista de salarios e: " << encontraMediana(lista) << endl;
    }

    void mostraMenor() override {
        cout << "O  menor dos salarios e: " << encontraMenor(lista) << endl;
    }

    void mostraMaior() override {
        cout << "O  maior dos salarios e " << encontraMaior(lista) << endl;
    }
};

class ListaIdades : public Lista {
private:
    vector<int> lista;

public:
    void entradaDeDados() override {
        cout << "Insercao de idades (digite 'FIM' para terminar):" << endl;
        inserirDados(lista);
    }

    void mostraMediana() override {
        cout << "A mediana da lista de idades e: " << encontraMediana(lista) << endl;
    }

    void mostraMenor() override {
        cout << "A menor das idades e: " << encontraMenor(lista) << endl;
    }

    void mostraMaior() override {
        cout << "A maior das idades e: " << encontraMaior(lista) << endl;
    }
};

class Menu {
public:
    void executar() {
        vector<Lista*> listaDeListas;
        int escolha;

        do {
            cout << "Escolha qual lista deseja inserir:" << endl;
            cout << "1. Nomes" << endl;
            cout << "2. Idades" << endl;
            cout << "3. Salarios" << endl;
            cout << "4. Datas" << endl;
            cout << "0. Sair" << endl;
            cout << "Opcao: ";
            cin >> escolha;

            switch (escolha) {
                case 1: {
                    ListaNomes* listaNomes = new ListaNomes();
                    listaNomes->entradaDeDados();
                    listaDeListas.push_back(listaNomes);
                    break;
                }
                case 2: {
                    ListaIdades* listaIdades = new ListaIdades();
                    listaIdades->entradaDeDados();
                    listaDeListas.push_back(listaIdades);
                    break;
                }
                case 3: {
                    ListaSalarios* listaSalarios = new ListaSalarios();
                    listaSalarios->entradaDeDados();
                    listaDeListas.push_back(listaSalarios);
                    break;
                }
                case 4: {
                    ListaDatas* listaDatas = new ListaDatas();
                    listaDatas->entradaDeDados();
                    listaDeListas.push_back(listaDatas);
                    break;
                }
                case 0: {
                    break;
                }
                default: {
                    cout << "Opcao invalida. Tente novamente." << endl;
                    break;
                }
            }
        } while (escolha != 0);

        for (Lista* l : listaDeListas) {
            cout << endl;
            l->mostraMediana();
            l->mostraMenor();
            l->mostraMaior();
            delete l;
            cout << endl;
        }
    }
};

int main() {
    Menu menu;
    menu.executar();

    return 0;
}