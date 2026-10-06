#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Alfabeto utilizado para criptografia
const char ALFABETO[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

// Retorna o índice do caractere no alfabeto ou -1 se não estiver presente
int encontrar_posicao(char c) {
    for (int i = 0; ALFABETO[i] != '\0'; i++) {
        if (ALFABETO[i] == c) {
            return i;
        }
    }
    return -1;
}

// Função para ler um número inteiro do usuário, com validação de entrada e intervalo
int ler_inteiro(const char *mensagem, int minimo, int maximo, bool tem_min, bool tem_max) {
    int valor;
    int resultado;

    while (1) {
        printf("%s", mensagem);
        resultado = scanf("%d", &valor);

        // Limpa o buffer de entrada
        while (getchar() != '\n');

        if (resultado != 1) {
            printf("\nDigite apenas um número inteiro.\n");
            continue;
        }

        if (tem_min && valor < minimo) {
            printf("\nDigite um número maior ou igual a %d.\n", minimo);
            continue;
        }

        if (tem_max && valor > maximo) {
            printf("\nDigite um número menor ou igual a %d.\n", maximo);
            continue;
        }

        return valor;
    }
}

// Cifra de César
void cifra_cesar(const char *mensagem, int deslocamento, char *resultado) {
    int tam_alfabeto = strlen(ALFABETO);
    int len = strlen(mensagem);

    for (int i = 0; i < len; i++) {
        char caractere = mensagem[i];
        int posicao = encontrar_posicao(caractere);

        if (posicao != -1) {
            int nova_posicao = (posicao + deslocamento) % tam_alfabeto;
            if (nova_posicao < 0) {
                nova_posicao += tam_alfabeto;
            }
            resultado[i] = ALFABETO[nova_posicao];
        } else {
            resultado[i] = caractere;
        }
    }
    resultado[len] = '\0';
}

// Sequência Fibonacci
void fibonacci_base(int tamanho, int *sequencia) {
    if (tamanho >= 1) sequencia[0] = 1;
    if (tamanho >= 2) sequencia[1] = 1;

    for (int i = 2; i < tamanho; i++) {
        sequencia[i] = sequencia[i - 1] + sequencia[i - 2];
    }
}

// Segunda camada - Fibonacci
void segunda_camada_fib(const char *mensagem, const int *sequencia, int deslocamento, char *resultado) {
    int tam_alfabeto = strlen(ALFABETO);
    int len = strlen(mensagem);

    for (int i = 0; i < len; i++) {
        char caractere = mensagem[i];
        int posicao = encontrar_posicao(caractere);

        if (posicao != -1) {
            int deslocamento_fib = deslocamento + sequencia[i];
            int nova_posicao = (posicao + deslocamento_fib) % tam_alfabeto;
            if (nova_posicao < 0) {
                nova_posicao += tam_alfabeto;
            }
            resultado[i] = ALFABETO[nova_posicao];
        } else {
            resultado[i] = caractere;
        }
    }
    resultado[len] = '\0';
}

// Sequência de Progressão Aritmética
void progressao_aritmetica(int tamanho, int razao, int *sequencia) {
    if (tamanho >= 1) sequencia[0] = 1;
    for (int i = 1; i < tamanho; i++) {
        sequencia[i] = sequencia[i - 1] + razao;
    }
}

// Segunda camada - PA
void segunda_camada_pa(const char *mensagem, const int *sequencia, int deslocamento, char *resultado) {
    int tam_alfabeto = strlen(ALFABETO);
    int len = strlen(mensagem);

    for (int i = 0; i < len; i++) {
        char caractere = mensagem[i];
        int posicao = encontrar_posicao(caractere);

        if (posicao != -1) {
            int deslocamento_pa = deslocamento + sequencia[i];
            int nova_posicao = (posicao + deslocamento_pa) % tam_alfabeto;
            if (nova_posicao < 0) {
                nova_posicao += tam_alfabeto;
            }
            resultado[i] = ALFABETO[nova_posicao];
        } else {
            resultado[i] = caractere;
        }
    }
    resultado[len] = '\0';
}

// Sequência de Progressão Geométrica
void progressao_geometrica(int tamanho, int razao, int *sequencia) {
    if (tamanho >= 1) sequencia[0] = 1;
    for (int i = 1; i < tamanho; i++) {
        sequencia[i] = sequencia[i - 1] * razao;
    }
}

// Segunda camada - PG
void segunda_camada_pg(const char *mensagem, const int *sequencia, int deslocamento, char *resultado) {
    int tam_alfabeto = strlen(ALFABETO);
    int len = strlen(mensagem);

    for (int i = 0; i < len; i++) {
        char caractere = mensagem[i];
        int posicao = encontrar_posicao(caractere);

        if (posicao != -1) {
            int deslocamento_pg = deslocamento + sequencia[i];
            int nova_posicao = (posicao + deslocamento_pg) % tam_alfabeto;
            if (nova_posicao < 0) {
                nova_posicao += tam_alfabeto;
            }
            resultado[i] = ALFABETO[nova_posicao];
        } else {
            resultado[i] = caractere;
        }
    }
    resultado[len] = '\0';
}

// Verificação de número primo
bool eh_primo(int numero) {
    if (numero < 2) return false;
    for (int divisor = 2; divisor < numero; divisor++) {
        if (numero % divisor == 0) return false;
    }
    return true;
}

// Sequência de Números Primos
void numeros_primos(int tamanho, int *sequencia) {
    int qtd = 0;
    int numero = 2;

    while (qtd < tamanho) {
        if (eh_primo(numero)) {
            sequencia[qtd] = numero;
            qtd++;
        }
        numero++;
    }
}

// Segunda camada - Números Primos
void segunda_camada_primos(const char *mensagem, const int *sequencia, int deslocamento, char *resultado) {
    int tam_alfabeto = strlen(ALFABETO);
    int len = strlen(mensagem);

    for (int i = 0; i < len; i++) {
        char caractere = mensagem[i];
        int posicao = encontrar_posicao(caractere);

        if (posicao != -1) {
            int deslocamento_primos = deslocamento + sequencia[i];
            int nova_posicao = (posicao + deslocamento_primos) % tam_alfabeto;
            if (nova_posicao < 0) {
                nova_posicao += tam_alfabeto;
            }
            resultado[i] = ALFABETO[nova_posicao];
        } else {
            resultado[i] = caractere;
        }
    }
    resultado[len] = '\0';
}

// Sequência de Incremento em Progressão
void incremento_progressao(int tamanho, int *sequencia) {
    if (tamanho >= 1) sequencia[0] = 1;
    int incremento = 1;

    for (int i = 1; i < tamanho; i++) {
        sequencia[i] = sequencia[i - 1] + incremento;
        incremento++;
    }
}

// Segunda camada - Incremento em Progressão
void segunda_camada_incremento(const char *mensagem, const int *sequencia, int deslocamento, char *resultado) {
    int tam_alfabeto = strlen(ALFABETO);
    int len = strlen(mensagem);

    for (int i = 0; i < len; i++) {
        char caractere = mensagem[i];
        int posicao = encontrar_posicao(caractere);

        if (posicao != -1) {
            int deslocamento_inc = deslocamento + sequencia[i];
            int nova_posicao = (posicao + deslocamento_inc) % tam_alfabeto;
            if (nova_posicao < 0) {
                nova_posicao += tam_alfabeto;
            }
            resultado[i] = ALFABETO[nova_posicao];
        } else {
            resultado[i] = caractere;
        }
    }
    resultado[len] = '\0';
}

// Converte string para minúsculas e remove espaços das extremidades
void formatar_resposta(char *str) {
    int i = 0, j = strlen(str) - 1;

    while (isspace((unsigned char)str[i])) i++;
    while (j >= i && isspace((unsigned char)str[j])) j--;

    int index = 0;
    for (int k = i; k <= j; k++) {
        str[index++] = tolower((unsigned char)str[k]);
    }
    str[index] = '\0';
}

// Remove quebra de linha (\n ou \r)
void remover_quebra_linha(char *str) {
    str[strcspn(str, "\r\n")] = '\0';
}

// Salva o resultado em arquivo txt
void salvar_resultado(const char *palavra, int shift, const char *tipo, int letras) {
    FILE *arquivo = fopen("resultado_criptografia.txt", "w");
    if (arquivo != NULL) {
        fprintf(arquivo, "Palavra codificada: %s\n", palavra);
        fprintf(arquivo, "SHIFT: %d\n", shift);
        fprintf(arquivo, "Tipo: %s\n", tipo);
        fprintf(arquivo, "Letras: %d\n", letras);
        fclose(arquivo);
    } else {
        printf("Não foi possível salvar o arquivo.\n");
    }
}

int main() {
    char mensagem[100];
    char confirmar[20];
    char segundo_criptografia[20];
    char opcao[20];
    char resultado[100];
    char resultado_final[100];

    // Entrada da mensagem
    printf("----- BEM-VINDO -----\nDigite a mensagem a ser criptografada: ");
    fgets(mensagem, sizeof(mensagem), stdin);
    remover_quebra_linha(mensagem);

    while (strlen(mensagem) == 0 || strlen(mensagem) > 15) {
        if (strlen(mensagem) == 0) {
            printf("\nA mensagem não pode estar vazia.\n");
        } else {
            printf("\nA mensagem deve ter no máximo 15 caracteres.\n");
        }
        printf("Digite a mensagem a ser criptografada: ");
        fgets(mensagem, sizeof(mensagem), stdin);
        remover_quebra_linha(mensagem);
    }

    // Confirmação
    printf("\nMensagem escolhida: %s\n\nDeseja confirmar? (sim/não)\n", mensagem);
    fgets(confirmar, sizeof(confirmar), stdin);
    formatar_resposta(confirmar);

    while (strcmp(confirmar, "sim") != 0 && strcmp(confirmar, "não") != 0) {
        printf("\nResposta inválida\n");
        printf("\nVocê digitou: %s\n\nDeseja confirmar? (sim/não)\n", mensagem);
        fgets(confirmar, sizeof(confirmar), stdin);
        formatar_resposta(confirmar);
    }

    while (strcmp(confirmar, "não") == 0) {
        printf("\n----- BEM-VINDO -----\nDigite a mensagem a ser criptografada: ");
        fgets(mensagem, sizeof(mensagem), stdin);
        remover_quebra_linha(mensagem);

        while (strlen(mensagem) == 0 || strlen(mensagem) > 15) {
            if (strlen(mensagem) == 0) {
                printf("\nA mensagem não pode estar vazia.\n");
            } else {
                printf("\nA mensagem deve ter no máximo 15 caracteres.\n");
            }
            printf("Digite a mensagem a ser criptografada: ");
            fgets(mensagem, sizeof(mensagem), stdin);
            remover_quebra_linha(mensagem);
        }

        printf("\nVocê digitou: %s\n\nDeseja confirmar? (sim/não)\n", mensagem);
        fgets(confirmar, sizeof(confirmar), stdin);
        formatar_resposta(confirmar);

        while (strcmp(confirmar, "sim") != 0 && strcmp(confirmar, "não") != 0) {
            printf("\nResposta inválida\n");
            printf("\nVocê digitou: %s\n\nDeseja confirmar? (sim/não)\n", mensagem);
            fgets(confirmar, sizeof(confirmar), stdin);
            formatar_resposta(confirmar);
        }
    }

    if (strcmp(confirmar, "sim") == 0) {
        int tamanho = strlen(mensagem);
        printf("\nMensagem: %s\n\n", mensagem);

        // Deslocamento da Cifra de César
        int deslocamento = ler_inteiro("===== CIFRA DE CÉSAR =====\n\nDigite o deslocamento desejado: ", -1000000000, 1000000000, true, true);
        cifra_cesar(mensagem, deslocamento, resultado);

        printf("\n-------------------------------------------------------------------\nAlfabeto utilizado:\n");
        for (int i = 0; ALFABETO[i] != '\0'; i++) {
            printf("%c%s", ALFABETO[i], ALFABETO[i + 1] != '\0' ? ", " : "\n\n");
        }
        printf("Mensagem criptografada: %s\n-------------------------------------------------------------------\n", resultado);

        // Pergunta sobre a segunda camada
        printf("\nDeseja utilizar uma segunda forma de criptografia? (sim/não)\n\nResposta: ");
        fgets(segundo_criptografia, sizeof(segundo_criptografia), stdin);
        formatar_resposta(segundo_criptografia);

        while (strcmp(segundo_criptografia, "sim") != 0 && strcmp(segundo_criptografia, "não") != 0) {
            printf("\nResposta inválida\n");
            printf("\nDeseja utilizar uma segunda forma de criptografia? (sim/não)\n\nResposta: ");
            fgets(segundo_criptografia, sizeof(segundo_criptografia), stdin);
            formatar_resposta(segundo_criptografia);
        }

        if (strcmp(segundo_criptografia, "sim") == 0) {
            printf("\n-------------------------------------------------------------------\nEscolha a segunda forma de criptografia:\n1 - Fibonacci\n2 - Progressão Aritmética\n3 - Progressão Geométrica\n4 - Números Primos\n5 - Incremento em Progressão\n\nResposta: ");
            fgets(opcao, sizeof(opcao), stdin);
            remover_quebra_linha(opcao);

            while (strcmp(opcao, "1") != 0 && strcmp(opcao, "2") != 0 && strcmp(opcao, "3") != 0 && strcmp(opcao, "4") != 0 && strcmp(opcao, "5") != 0) {
                printf("\nOpção inválida\n");
                printf("\n-------------------------------------------------------------------\nEscolha a segunda forma de criptografia:\n1 - Fibonacci\n2 - Progressão Aritmética\n3 - Progressão Geométrica\n4 - Números Primos\n5 - Incremento em Progressão\n\nResposta: ");
                fgets(opcao, sizeof(opcao), stdin);
                remover_quebra_linha(opcao);
            }

            int sequencia[100];

            if (strcmp(opcao, "1") == 0) {
                fibonacci_base(tamanho, sequencia);
                printf("\n-------------------------------------------------------------------\n\nSequência de Fibonacci gerada:\n[");
                for (int i = 0; i < tamanho; i++) {
                    printf("%d%s", sequencia[i], i < tamanho - 1 ? ", " : "]\n\n");
                }
                segunda_camada_fib(resultado, sequencia, deslocamento, resultado_final);
                printf("Mensagem após segunda criptografia: %s\n", resultado_final);
                printf("\n-------------------------------------------------------------------\n");
                salvar_resultado(resultado_final, deslocamento, "Fibonacci", tamanho);

            } else if (strcmp(opcao, "2") == 0) {
                int razao = ler_inteiro("\n-------------------------------------------------------------------\nDigite a razão da progressão aritmética: ", 1, 1000, true, true);
                progressao_aritmetica(tamanho, razao, sequencia);
                printf("\n-------------------------------------------------------------------\n\nSequência de Progressão Aritmética gerada:\n[");
                for (int i = 0; i < tamanho; i++) {
                    printf("%d%s", sequencia[i], i < tamanho - 1 ? ", " : "]\n\n");
                }
                segunda_camada_pa(resultado, sequencia, deslocamento, resultado_final);
                printf("Mensagem após segunda criptografia: %s\n", resultado_final);
                printf("\n-------------------------------------------------------------------\n");
                salvar_resultado(resultado_final, deslocamento, "Progressao Aritmetica", tamanho);

            } else if (strcmp(opcao, "3") == 0) {
                int razao = ler_inteiro("\n-------------------------------------------------------------------\nDigite a razão da progressão geométrica: ", 1, 1000, true, true);
                progressao_geometrica(tamanho, razao, sequencia);
                printf("\n-------------------------------------------------------------------\n\nSequência de Progressão Geométrica gerada:\n[");
                for (int i = 0; i < tamanho; i++) {
                    printf("%d%s", sequencia[i], i < tamanho - 1 ? ", " : "]\n\n");
                }
                segunda_camada_pg(resultado, sequencia, deslocamento, resultado_final);
                printf("Mensagem após segunda criptografia: %s\n", resultado_final);
                printf("\n-------------------------------------------------------------------\n");
                salvar_resultado(resultado_final, deslocamento, "Progressao Geometrica", tamanho);

            } else if (strcmp(opcao, "4") == 0) {
                numeros_primos(tamanho, sequencia);
                printf("\n-------------------------------------------------------------------\n\nSequência de números primos gerada:\n[");
                for (int i = 0; i < tamanho; i++) {
                    printf("%d%s", sequencia[i], i < tamanho - 1 ? ", " : "]\n\n");
                }
                segunda_camada_primos(resultado, sequencia, deslocamento, resultado_final);
                printf("Mensagem após segunda criptografia: %s\n", resultado_final);
                printf("\n-------------------------------------------------------------------\n");
                salvar_resultado(resultado_final, deslocamento, "Numeros Primos", tamanho);

            } else if (strcmp(opcao, "5") == 0) {
                incremento_progressao(tamanho, sequencia);
                printf("\n-------------------------------------------------------------------\n\nSequência de incremento em progressão gerada:\n[");
                for (int i = 0; i < tamanho; i++) {
                    printf("%d%s", sequencia[i], i < tamanho - 1 ? ", " : "]\n\n");
                }
                segunda_camada_incremento(resultado, sequencia, deslocamento, resultado_final);
                printf("Mensagem após segunda criptografia: %s\n", resultado_final);
                printf("\n-------------------------------------------------------------------\n");
                salvar_resultado(resultado_final, deslocamento, "Incremento Progressao", tamanho);
            }
        } else {
            salvar_resultado(resultado, deslocamento, "Cifra de César", tamanho);
        }
    }

    return 0;
}
