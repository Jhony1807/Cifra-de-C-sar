# Cifra-de-César em C
Cifra de César é um trabalho acadêmico.

📜 Projeto de Criptografia Multicamadas em C

Este projeto consiste em um sistema de criptografia interativo desenvolvido em Linguagem C, projetado para aplicar uma ou duas camadas de codificação em mensagens de texto. A primeira camada utiliza a clássica Cifra de César, e a segunda camada permite aplicar transformações baseadas em sequências matemáticas e lógicas (Fibonacci, Progressão Aritmética, Progressão Geométrica, Números Primos e Incremento em Progressão).

🚀 Funcionalidades

Validação de Entrada: Garante que a mensagem não seja vazia e tenha no máximo 15 caracteres.Alfabeto Alfanumérico Ampliado: Suporta letras maiúsculas (A-Z), minúsculas (a-z) e dígitos numéricos (0-9), totalizando 62 caracteres.
CAMADA 1 

1 - Cifra de César: Deslocamento customizável pelo usuário (suporta valores positivos e negativos).

CAMADA 2

2 - Sequências Matemáticas: Fibonacci: Deslocamento baseado nos termos da sequência de Fibonacci.Progressão Aritmética (PA): Deslocamento com razão definida pelo usuário.Progressão Geométrica (PG): Deslocamento exponencial com razão definida pelo usuário. Números Primos: Deslocamento progressivo baseado na sequência de números primos.Incremento em Progressão: Deslocamento acumulativo ($1, 2, 4, 7, 11, \dots$). Exportação dos Resultados: Salva automaticamente o resultado codificado e os parâmetros utilizados em um arquivo texto (resultado_criptografia.txt).

🛠️ Estrutura do Códigoencontrar_posicao(): Localiza o índice de um caractere no alfabeto suportado.ler_inteiro(): Faz a leitura segura de valores numéricos tratando entradas inválidas e limites.cifra_cesar(): Aplica o deslocamento fixo inicial. 
Funções de Camada 2: segunda_camada_fib, segunda_camada_pa, segunda_camada_pg, segunda_camada_primos, segunda_camada_incremento.salvar_resultado(): Gera o arquivo .txt final de saída.

💻 Como Compilar e ExecutarPré-requisitosUm compilador C instalado (como gcc ou clang).

Passos:
Clone o repositório ou baixe o arquivo fonte .c:

Bash
git clone EX: https://github.com/SEU_USUARIO/NOME_DO_REPOSITORIO.git
cd NOME_DO_REPOSITORIO
Compile o código:

Bash
gcc -o criptografia main.c
Execute o programa:

Linux / macOS:

Bash
./criptografia
Windows:

DOS
criptografia.exe
📂 Arquivo de Saída (resultado_criptografia.txt)
Ao finalizar o processo, o programa gera um arquivo chamado resultado_criptografia.txt no mesmo diretório com o seguinte formato:

Plaintext
Palavra codificada: [MENSAGEM_CRIPTOGRAFADA]
SHIFT: [DESLOCAMENTO_CESAR]
Tipo: [TIPO_DA_SEGUNDA_CAMADA]
Letras: [TAMANHO_DA_MENSAGEM]
