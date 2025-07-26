#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "funcoes.hpp"

using namespace std;

int main(){
    setlocale(LC_ALL, "portuguese");

    int qnt_disciplinas = ler_inteiro("Digite a quantidade de disciplinas que deseja inserir em seu planejamento.", 0, 30);

    vector<vector<list<string>>> Agenda(16, vector<list<string>>(8));
    float Disc_maior_nome = 3.0;
    Agenda[0][0].push_back("07:00-07:50");
    Agenda[1][0].push_back("07:50-08:40");
    Agenda[2][0].push_back("08:50-09:40");
    Agenda[3][0].push_back("09:40-10:30");
    Agenda[4][0].push_back("10:40-11:30");
    Agenda[5][0].push_back("11:30-12:20");
    Agenda[6][0].push_back("13:00-13:50");
    Agenda[7][0].push_back("13:50-14:40");
    Agenda[8][0].push_back("14:50-15:40");
    Agenda[9][0].push_back("15:40-16:30");
    Agenda[10][0].push_back("16:40-17:30");
    Agenda[11][0].push_back("17:30-18:20");
    Agenda[12][0].push_back("18:40-19:30");
    Agenda[13][0].push_back("19:30-20:20");
    Agenda[14][0].push_back("20:30-21:20");
    Agenda[15][0].push_back("21:20-22:10");

    for (int i = 0; i < qnt_disciplinas; i++){
        string Disciplina, CODs_Entrada;
        getline(cin >> ws, Disciplina);
        while(true){
            getline(cin >> ws, CODs_Entrada);
            vector<string> COD_Horarios = split(CODs_Entrada, ',');
            int tamanho_COD_Horarios = COD_Horarios.size(), ERRO = 0;
            for (int j = 0; j < tamanho_COD_Horarios; j++){
                if (inserirHorarionaAgenda(Agenda, Disciplina, COD_Horarios[j])){
                    cerr << "> ERRO: entrada inválida. Digite o código que correspondente ao momento que suas aulas ocorrem conforme a formatação certa, exemplo: 24M12." << endl;
                    ERRO++;
                }
            }
            if (ERRO < tamanho_COD_Horarios){break;}
        }
        if (contarCaracteresUTF8(Disciplina) > Disc_maior_nome){Disc_maior_nome = contarCaracteresUTF8(Disciplina);}
    }

    Disc_maior_nome += 4;
    imprimir_Agenda(Agenda, Disc_maior_nome);
    return 0;
}