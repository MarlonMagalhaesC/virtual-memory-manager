# Trabalho Prático 2 — Gerenciador de Memória Virtual

## Requisitos

Para executar o projeto é necessário:

* Windows 10 ou superior.
* Python 3.
* w64devkit (GCC + Make).
* Visual Studio Code (opcional).

---

# 1. Instalação do Python

Baixe e instale:

https://www.python.org/downloads/

Durante a instalação marque:

```
Add Python to PATH
```

Após instalar, abra o Prompt de Comando e execute:

```bash
python --version
```

---

# 2. Instalação do w64devkit

Baixe:

https://github.com/skeeto/w64devkit/releases

Extraia, por exemplo:

```text
C:\w64devkit
```

---

# 3. Abrindo o terminal do w64devkit

Abra:

```text
w64devkit.exe
```

Será aberta uma janela semelhante a:

```text
C:\w64devkit>
```

Esse terminal já possui:

* gcc
* make
* ferramentas GNU

Sem ele, os comandos `gcc` e `make` podem não funcionar.

---

# 4. Entrando na pasta do projeto

Supondo que o projeto esteja em:

```text
C:\Users\Marlon\Downloads\PROJETO\vm_manager
```

No terminal do w64devkit execute:

```bash
cd /c/Users/Marlon/Downloads/PROJETO/vm_manager
```

Verifique se os arquivos aparecem:

```bash
ls
```

Deve aparecer:

```text
data
include
src
Makefile
```

---

# 5. Gerando os arquivos de teste

Entre na pasta:

```bash
cd data
```

Execute:

```bash
python generate_data.py
```

Serão criados:

* BACKING_STORE.bin
* addresses_random.txt
* addresses_location.txt

Retorne:

```bash
cd ..
```

---

# 6. Compilando o projeto

Execute:

```bash
make
```

Será criado:

```text
vm.exe
```

Se quiser recompilar completamente:

```bash
make clean
make
```

---

# 7. Executando os testes

Teste aleatório:

```bash
./vm < data/addresses_random.txt
```

Teste com localidade:

```bash
./vm < data/addresses_location.txt
```

---

# 8. Resultados

O programa exibirá:

* endereço lógico;
* endereço físico;
* valor armazenado;
* número de page faults;
* taxa de page faults;
* número de TLB hits;
* taxa de TLB hits.

Exemplo:

```text
Number of Translated Addresses = 10000
Page Faults = 1164
Page Fault Rate = 0.116
TLB Hits = 7925
TLB Hit Rate = 0.792
```

---

# Observação

O projeto foi desenvolvido e testado utilizando o terminal do w64devkit. Recomenda-se utilizar esse ambiente para garantir compatibilidade com os comandos GCC e Make.
