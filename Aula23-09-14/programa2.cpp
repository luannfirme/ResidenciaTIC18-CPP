#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Data {
    int Dia, Mes, Ano;

    int AnosEntre(Data dataFinal){
        int x;
    x = dataFinal.Ano - Ano;

    if(dataFinal.Mes > Mes)
        x--;
    
    if(dataFinal.Mes == Mes && dataFinal.Dia > Dia)
        x--;

    return x;
    }

    bool DataValida(){

        if(Ano <= 1000 || Ano >= 9999)
            return false;

        if(Mes < 1 || Mes > 12)
            return false;

        if(Mes == 1, 3, 5, 7, 8, 10, 12 && (Dia < 1 || Dia > 31))
            return false;

        if(Mes == 4, 6, 9, 11 && (Dia < 1 || Dia > 30))
            return false;

        if(Ano % 400 == 0 && Mes == 2 && (Dia < 1 || Dia > 29))
            return false;

        else if(((Ano % 4 == 0) && (Ano % 100 != 0)) &&  Mes == 2 && (Dia < 1 || Dia > 29) )
             return false;

        else if(((Ano % 4 == 0) && (Ano % 100 != 0)) && Mes == 2 && (Dia < 1 || Dia > 28) )
             return false;

         return true;
    }

    int DiaDaSemana(){
        tm time_in = { 0, 0, 0, Dia, Mes, Ano - 1900 };

        time_t time_temp = mktime(&time_in);

        const tm * time_out = localtime(&time_temp);

        int dia = time_out->tm_wday;

        return dia;
    }
};

void ReturnDiaDaSemana(Data data){
    int dia = data.DiaDaSemana();
    switch (dia)
    {
    case 2:
        cout << "a data informada cai em um Domingo" << endl;
        break;
    case 3:
        cout << "a data informada cai em uma segunda-feira" << endl;
        break;
    case 4:
        cout << "a data informada cai em uma terca-feira" << endl;
        break;
    case 5:
        cout << "a data informada cai em uma quarta-feira" << endl;
        break;
    case 6:
        cout << "a data informada cai em uma quinta-feira" << endl;
        break;
    case 0:
        cout << "a data informada cai em uma sexta-feira" << endl;
        break;
    case 1:
        cout << "a data informada cai em um sabado" << endl;
        break;
    default:
        break;
    }
};

int main (void){
 
    Data dataInicial, dataFinal;
    int x;
    
    cout << "####### MENU #######" << endl;
    cout << "1. Comparar Anos" << endl;
    cout << "2. Validar Data" << endl;
    cout << "3. Obter Dia da Semana" << endl;
    cout << "0. Encerrar" << endl;
    cin >> x;

    if( x == 1){
        cout << "Informe a data inicial <dd mm aaaa>: ";
        cin >> dataInicial.Dia >> dataInicial.Mes >> dataInicial.Ano;
        cout << "Informe a data final <dd mm aaaa>: ";
        cin >> dataFinal.Dia >> dataFinal.Mes >> dataFinal.Ano;
        cout << "a diferenca entra as datas e " << dataInicial.AnosEntre(dataFinal) << " anos." << endl;

    } else if ( x == 2 || x == 3) {
        cout << "Informe uma data <dd mm aaaa>: ";
        cin >> dataInicial.Dia >> dataInicial.Mes >> dataInicial.Ano;

        if (x == 2){
            if(dataInicial.DataValida() == 1)
                cout << "Data valida.";
            else
                cout << "Data invalida.";
        }

        if( x == 3)
            ReturnDiaDaSemana(dataInicial);

    } else {
        cout << "Programa encerrado..." << endl;
    }

    return 0;
}