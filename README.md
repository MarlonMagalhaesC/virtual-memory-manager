# Trabalho Prático 2 — Gerenciador de Memória Virtual

Este é o projeto-base para implementação de um simulador de gerência de memória virtual.

# Execução do Projeto

## 1. Requisitos do Sistema

Para executar o simulador é necessário:

* Sistema operacional Windows 10 ou superior.
* Python 3 instalado.
* GCC (compilador C).
* Make.
* Git Bash ou terminal compatível.

O projeto foi desenvolvido e testado em ambiente Windows utilizando Git Bash.

---

## 2. Estrutura do Projeto

Após extrair o arquivo do projeto, a estrutura de diretórios deve ser semelhante a:

```text
vm_manager/
│
├── data/
├── include/
├── src/
├── Makefile
└── README
```

As pastas possuem as seguintes funções:

* data: arquivos utilizados nos testes.
* include: arquivos de cabeçalho (.h).
* src: arquivos-fonte em C (.c).
* Makefile: responsável pela compilação.

---

## 3. Instalação do Python

Acessar:

https://www.python.org/downloads/

Durante a instalação, marcar a opção:

"Add Python to PATH"

Após a instalação, abrir o terminal e executar:

```bash
python --version
```

Caso seja exibida a versão do Python, a instalação foi concluída corretamente.

---

## 4. Instalação do GCC e Make

Instalar o ambiente MinGW ou MSYS2 contendo:

* gcc
* make

Após a instalação, verificar:

```bash
gcc --version
make --version
```

Caso as versões sejam exibidas, a instalação foi concluída com sucesso.

---

## 5. Abrindo o Projeto

Extrair o arquivo do projeto em qualquer pasta do computador.

Exemplo:

```text
C:\Projetos\vm_manager
```

Abrir o Git Bash dentro dessa pasta.

Também é possível abrir a pasta utilizando o Visual Studio Code.

---

## 6. Geração dos Arquivos de Teste

Entrar na pasta:

```bash
cd data
```

Executar:

```bash
python generate_data.py
```

Ao término serão criados:

* BACKING_STORE.bin
* addresses_random.txt
* addresses_location.txt

A mensagem:

```text
Arquivos gerados com sucesso
```

indica que o processo foi concluído corretamente.

Retornar para a pasta principal:

```bash
cd ..
```

---

## 7. Compilação do Projeto

Na pasta principal executar:

```bash
make
```

O compilador GCC será executado automaticamente.

Ao término será criado o executável:

```text
vm.exe
```

Caso não ocorram mensagens de erro, a compilação foi realizada com sucesso.

---

## 8. Execução dos Testes

### Teste com acessos aleatórios

```bash
./vm < data/addresses_random.txt
```

Esse teste simula acessos distribuídos aleatoriamente pela memória virtual.

---

### Teste com localidade de referência

```bash
./vm < data/addresses_location.txt
```

Esse teste simula acessos próximos entre si, representando a localidade de referência.

---

## 9. Resultados Apresentados

Ao final da execução o programa apresenta:

* Número total de endereços traduzidos.
* Quantidade de page faults.
* Taxa de page faults.
* Quantidade de acertos do TLB.
* Taxa de acertos do TLB.

Exemplo:

```text
Number of Translated Addresses = 10000
Page Faults = 1164
Page Fault Rate = 0.116
TLB Hits = 7925
TLB Hit Rate = 0.792
```
---
