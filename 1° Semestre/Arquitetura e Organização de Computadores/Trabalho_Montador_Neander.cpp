#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definição de instruções
#define NOP 0x00
#define STA 0x10
#define LDA 0x20
#define ADD 0x30
#define OR 0x40
#define AND 0x50
#define NOT 0x60
#define JMP 0x80
#define JN 0x90
#define JZ 0xA0
#define HLT 0xF0

// Função para transformar caracteres minúsculos em maiúsculos
void maiusculo(char *str) {
    while (*str) {
        *str = toupper((unsigned char) *str);
        str++;
    }
}
int main(void) {
    char nome[1000]; // Endereço do arquivo
    FILE *file, *mem; // Ponteiro para os arquivos .txt e .mem
    unsigned char dados[512]; // Conteúdo que vai para o .mem
    char assembly[3], linha[512]; // Assembly: vai guardar os opcodes | Linha: uma string utilizada para armazenar uma linha do arquivo de entrada
    int i = 0; // controla a posição no array de dados
    
	// incluindo cabeçalho em dados
    dados[i++] = 0x03;
    dados[i++] = 0x4E;
    dados[i++] = 0x44;
    dados[i++] = 0x52;
    
    printf("Digite o endereco do arquivo: ");
    scanf("%99s", nome);
    
    // Abre o arquivo para leitura
    file = fopen(nome, "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo\n");
        return 1;
    } else {
        printf("Dados do arquivo txt:\n");
        while (fgets(linha, sizeof(linha), file) != NULL) {
            printf("%s", linha);
        }
    }
	// Criação de arquivo de saída
    mem = fopen("prog1.mem", "wb");
    if (mem == NULL) {
        printf("Não foi possível criar o arquivo .mem\n");
        fclose(file);
        return 1;
    }
    rewind(file);
	/*
	A função rewind(file) reposiciona o ponteiro
	do arquivo de volta ao início, permitindo que o arquivo
	seja lido novamente desde o começo.
	Isso é necessário porque, após a primeira leitura do arquivo,
	o ponteiro estará no final, e sem o `rewind`,
	não seria possível ler o arquivo novamente.
	*/
    
	// Leitura de instruções em assembly e armazenamento dos opcodes no .mem
    while (fscanf(file, "%s", assembly) != EOF) {
		maiusculo(assembly);
        if (strcmp(assembly, "NOP") == 0) {
            dados[i++] = NOP;
        	dados[i++] = NOP;
        } else if (strcmp(assembly, "STA") == 0) {
            dados[i++] = STA;
            dados[i++] = NOP;
        } else if (strcmp(assembly, "LDA") == 0) {
            dados[i++] = LDA;
            dados[i++] = NOP;
        } else if (strcmp(assembly, "ADD") == 0) {
            dados[i++] = ADD;
            dados[i++] = NOP;
        } else if (strcmp(assembly, "OR") == 0) {
            dados[i++] = OR;
            dados[i++] = NOP;
        } else if (strcmp(assembly, "AND") == 0) {
            dados[i++] = AND;
            dados[i++] = NOP;
        } else if (strcmp(assembly, "NOT") == 0) {
            dados[i++] = NOT;
            dados[i++] = NOP;
        } else if (strcmp(assembly, "JMP") == 0) {
            dados[i++] = JMP;
            dados[i++] = NOP;
        } else if (strcmp(assembly, "JN") == 0) { 
            dados[i++] = JN;
            dados[i++] = NOP;
        } else if (strcmp(assembly, "JZ") == 0) { 
            dados[i++] = JZ;
            dados[i++] = NOP;
        } else if (strcmp(assembly, "HLT") == 0) {
            dados[i++] = HLT;
        } else {
            unsigned char hexa = (unsigned char) strtol(assembly, NULL, 16);
            dados[i++] = hexa;
            dados[i++] = NOP;
        }
    }
	// Preenchimento do de bytes do array dados
    while (i < 512) {
            dados[i++] = NOP;
    }
    
	// Alocando o conteúdo de dados no arquivo .mem
    fwrite(dados, sizeof(unsigned char), 512, mem);
    
	// Fechando arquivos
    fclose(file);
    fclose(mem);
    
    printf("\n\nArquivo prog1.mem criado com sucesso.");
    return 0;
}
