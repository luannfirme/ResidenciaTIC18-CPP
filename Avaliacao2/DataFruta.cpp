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
    virtual void listarOrdem() = 0;
    virtual void mostrarPrimeirosNElementos() = 0;
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
            if (entrada == "fim") return;
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

    void Opcoes() {
            cout << "1. INCLUIR LISTA" << endl;
            cout << "2. ENCONTRAR MENOR" << endl;
            cout << "3. ENCONTRAR MAIOR" << endl;
            cout << "4. ENCONTRAR MEDIANA" << endl;
            cout << "5. ORDENAR CRESCENTE" << endl;
            cout << "6. LISTAR OS 'N' PRIMEIROS " << endl;
            cout << "0. VOLTAR" << endl;
            cout << "Resposta <enter>: ";
    }

    void executarMenu(string local) {
        int resp;
        do {
            cout << endl;
            cout << "######## MENU " << local << " ########" << endl;
            Opcoes();

            if (!(cin >> resp)) {
                cout << "Resposta invalida. Por favor, informe o numero correto." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (resp) {
                case 1: {
                    entradaDeDados();
                    break;
                }
                case 2: {
                    cin.ignore();
                    mostraMenor();
                    break;
                }
                case 3: {
                    cin.ignore();
                    mostraMaior();
                    break;
                }
                case 4: {
                    cin.ignore();
                    mostraMediana();
                    break;
                }
                case 5: {
                    cin.ignore();
                    listarOrdem();
                    break;
                }
                case 6: {
                    cin.ignore();
                    mostrarPrimeirosNElementos();
                    break;
                }
                case 0: {
                    break;
                }
                default: {
                    cout << "Opção inválida. Tente novamente." << endl;
                    break;
                }
            }
        } while (resp != 0);
    }
};

class ListaNomes : public Lista {
private:
    vector<string> lista;

public:
    void entradaDeDados() override {
        cout << endl;
        cout << "Insercao de nomes (digite 'FIM' para terminar):" << endl;
        inserirDados(lista);
    }

    void mostraMediana() override {
        cout << endl;
        cout << "A mediana da lista de nomes e: " << encontraMediana(lista) << endl;
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void mostraMenor() override {
        cout << endl;
        cout << "O primeiro nome alfabeticamente e: " << encontraMenor(lista) << endl;
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void mostraMaior() override {
        cout << endl;
        cout << "O ultimo nome alfabeticamente e: " << encontraMaior(lista) << endl;
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void listarOrdem() override {
        cout << "Nomes ordenados:" << endl;
        sort(lista.begin(), lista.end());
        for (const auto& elemento : lista){
            cout << elemento << endl;
        }
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void mostrarPrimeirosNElementos() override {
        int resp = 0;
        int count = 0;
        cout << "Informe o posicao que deseja <enter>: ";
        cin >> resp;
        cout << "Os primeiras " << resp << " nomes:" << endl;
        for (const auto& data : lista) {
            if (count >= resp) {
                break;
            }
            cout << data << endl;
            ++count;
        }
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
};

class ListaDatas : public Lista {
private:
    vector<Data> lista;

public:
    void entradaDeDados() override {
        cout << endl;
        inserirData(lista);
    }

    void mostraMediana() override {
        cout << endl;
        cout << "A mediana da lista de datas e: " << encontraMediana(lista).toString() << endl;
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void mostraMenor() override {
        cout << endl;
        cout << "A primeira data cronologicamente e: " << encontraMenor(lista).toString() << endl;
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void mostraMaior() override {
        cout << endl;
        cout << "A ultima ultima data cronologicamente e: " << encontraMaior(lista).toString() << endl;
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void listarOrdem() override {
        cout << "Datas ordenadas:" << endl;
        sort(lista.begin(), lista.end());
        for (const auto& elemento : lista){
            cout << elemento.toString() << endl;
        }
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void mostrarPrimeirosNElementos() override {
        int resp = 0;
        int count = 0;
        cout << "Informe o posicao que deseja <enter>: ";
        cin >> resp;
        cout << "Os primeiras " << resp << " datas:" << endl;
        for (const auto& data : lista) {
            if (count >= resp) {
                break;
            }
            cout << data.toString() << endl;
            ++count;
        }
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
};

class ListaSalarios : public Lista {
private:
    vector<float> lista;

public:
    void entradaDeDados() override {
        cout << endl;
        cout << "Insercao de salarios (digite 'FIM' para terminar):" << endl;
        inserirDados(lista);
    }

    void mostraMediana() override {
        cout << endl;
        cout << "A mediana da lista de salarios e: " << encontraMediana(lista) << endl;
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void mostraMenor() override {
        cout << endl;
        cout << "O  menor dos salarios e: " << encontraMenor(lista) << endl;
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void mostraMaior() override {
        cout << endl;
        cout << "O  maior dos salarios e " << encontraMaior(lista) << endl;
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void listarOrdem() override {
        cout << "Salarios ordenados:" << endl;
        sort(lista.begin(), lista.end());
        for (const auto& elemento : lista){
            cout << elemento << endl;
        }
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }    

    void mostrarPrimeirosNElementos() override {
        int resp = 0;
        int count = 0;
        cout << "Informe o posicao que deseja <enter>: ";
        cin >> resp;
        cout << "Os primeiras " << resp << " salarios:" << endl;
        for (const auto& data : lista) {
            if (count >= resp) {
                break;
            }
            cout << data << endl;
            ++count;
        }
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

};

class ListaIdades : public Lista {
private:
    vector<int> lista;

public:
    void entradaDeDados() override {
        cout << endl;
        cout << "Insercao de idades (digite 'FIM' para terminar):" << endl;
        inserirDados(lista);
    }

    void mostraMediana() override {
        cout << endl;
        cout << "A mediana da lista de idades e: " << encontraMediana(lista) << endl;
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void mostraMenor() override {
        cout << endl;
        cout << "A menor das idades e: " << encontraMenor(lista) << endl;
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void mostraMaior() override {
        cout << endl;
        cout << "A maior das idades e: " << encontraMaior(lista) << endl;
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void listarOrdem() override {
        cout << "Idades ordenadas:" << endl;
        sort(lista.begin(), lista.end());
        for (const auto& elemento : lista){
            cout << elemento << endl;
        }
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void mostrarPrimeirosNElementos() override {
        int resp = 0;
        int count = 0;
        cout << "Informe o posicao que deseja <enter>: ";
        cin >> resp;
        cout << "Os primeiras " << resp << " idades:" << endl;
        for (const auto& data : lista) {
            if (count >= resp) {
                break;
            }
            cout << data << endl;
            ++count;
        }
        cout << "pressione <enter> para voltar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
};

class Menu {
public:
    void executar() {
        vector<Lista*> listaDeListas;
        int escolha;

        do {
            cout << endl;
            cout << "######## MENU PRINCIPAL ########" << endl;
            cout << "1. NOMES" << endl;
            cout << "2. IDADES" << endl;
            cout << "3. SALARIOS" << endl;
            cout << "4. DATAS" << endl;
            cout << "0. SAIR" << endl;
            cout << "Resposta <enter>: ";
            cin >> escolha;
            cout << endl;

            cin.ignore();

            Lista* novaLista = nullptr;
            string menu = "";

            switch (escolha) {
                case 1: {
                    novaLista = new ListaNomes();
                    menu = "NOMES";
                    break;
                }
                case 2: {
                    novaLista = new ListaIdades();
                    menu = "IDADES";
                    break;
                }
                case 3: {
                    novaLista = new ListaSalarios();
                    menu = "SALARIOS";
                    break;
                }
                case 4: {
                    novaLista = new ListaDatas();
                    menu = "DATAS";
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

            if (novaLista != nullptr) {
                novaLista->executarMenu(menu);
            }
        
          } while (escolha != 0);

    }
};

int main() {
    Menu menu;
    menu.executar();

    return 0;
}