#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define variaveis globais para numero maximo de livros exemplares e emprestimos
#define MaxLivros 100
#define MaxExemplares 10
#define MaxEmprestimos 100

//define a estrutura de pessoa
typedef struct {
    char nome[100]; //nome da pessoa
    char cpf[15]; //cpf da pessoa
} Pessoa;

//define a estrutura de livro
typedef struct {
    char titulo[150]; //titulo do livro
    char autor[100]; //nome do autor
    int ano; //ano de lancamento
    int id; //id do livro
    int qtd_disponivel; //quantidade de livro disponivel
    Pessoa emprestimos[MaxEmprestimos]; //vetor de pessoas que fizeram emprestimo
    int contador_emprestimos; //numero de quantas pessoas ja fizeram emprestimo
} Livro;

//define estrutura de biblioteca
typedef struct {
    Livro livros[MaxLivros]; //vetor de livros que armazena o maximo de livros que uma biblioteca pode(100)
    int contador_livros; //conta quantos livros ja estao cadastrados 
} Biblioteca;

// Inicializa a biblioteca
void inicializar_biblioteca(Biblioteca *b) {
    b->contador_livros = 0; //zera o contador de livros
}

// Limpa buffer do teclado
void limpar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Cadastra novo livro
void cadastrar_livro(Biblioteca *bib) {
    if (bib->contador_livros >= MaxLivros) { //verifica se ja atingiu o maximo de livros na biblioteca
        printf("\nBiblioteca cheia! Nao e possivel cadastrar mais livros.\n"); //printa a mensagem caso esteja cheia
        return;
    }

    Livro *novo = &bib->livros[bib->contador_livros]; //adereca o livro novo com o vetor de livros dentro da biblioteca
    
    printf("\n--- Cadastro de Livro ---\n");
    printf("Titulo: ");
    fgets(novo->titulo, sizeof(novo->titulo), stdin); //pega o titulo digitado pelo usuario
    novo->titulo[strcspn(novo->titulo, "\n")] = '\0'; //remove a quebra de linha
    
    printf("Autor: ");
    fgets(novo->autor, sizeof(novo->autor), stdin);//pega o nome do autor digitado pelo usuario
    novo->autor[strcspn(novo->autor, "\n")] = '\0';//remove a quebra de linha
    
    printf("Ano de publicacao: ");
    scanf("%d", &novo->ano); // pega o ano da publicacao digitado pelo usuario
    
    printf("Codigo unico (ID): ");
    scanf("%d", &novo->id); //pega o id digitado pelo usuario
    
    // Verifica se ID ja existe
    for (int i = 0; i < bib->contador_livros; i++) {
        if (bib->livros[i].id == novo->id) { //passa por todos os livros da biblioteca verificando se o id existe na biblioteca
            printf("\nErro: ID ja cadastrado!\n");
            limpar_buffer();
            return;
        }
    }
    
    printf("Quantidade disponivel (max %d): ", MaxExemplares); 
    scanf("%d", &novo->qtd_disponivel); //escaneia quantos livros estarao disponiveis
    
    //verifica se a quantidade digitada foi menor que zero ou maior que a quantidade permitida
    if (novo->qtd_disponivel < 0 || novo->qtd_disponivel > MaxExemplares) {
        printf("\nQuantidade invalida! Definindo como 0.\n");
        novo->qtd_disponivel = 0;
    }
    
    novo->contador_emprestimos = 0;
    bib->contador_livros++;
    
    limpar_buffer();
    printf("\nLivro cadastrado com sucesso!\n");
}

// Lista todos os livros
void listar_livros(Biblioteca *bib) {
    if (bib->contador_livros == 0) { //verifica se a biblioteca esta vazia
        printf("\nNenhum livro cadastrado.\n");
        return;
    }
    
    //lista os livros cadastrados
    printf("\n=== LISTA DE LIVROS ===\n");
    for (int i = 0; i < bib->contador_livros; i++) {
        Livro *l = &bib->livros[i];
        printf("\nID: %d\n", l->id);
        printf("Titulo: %s\n", l->titulo);
        printf("Autor: %s\n", l->autor);
        printf("Ano: %d\n", l->ano);
        printf("Disponiveis: %d\n", l->qtd_disponivel);
        printf("Total de emprestimos realizados: %d\n", l->contador_emprestimos);
        printf("------------------------\n");
    }
}

// Busca livro por ID, retorna indice ou -1
int buscar_livro_por_id(Biblioteca *bib, int id) {
    for (int i = 0; i < bib->contador_livros; i++) {
        if (bib->livros[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Realiza emprestimo
void realizar_emprestimo(Biblioteca *bib) {
    int id;
    printf("\nDigite o ID do livro: ");
    scanf("%d", &id);//pega o id digitado
    limpar_buffer();
    
    int idx = buscar_livro_por_id(bib, id);//busca o livro do id especificado

    if (idx == -1) { //verifica se achou um indice invalido
        printf("\nLivro nao encontrado!\n");
        return;
    }
    
    Livro *livro = &bib->livros[idx];//pega o livro desejado
    
    if (livro->qtd_disponivel <= 0) { //verifica se ainda tem disponibilidade
        printf("\nNenhum exemplar disponivel para emprestimo.\n");
        return;
    }
    
    //verifica se o numero maximod e emprestimos foi atingido
    if (livro->contador_emprestimos >= MaxEmprestimos) {
        printf("\nLimite de registros de emprestimos atingido.\n");
        return;
    }
    
    //registra os dados da pessoa que esta fazendo o emprestimo
    Pessoa p;
    printf("Nome da pessoa: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';//pega o nome
    
    printf("CPF: ");
    fgets(p.cpf, sizeof(p.cpf), stdin);
    p.cpf[strcspn(p.cpf, "\n")] = '\0';//pega o cpf
    
    // Registra emprestimo
    livro->emprestimos[livro->contador_emprestimos] = p;
    livro->contador_emprestimos++;
    livro->qtd_disponivel--;
    
    printf("\nEmprestimo realizado com sucesso!\n");
    printf("Exemplares restantes: %d\n", livro->qtd_disponivel);
}

// Devolve livro
void devolver_livro(Biblioteca *bib) {
    int id;
    printf("\nDigite o ID do livro: ");
    scanf("%d", &id);//pega o id do livro buscado
    limpar_buffer();
    
    int idx = buscar_livro_por_id(bib, id);
    //verifica index invalido
    if (idx == -1) {
        printf("\nLivro nao encontrado!\n");
        return;
    }
    
    Livro *livro = &bib->livros[idx];//pega o endereco do livro caso index valido
    
    //verifica se atingiu o numero maximo de emprestimos
    if (livro->qtd_disponivel >= MaxExemplares) {
        printf("\nTodos os exemplares ja foram devolvidos.\n");
        return;
    }

    // adiciona quantidade disponivel ja que esta devolvendo o livro
    livro->qtd_disponivel++;
    printf("\nLivro devolvido com sucesso!\n");
    printf("Exemplares disponiveis: %d\n", livro->qtd_disponivel);
}

// Consulta informacoes de um livro
void consultar_livro(Biblioteca *bib) {
    int id;
    printf("\nDigite o ID do livro: ");
    scanf("%d", &id);//pega id do livro buscado
    limpar_buffer();
    
    int idx = buscar_livro_por_id(bib, id);
    if (idx == -1) { //verifica se o index e valido
        printf("\nLivro nao encontrado!\n");
        return;
    }
    
    Livro *l = &bib->livros[idx];//pega o endereco do livro

    //printa os dados do livro
    printf("\n=== INFORMACOES DO LIVRO ===\n");
    printf("ID: %d\n", l->id);
    printf("Titulo: %s\n", l->titulo);
    printf("Autor: %s\n", l->autor);
    printf("Ano: %d\n", l->ano);
    printf("Disponiveis: %d de %d\n", l->qtd_disponivel, MaxExemplares);
    printf("Total de emprestimos: %d\n", l->contador_emprestimos);
}

// Lista todas as pessoas que emprestaram um livro
void listar_emprestimos_livro(Biblioteca *bib) {
    int id;
    printf("\nDigite o ID do livro: ");
    scanf("%d", &id);//pega o id do livro buscado
    limpar_buffer();
    
    int idx = buscar_livro_por_id(bib, id);
    if (idx == -1) { //verifica se index e valido
        printf("\nLivro nao encontrado!\n");
        return;
    }
    
    Livro *l = &bib->livros[idx];//pega endereco de memoria do livro
    
    if (l->contador_emprestimos == 0) { //verifica caso nao tenha emprestimos
        printf("\nNenhum emprestimo registrado para este livro.\n");
        return;
    }
    
    printf("\n=== EMPRESTIMOS DO LIVRO '%s' ===\n", l->titulo);
    //printa dados de cada pessoa que fez emprestimo do livro
    for (int i = 0; i < l->contador_emprestimos; i++) {
        printf("\n%d. Nome: %s\n", i + 1, l->emprestimos[i].nome);
        printf("   CPF: %s\n", l->emprestimos[i].cpf);
    }
}

//funcao principal
int main(void) {
    Biblioteca bib; //cria biblioteca
    inicializar_biblioteca(&bib); //inicializa biblioteca
    
    int opcao; //cria variavel para opcao
    
    //printa menu do sistema completo
    for (;;) {
        printf("\n========================================\n");
        printf("     SISTEMA DE BIBLIOTECA\n");
        printf("========================================\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Consultar livro por ID\n");
        printf("4 - Realizar emprestimo\n");
        printf("5 - Devolver livro\n");
        printf("6 - Listar emprestimos de um livro\n");
        printf("0 - Sair\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");
        
        //verifica se opcao digitada e um numero
        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida!\n");
            limpar_buffer();
            continue;
        }
        limpar_buffer();
        
        //switch case de opcoes
        switch (opcao) {
        case 1:
            cadastrar_livro(&bib);
            break;
        case 2:
            listar_livros(&bib);
            break;
        case 3:
            consultar_livro(&bib);
            break;
        case 4:
            realizar_emprestimo(&bib);
            break;
        case 5:
            devolver_livro(&bib);
            break;
        case 6:
            listar_emprestimos_livro(&bib);
            break;
        case 0:
            printf("\nEncerrando sistema...\n");
            return 0;
        default:
            printf("\nOpcao invalida!\n");
        }
    }
    
    return 0;
}
