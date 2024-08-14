<h1 align="center">Get Next Line</h1>

<div align="center">
  <img src="https://github.com/debsalbornoz/get_next_line/assets/119970138/ad029c4d-5e6b-4afb-b3a3-a97f4fe6bc97">
</div>
<div align="center">
  <img alt="Static Badge" src="https://img.shields.io/badge/Status-Finished-green">
</div>

<h2>Sobre</h2>
Este repositório contém uma implementação da função get_next_line em C, criada como um projeto para a escola de programação 42. A função get_next_line é uma ferramenta essencial em operações de entrada/saída de arquivos, permitindo que o programa leia uma linha de cada vez de um arquivo ou fonte de entrada até chegar ao final do arquivo. Esta função aloca dinamicamente a memória para cada linha, garantindo uso eficiente da memória.

<h4>Principais Recursos:</h4>

• **Leitura Eficiente Linha a Linha:** Lê uma linha de cada vez de arquivos ou fluxos de entrada, otimizando o processamento de dados ao lidar com informações de forma incremental.

• **Alocação Dinâmica de Memória:** Aloca dinamicamente a memória para cada linha, promovendo um uso eficiente da memória, mesmo ao lidar com arquivos de texto extensos.

• **Gerenciamento de Recursos de Memória:** Processa grandes arquivos de texto linha por linha sem sobrecarregar a memória do sistema, garantindo uma operação suave.

• **Fácil Integração:** Integra-se perfeitamente a uma variedade de projetos em C envolvendo operações com arquivos, fornecendo uma solução confiável para leitura de arquivos.

Sinta-se à vontade para explorar o repositório, experimentar o código e integrar esta função de leitura de linhas em seus projetos. Se você encontrar problemas ou tiver sugestões de melhorias, suas contribuições são altamente apreciadas! <3

<h2>Como usar:</h2>

<h3>Requisitos:</h3>

Este projeto necessita do compilador `cc`.

<h3>Instruções:</h3>

• Clone o repositório

```bash
git clone https://github.com/debsalbornoz/get_next_line.git
```

• Inclua os arquivos do repositório na sua pasta de projetos e inclua o header no seu código fonte 

```

#include "get_next_line.h>

```

•Chame a função "get_next_line" para ler linhas do arquivo. Aqui está um exemplo simples de como usar: 

```
#include "get_next_line.h"
#include <stdio.h> 
#include <fcntl.h>

int main(void)
{
    int fd;
    char   *line;

    //Abre o arquivo para leitura, é preciso que o arquivo file.txt exista e verifica erros na abertura
    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
       return (-1);
    //Chama a função uma vez, lê a primeira linha do arquivo e imprime a linha no terminal
    line = get_next_line(fd);
    printf("%s",line);
   //Libera a memória alocada pela linha e fecha o arquivo
    free(line); 
    close(fd);
  return(0);
}
```

•Compile e execute : 


cc  -Wall -Wextra -Werror -o my_program my_program.c get_next_line.c get_next_line_utils.c  &&  ./my_program

