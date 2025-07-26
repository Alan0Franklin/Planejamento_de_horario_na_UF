# Planejamento de Horário na UF
Programa desenvolvido para ajudar no planejamento das disciplinas a serem cursadas no próximo semestre ao gerar uma grade horária com base na quantidade de disciplinas desejadas, seus respectivos nomes e os códigos de horários conforme o sistema da UF. Assim, possibilitando a visualização clara do cronograma planejado.


## Sumário

- [1. Estrutura](#1-estrutura)
- [2. Descrição das Funções](#2-descricao_das_funcoes)
- [3. Como Compilar e Executar](#3-como_compilar_e_executar)

---


## 1. Estrutura <a name="1-estrutura"></a>
```
Analise_Comparativa_Algoritmos_de_Ordenacao/
├── Entradas_+_Saidas_Esperadas
│   ├── teste1_entrada.txt
│   ├── teste1_saida.md
│   ├── teste2_entrada.txt
│   ├── teste2_saida.md
│   ├── teste3_entrada.txt
│   └── teste3_saida.md
├── Makefile
├── README.md
├── funcoes.cpp
├── funcoes.hpp
└── main.cpp
```


## 2. Descrição das Funções <a name="2-descricao_das_funcoes"></a>

### + int ler_inteiro(std::string mensagem_de_erro, int lim_inf, int lim_sup)
Função para ler um número inteiro do terminal, bloqueando qualquer entrada que não seja um inteiro. Após validar que a entrada é um número inteiro, verifica-se se o valor pertence ao intervalo fechado \[`lim_inf`, `lim_sup`]. Se pertencer, a função retorna esse valor e é finalizada. Caso contrário, a `mensagem_erro` será exibida e um novo valor deverá ser inserido até que seja uma entrada válida.
- `mensagem_erro`: String correspondente à mensagem de erro que deve ser exposta caso um valor não inteiro seja recebido do dispositivo de entrada.
- `lim_inf`: Inteiro correspondente ao primeiro número de um intervalo fechado o qual o valor que deve pertencer.
- `lim_inf`: Inteiro correspondente ao último número de um intervalo fechado o qual o valor que deve pertencer.

### + int contarCaracteresUTF8(const std::string &texto)
Função para contar os caracteres reais (code points) em um `texto` codificado em UTF-8. Em muitas linguagens, como C++, métodos como `.length()` ou `.size()` retornam o tamanho com base na representação interna da string, o que pode resultar em uma contagem incorreta quando há caracteres especiais como 'ç', acentos ou emojis. Esta função garante uma contagem precisa dos caracteres visíveis, sendo útil especialmente para alinhar corretamente os nomes das disciplinas nas colunas em tabelas feitas em arquivos `.txt`, onde o espaçamento visual é relevante, ao contrário do formato `.md`.
- `texto`: String ao qual se deseja saber a quantidade de caracteres reais.

### + bool inserirHorarionaAgenda(std::vector<std::vector<std::list<std::string>>> &Agenda, std::string Disciplina, std::string COD_Horario)
Função para inserir uma disciplina de nome `Disciplina` na grade de horário `Agenda` conforme seu código de horário `COD_Horario` conforme o sistema da UF. A função retorna uma booleana que sinaliza a presença (`true`) ou ausência (`false`) de erros durante o agendamento. No caso de haver erro, o sistema verificará se ocorreu erro (se essa função retornou `true`) em todos os códigos de horários fornecidos na entrada. Se ocorreu erro em todos esses códigos, o usuário deverá inserir uma nova entrada de códigos de horários. Caso contrário, prosseguirá com a execução considerando apenas o(s) código(s) válido(s).
- `Agenda`: Vetor de vetores de listas de strings que representa a grade horária que vai armazenar os nomes das disciplinas conforme os códigos de horários.
- `Disciplina`: String correspondente ao nome daquela disciplina que deseja ser incluída na grade de horários.
- `COD_Horario`: String correspondente ao código do horário, incluindo dia da semana, turno do dia e horário em que aquela tal disciplina ocorre.

### + std::string trim(const std::string &str)
A função trim() (ou equivalente, a depender da linguagem) remove espaços em branco no início e no final de uma dada string `str`. Nesta implementação dela, não há modificação da string original (especificada pela palavra-chave `const`). Ao invés disso, a função retornará a string correspondente à `str` com seus espaços no começo e no fim já removidas.
- `str`: String correspondente ao texto que deseja-se obter seu conteúdo sem espaços no começo e no fim da string.

### + std::vector\<std::string> split(const std::string &str, char delimitador)
A função split() (na maioria das linguagens) divide uma dada string `str` em partes menores (substrings) com base em um `delimitador` (como espaço, vírgula, hífen etc.) e retorna essas partes geralmente em forma de lista ou vetor, dependendo da linguagem. Nesse sistema, seu papel é receber os códigos de horários de uma disciplina em formato de string e retornar um vetor que separa cada código por meio de uma vígula como delimitador, aplicando a função `trim()` para cada string código.
- `str`: String correspondente a string que deseja-se dividir em um vetor de substrings.
- `delimitador`: Caractere usado como parâmetro para fazer as divisões da string em substrings.

### + bool dia_vazio(std::vector<std::vector<std::list<std::string>>> &Agenda, int indice_dia)
Função para conferir se há alguma disciplina planejada para ocorrer em um certo dia, recebendo a `Agenda` como a grade de horários a ser analisada e o `indice_dia` como o índice de um dado dia nesse vetor de vetores. A função retorna um valor booleano indicando se há alguma compromisso de aula em alguma disciplina (true) ou não (false).
- `Agenda`: Vetor de vetores de listas de strings que representa a grade horária que armazena os nomes das disciplinas conforme os códigos de horários.
- `tamanho_vetor`: Inteiro correspondente ao índice do dia que deseja-se analisar se há alguma compromisso de aula em alguma disciplina ou não.

### + void imprimir_Agenda(std::vector<std::vector<std::list<std::string>>> &Agenda, float Disc_maior_nome)
Função para imprimir a grade de horários `Agenda` projetada. A grade é impressa seguindo a formatação de tabelas em arquivos `.md` (markdown), entretanto o programa também adapta os espaçamentos entre as saídas para que a visualização da grade seja possível em arquivos `.txt` (texto). O sistema leva em conta a disciplina com o maior nome para determinar os espaçamentos entre saídas, o tamanho do nome dessa disciplina é calculado com a função `contarCaracteresUTF8()` e armazenado como nome de variável flutuante `Disc_maior_nome`. O `Disc_maior_nome` é declarado como flutuante para evitar a necessidade de convertê-lo para float em operações de variáveis de números flutuantes durante a progressão do código.
- `Agenda`: Vetor de vetores de listas de strings que representa a grade horária que armazena os nomes das disciplinas conforme os códigos de horários.
- `Disc_maior_nome`: Flutuante correspondente à string nome de disciplina com a maior quantidade de caracteres reais, senão 3.


## 3. Como Compilar e Executar <a name="3-como_compilar_e_executar"></a>
Para compilar os arquivos, use o comando `make` em um terminal no diretório/pasta que o `Makefile` estiver. Este comando automatizará a compilação e gerará um executável chamado `planejamento_de_horario_na_UF`.

Esse programa consegue ler o conteúdo do `cout` redirecionado de um arquivo `entrada.txt` com o `<`, como se fosse digitado pelo terminal, e consegue ser impresso (`cin`) de forma redirecionada para um arquivo `saida.md` (ou `saida.txt`) com o `>`, como se fosse impresso no terminal. Para isso use o seguinte comando a depender do seu terminal:

*   **Windows (Command Prompt):** `planejamento_de_horario_na_UF.exe < entrada.txt > saida.md`
*   **Linux/macOS (Terminal):** `./planejamento_de_horario_na_UF < entrada.txt > saida.md`

### Formato de Entrada Padrão
O programa lê **exatamente** neste formato:
```
[número de disciplinas desejadas]
[nome da disciplina]
[código(s) de horário desta disciplina separados por vírgula]
...
[nome da disciplina]
[código(s) de horário desta disciplina separados por vírgula]
```

Exemplo concreto (para 5 disciplinas):
```
5
Arquitetura de Computadores
24T34

Ciências de Dados
35M34, 7N34

Estrutura de Dados Básicas I
35T34, 7T34

Linguagem de Programação I
35M56, 7M56

Probabilidade
24M34
```

**Observações:**
- Se a entrada correspondente ao número de disciplinas for recebido em valor **não númerico**, **não inteiro** ou **fora do intervalo fechado \[0, 30]**, o código enviará uma mensagem de erro (`cerr`) e você terá de digitar uma nova entrada.
- A entrada "nome da disciplina" é recebida sem correção por parte do sistema, logo ela deve ser digitada corretamente conforme a forma que você quer que o nome da disciplina apareça na grade de horários. Uma variação adequada, além do nome completo, é a abreviação - por exemplo "EDB2" no lugar de "Estrutura de Dados Básicas II".
- Os códigos de horários devem ser digitados conforme a formatação que o sistema da UF usa para determinar os horários das matérias. Se houver algum código fora dessa formatação entre esses horários, o sistema prosseguirá sem necessidade de reatribuir uma nova entrada **na condição de haver pelo menos um entre esses códigos que seja válido**. Se não houver vígulas separando diferentes códigos de horários, os códigos não corretamente separados serão tidos como **um único código digitado e inválido**.

### Formato da Saída Padrão
O programa, conforme foi implementado a função `imprimir_Agenda()`, imprime a grade de horários, com apenas um texto adicional indicando caso houver colisões em algum horário. Se os dias de domingo ou sábado não possuirem nenhuma aula agendada prevista, conforme indicado pela função `dia_vazio()`, as suas partes na grade de horários não serão impressas. Uma vez que domingos e sábados dificilmente possuem compromissos diversos agendados, não há uma necessidade imediata de lembrarmos-nos de que não haverá aulas nesses dias.
```
|   Horário   |  Seg  |  Ter  |  Qua  |  Qui  |  Sex  |
|:-----------:|:-----:|:-----:|:-----:|:-----:|:-----:|
| 07:00-07:50 |  ---  |  ---  |  ---  |  ---  |  ---  |
| 07:50-08:40 |  ---  |  ---  |  ---  |  ---  |  ---  |
| 08:50-09:40 |  ---  |  ---  |  ---  |  ---  |  ---  |
| 09:40-10:30 |  ---  |  ---  |  ---  |  ---  |  ---  |
| 10:40-11:30 |  ---  |  ---  |  ---  |  ---  |  ---  |
| 11:30-12:20 |  ---  |  ---  |  ---  |  ---  |  ---  |
|      ~      |   ~   |   ~   |   ~   |   ~   |   ~   |
| 13:00-13:50 |  ---  |  ---  |  ---  |  ---  |  ---  |
| 13:50-14:40 |  ---  |  ---  |  ---  |  ---  |  ---  |
| 14:50-15:40 |  ---  |  ---  |  ---  |  ---  |  ---  |
| 15:40-16:30 |  ---  |  ---  |  ---  |  ---  |  ---  |
| 16:40-17:30 |  ---  |  ---  |  ---  |  ---  |  ---  |
| 17:30-18:20 |  ---  |  ---  |  ---  |  ---  |  ---  |
|      ~      |   ~   |   ~   |   ~   |   ~   |   ~   |
| 18:40-19:30 |  ---  |  ---  |  ---  |  ---  |  ---  |
| 19:30-20:20 |  ---  |  ---  |  ---  |  ---  |  ---  |
| 20:30-21:20 |  ---  |  ---  |  ---  |  ---  |  ---  |
| 21:20-22:10 |  ---  |  ---  |  ---  |  ---  |  ---  |
```

Exemplo concreto (para 4 disciplinas):
```
|   Horário   |              Seg               |              Ter               |              Qua               |              Qui               |              Sex               |              Sáb               |
|:-----------:|:------------------------------:|:------------------------------:|:------------------------------:|:------------------------------:|:------------------------------:|:------------------------------:|
| 07:00-07:50 |              ---               |              ---               |              ---               |              ---               |              ---               |              ---               |
| 07:50-08:40 |              ---               |              ---               |              ---               |              ---               |              ---               |              ---               |
| 08:50-09:40 |         Probabilidade          |       Ciências de Dados        |         Probabilidade          |       Ciências de Dados        |              ---               |              ---               |
| 09:40-10:30 |         Probabilidade          |       Ciências de Dados        |         Probabilidade          |       Ciências de Dados        |              ---               |              ---               |
| 10:40-11:30 |              ---               |   Linguagem de Programação I   |              ---               |   Linguagem de Programação I   |              ---               |   Linguagem de Programação I   |
| 11:30-12:20 |              ---               |   Linguagem de Programação I   |              ---               |   Linguagem de Programação I   |              ---               |   Linguagem de Programação I   |
|      ~      |               ~                |               ~                |               ~                |               ~                |               ~                |               ~                |
| 13:00-13:50 |              ---               |              ---               |              ---               |              ---               |              ---               |              ---               |
| 13:50-14:40 |              ---               |              ---               |              ---               |              ---               |              ---               |              ---               |
| 14:50-15:40 |  Arquitetura de Computadores   |  Estrutura de Dados Básicas I  |  Arquitetura de Computadores   |  Estrutura de Dados Básicas I  |              ---               |  Estrutura de Dados Básicas I  |
| 15:40-16:30 |  Arquitetura de Computadores   |  Estrutura de Dados Básicas I  |  Arquitetura de Computadores   |  Estrutura de Dados Básicas I  |              ---               |  Estrutura de Dados Básicas I  |
| 16:40-17:30 |              ---               |              ---               |              ---               |              ---               |              ---               |              ---               |
| 17:30-18:20 |              ---               |              ---               |              ---               |              ---               |              ---               |              ---               |
|      ~      |               ~                |               ~                |               ~                |               ~                |               ~                |               ~                |
| 18:40-19:30 |              ---               |              ---               |              ---               |              ---               |              ---               |              ---               |
| 19:30-20:20 |              ---               |              ---               |              ---               |              ---               |              ---               |              ---               |
| 20:30-21:20 |              ---               |              ---               |              ---               |              ---               |              ---               |       Ciências de Dados        |
| 21:20-22:10 |              ---               |              ---               |              ---               |              ---               |              ---               |       Ciências de Dados        |
```
