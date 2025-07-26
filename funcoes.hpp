#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include <vector>
#include <list>
#include <string>

int ler_inteiro(std::string mensagem_de_erro, int lim_inf, int lim_sup); // Função para ler um número inteiro.
int contarCaracteresUTF8(const std::string &texto); // Função para contar caracteres reais (code points) em uma string UTF-8.
bool inserirHorarionaAgenda(std::vector<std::vector<std::list<std::string>>> &Agenda, std::string Disciplina, std::string COD_Horario); // Função para inserir a disciplina na agenda dado seu horário.
std::string trim(const std::string &str); // Função para remover espaços à esquerda e à direita (trim)
std::vector<std::string> split(const std::string &str, char delimitador); // Função para dividir uma string em uma lista de substrings, com base em um caractere delimitador específico.
bool dia_vazio(std::vector<std::vector<std::list<std::string>>> &Agenda, int indice_dia); // Função para conferir se há algum compromisso planejado para um dado dia.
void imprimir_Agenda(std::vector<std::vector<std::list<std::string>>> &Agenda, float Disc_maior_nome); // Função para imprimir a agenda projetada.

#endif