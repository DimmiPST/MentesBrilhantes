# 🚀 Mentes Brilhantes: Pioneiras da Computação

Feito para a Feira de Ciências do IFTM 2026, este jogo em C traz arquitetura modular multi-plataforma (Linux/Windows). Contém laços, vetores, matrizes, criptografia e mini-games interativos para celebrar as grandes mulheres pioneiras da computação!

---

## 🛠️ Transparência de Desenvolvimento: Quem fez o quê?

Para fins acadêmicos e de valorização do esforço da equipe, dividimos exatamente como cada parte do código foi construída (separando o que foi "vibe-codado" com IA do que foi escrito à mão pelos integrantes):

### 🤖 Arquivos 100% "Vibe-codados" (Gerados com IA)
* **Prólogo (`prologo.c`):** Escrito por Miguel Augusto (com estruturação e refinamento via IA).
* **Ada Lovelace (`lovelace.c`):** Desenvolvido por Wanderson (protótipo e lógica estruturados via IA).
* **Arquivo Principal (`main.c`):** Estruturado inteiramente com IA para unir os módulos, gerenciar o fluxo cronológico e configurar a portabilidade (Linux/Windows).

### 💻 Código Humano com Assistência de IA (Escrito à mão pela equipe)
Nestas partes, o código base, a lógica principal e a criatividade vieram 100% da mão dos autores. A IA foi utilizada apenas pontualmente para adicionar as funções de pausa (`sleep`), ajustar portabilidade e transformar blocos em funções (`nome_historia`):

* **Joan Clarke (`joan_clarke.c`):** 
  * **Autoria:** Ana Clara
  * **Uso de IA:** Código estruturado pela autora; IA usada apenas para inserir as pausas cinemáticas e adaptar ao formato de função.
* **Margaret Hamilton (`hamilton.c`):** 
  * **Autoria:** Vitor Borges
  * **Uso de IA:** Lógica de busca de erros da Apollo 11 escrita à mão pelo autor; IA usada para suporte de tempo de tela e portabilidade.
* **Grace Hopper (`grace_hopper.c`):** 
  * **Autoria:** Breno e Guilherme
  * **Uso de IA:** Jogo da forca e lógica em binário desenvolvidos pelos autores; IA utilizada para refinar os prints e estruturar a função unificada.
* **Carol Shaw (`carol_shaw.c` - RIVER RAID!):** 
  * **Autoria:** J.Bena (Jorge)
  * **Destaque Técnico:** **Código  autoral e raiz!** Toda a matriz complexa do rio, a movimentação da nave (`W/A/S/D`), a descida dos inimigos (`I`), a detecção de colisão e o loop do mini-game estilo *River Raid* foram pensados e programados inteiramente à mão, com objetivo de mostrar dominio tecnico. A IA foi usada  apenas nos toques finais de formatação do texto de introdução e organização de escopo.

---

## ⚙️ Detalhes Técnicos

* **Linguagem:** C (Padrão C99+)
* **Arquitetura:** Modularizada em múltiplos arquivos `.c` com protótipos centralizados no `main.c`.
* **Portabilidade:** Suporte multiplataforma (Linux/Windows) com macros condicionais (`#ifdef _WIN32`) para controle de tempo de tela e pausas cinemáticas.
* **Conceitos aplicados:** Manipulação de matrizes, vetores, laços de repetição (`for`/`while`), condicionais, criptografia de cifra de substituição (Cesar), funções e controle de fluxo interativo.

---

## 🛠️ Como Compilar e Executar

Certifique-se de ter o compilador **GCC** instalado no seu sistema.

### No Linux (ex: Linux Mint / Ubuntu):
Abra o terminal na pasta do projeto e execute:
```bash
gcc main.c prologo.c lovelace.c joan_clarke.c grace_hopper.c hamilton.c carol_shaw.c -o jogo_temporal
./jogo_temporal

No Windows (Usando Prompt de Comando / PowerShell)
Pré-requisito: Certifique-se de ter o MinGW (GCC para Windows) instalado e configurado nas Variáveis de Ambiente do sistema.

Abra o Prompt de Comando (CMD) ou o PowerShell e navegue até a pasta do projeto utilizando o comando cd (exemplo: cd C:\caminho\para\a\pasta).

Compile todos os arquivos de código-fonte gerando um arquivo executável com a extensão .exe:

DOS
gcc main.c prologo.c lovelace.c joan_clarke.c grace_hopper.c hamilton.c carol_shaw.c -o jogo_temporal.exe
Para iniciar e rodar o jogo no Windows, digite no terminal:

DOS
jogo_temporal.exe
🎮 Como Jogar
Siga as instruções exibidas no terminal em cada fase. Responda aos desafios lógicos, desvie dos obstáculos no mini-game estilo River Raid e ajude a salvar a linha do tempo das mentes brilhantes da história da tecnologia!