#include <iostream>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <limits>
#include <cmath>
#include "funcoes.hpp"

using namespace std;

int ler_inteiro(string mensagem_de_erro, int lim_inf, int lim_sup){
    float hold;
    while (true){
        cin >> hold;
        /* 1) Se houve erro de conversão (ex.: letra, vazio, etc.);
        Isso pode acontecer quando o usuário digita letras, caracteres especiais, espaços em branco ou quando pressiona Enter sem digitar nada.
        */
        if (cin.fail()){
            cerr << "> ERRO: entrada não númerica recebida." << mensagem_de_erro << endl;
            cin.clear(); // reseta o estado de erro do stream de entrada.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta todos os caracteres restantes até encontrar uma quebra de linha. esse numeric_limits é para dizer que limpe o máximo possível (tudo).
            continue; // retorna ao início do loop para solicitar uma nova entrada válida.
        }

        /* 2) Se o número está fora da faixa exigida;
        Verifica se a quantidade informada está dentro do intervalo permitido.
        Se estiver fora desse intervalo, exibe uma mensagem de erro e solicita uma nova entrada através do continue, que retorna ao início do loop.
        */
        if (hold != (int) hold || (hold < lim_inf || hold > lim_sup)){
            cerr << "> ERRO: número inválido recebido." << mensagem_de_erro << endl;
            continue; // volta para o início do loop para solicitar uma nova entrada válida.
        }
        break;
    }
    return hold;
}

int contarCaracteresUTF8(const string &texto){
    int count = 0;
    for (unsigned char c : texto){if ((c & 0b11000000) != 0b10000000){count++;}} // Se o byte não for um byte de continuação (10xxxxxx), é início de caractere
    return count;
}

bool inserirHorarionaAgenda(vector<vector<list<string>>> &Agenda, string Disciplina, string COD_Horario){
    vector<int> Dias, Horarios;
    int lim_inf = 1;
    char Turno;
    size_t tamanho_COD_Horario = COD_Horario.size(), j = 0;
    for ( ; j < tamanho_COD_Horario; j++){
        char c = COD_Horario[j];
        if (isdigit(c)){
            int hold = c - '0';
            if (hold < lim_inf || hold > 7){return true;}
            else{
                Dias.push_back(hold); 
                lim_inf = hold + 1;
            }
        }
        else if (c == 'M' || c == 'T' || c == 'N'){
            Turno = c;
            break;
        }
        else{return true;}
    }
    lim_inf = 1;
    for (j++; j < tamanho_COD_Horario; j++){
        char c = COD_Horario[j];
        if (isdigit(c)){
            int hold = c - '0';
            if (hold < lim_inf || hold > 6 || (Turno == 'N' && hold > 4)){return true;}
            else{
                Horarios.push_back(hold); 
                lim_inf = hold + 1;
            }
        }
        else{return true;}
    }
    if (Dias.empty() || Horarios.empty()){return true;}
    int tamanho_Dias = Dias.size(), tamanho_Horarios = Horarios.size();
    int hold = 0;
    if (Turno =='T'){hold += 6;}
    else if (Turno =='N'){hold += 12;}
    for (int j = 0; j < tamanho_Horarios; j++){for (int k = 0; k < tamanho_Dias; k++){Agenda[Horarios[j] - 1 + hold][Dias[k]].push_back(Disciplina);}}
    return false;
}

string trim(const string &str){
    auto start = find_if_not(str.begin(), str.end(), ::isspace);
    auto end = find_if_not(str.rbegin(), str.rend(), ::isspace).base();
    return (start < end) ? string(start, end) : "";
}

vector<string> split(const string &str, char delimitador){
    stringstream ss(str);
    string item;
    vector<string> lista_separada;
    while (getline(ss, item, delimitador)){lista_separada.push_back(trim(item));}
    return lista_separada;
}

bool dia_vazio(vector<vector<list<string>>> &Agenda, int indice_dia){
    for (int i = 0; i < 16; i++){if (!Agenda[i][indice_dia].empty()){return false;}}
    return true;
}

void imprimir_Agenda(vector<vector<list<string>>> &Agenda, float Disc_maior_nome){
    float centro = (Disc_maior_nome - 3.0)/2.0;
    string saida, espacamento_esquerdo = string(floor(centro), ' '), espacamento_direita = string(ceil(centro), ' ') + '|', linhas = ":" + string(Disc_maior_nome - 2, '-') + ":|";
    bool print_Dom = !dia_vazio(Agenda, 1), print_Sab = !dia_vazio(Agenda, 7), colisao = false;
    int lim_inf = 2, lim_sup = 6;
    
    cout << "|   Horário   |";
    if (print_Dom){cout  << espacamento_esquerdo << "Dom"  << espacamento_direita; lim_inf = 1;}
    cout << espacamento_esquerdo << "Seg" << espacamento_direita << espacamento_esquerdo << "Ter" << espacamento_direita << espacamento_esquerdo << "Qua"  << espacamento_direita << espacamento_esquerdo << "Qui" << espacamento_direita << espacamento_esquerdo << "Sex" << espacamento_direita;
    if (print_Sab){cout  << espacamento_esquerdo << "Sáb"  << espacamento_direita; lim_sup = 7;}
    cout << endl;
    cout << "|:-----------:|" << linhas << linhas << linhas << linhas << linhas;
    if (print_Dom){cout << linhas;}
    if (print_Sab){cout << linhas;}
    cout << endl;

    for (int j = 0; j < 16; j++){
        if (j % 6 == 0 && j != 0){
            centro = (Disc_maior_nome - 1.0)/2.0;
            saida = string(floor(centro), ' ') + '~' + string(ceil(centro), ' ') + '|';
            cout << "|      ~      |" << saida << saida << saida << saida << saida;
            if (print_Dom){cout << saida;}
            if (print_Sab){cout << saida;}
            cout << endl;
        }
        cout << "| " << Agenda[j][0].front() << " |";
        for (int k = lim_inf; k <= lim_sup; k++){
            if (Agenda[j][k].empty()){saida = "---";}
            else if (Agenda[j][k].size() == 1){saida = Agenda[j][k].front();}
            else {saida = "/!\\"; colisao = true;}
            centro = (Disc_maior_nome - contarCaracteresUTF8(saida))/2.0;
            cout << string(floor(centro), ' ') << saida << string(ceil(centro), ' ') <<'|';
        }
        cout << endl;
    }
    if (colisao){cout << "/!\\: Colisão de Horários.";}
}