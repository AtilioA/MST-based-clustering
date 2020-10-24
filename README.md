# MST-based clustering

Implementação de um algoritmo de clusterização baseado em árvores geradoras mínimas, apresentado como requisito parcial para aprovação na disciplina de Estrutura de Dados II pela Universidade Federal do Espírito Santo. O algoritmo para obtenção das árvores geradoras mínimas foi o de [Kruskal](https://en.wikipedia.org/wiki/Kruskal%27s_algorithm).

Foi utilizada a linguagem C e implementada a estrutura [union-find (disjoint-set)](https://en.wikipedia.org/wiki/Disjoint-set_data_structure), dentre algumas outras.

# Utilização

O programa é compatível apenas com plataformas UNIX; a compatibilidade com Windows não é o foco deste projeto, mas pode ser obtida alterando-se a função [qsort_r](https://linux.die.net/man/3/qsort_r) para [qsort_s](https://docs.microsoft.com/pt-br/cpp/c-runtime-library/reference/qsort-s?view=vs-2019).

Um executável pode ser obtido chamando [`make`](https://linux.die.net/man/1/make) dentro do diretório do projeto. A execução do programa se dá por 4 argumentos:

1. `./trab1`: o executável;

2. `entrada.txt`: o arquivo de entrada para leitura das informações dos pontos;

3. `k`: o número de grupos a ser obtido com a árvore geradora mínima.

4. `saida.txt`: o arquivo de saída para escrita dos grupos obtidos pelo programa.

Ex: `./trab1 entradas/3.txt 5 saida_3.txt`
