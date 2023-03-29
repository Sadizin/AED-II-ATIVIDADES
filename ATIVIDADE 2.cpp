/*
    Parte da solução da questão 2
    Autor: Gabriel da Silva
*/

#include <iostream>
#include <clocale>
using namespace std;

// ESTRUTURAS

struct TItem{
    int chave;
    string valor;
    //... demais campos necessários
};

struct TCelula{
    TItem item;
    TCelula *proximo;
};

struct TListaP{
    TCelula *primeiro;
    TCelula *ultimo;
    int qtdeItens; // criado para armazenar a quantidade de itens e não precisar
                    // percorrer a lista para saber este dado
};


// OPERAÇÕES BÁSICAS

void criarLPVazia(TListaP &lp){
    lp.primeiro = new TCelula;      // criei uma NOVA célula e chamei-a de PRIMEIRO
    lp.ultimo = lp.primeiro;        // atribuí o mesmo endereço de primeiro para ULTIMO
    lp.primeiro->proximo = NULL;
    lp.qtdeItens = 0;
}

void inserirLP(TListaP &lp, TItem x){
    lp.ultimo->proximo = new TCelula;
    lp.ultimo = lp.ultimo->proximo;
    lp.ultimo->item = x;
    lp.ultimo->proximo = NULL;
    lp.qtdeItens++;
}

bool estaVaziaLP(TListaP lp){
    return lp.primeiro == lp.ultimo;
}

void mostrar(TListaP lp){

    //celAux = lp.primeiro; // começa como ponto de acesso, logo, não tem item válido

    TCelula *celAux;
    celAux = lp.primeiro->proximo; // começa como a primeira célula válida, ie, que tem item válido

    cout << "=== MOSTRANDO A LISTA === "<< endl;

    if (estaVaziaLP(lp)){
        cout << "Nenhum item a ser mostrado. Lista vazia!" << endl;
        cout << "-------------------------------------------" << endl;

    }
    else{
        while (celAux != NULL){
            cout << "End.Mem.Celula: " << celAux << endl;
            cout << "   Chave:   " << celAux->item.chave << endl;
            cout << "   Valor:   " << celAux->item.valor << endl;
            cout << "   Proximo: " << celAux->proximo << endl;
            celAux = celAux->proximo;
            cout << "End.Mem. lp.ultimo: " << lp.ultimo << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
}


// QUALQUER OPERAÇÃO SOBRE UMA CÉLULA (NEW OU DELETE) DEVE SER FEITA A PARTIR
// DA CÉLULA ANTERIOR. POR ISSO, A IMPORTÂNCIA DE UMA FUNÇÃO DE RETORNA O ENDEREÇO
// DESTA CÉLULA ANTERIOR AO CRITÉRIO ESTABELECIDO NA BUSCA PELA CHAVE OU OUTRO CAMPO.

// Esta função será usada pelo procedimento retirar!
TCelula *pegaAnterior(TListaP lp, int chaveBusca){

    TCelula *celAux;
    bool achou = false;

    celAux = lp.primeiro;   // não começamos pela célula válida (COM CONTEÚDO)
                            // mas sim pela cabeça (PONTO DE ACESSO)

    cout << "=== PROCURANDO ITEM NA LISTA === "<< endl;
    while (celAux->proximo != NULL){
        if (celAux->proximo->item.chave == chaveBusca){
            achou = true;
            return celAux;
        }
        celAux = celAux->proximo;
    }
    if (achou == false){
        return NULL;
    }
}

void retirarPorChave(TListaP &lp, int chaveBusca){
    TCelula *anterior = pegaAnterior(lp,chaveBusca); //anterior

    if (anterior == NULL){
        cout << "A chave não foi encontrada. Nenhuma célula a retirar." << endl;
    }
    else{
        TCelula *celAlvo; //alvo

        celAlvo = anterior->proximo;
        anterior->proximo = celAlvo->proximo;
        // só para mostrar os dados da célula a ser excluída!!!

        cout << "End.Mem.Celula Anterior: " << anterior << endl;
        cout << "   Chave:   " << anterior->item.chave << endl;
        cout << "   Valor:   " << anterior->item.valor << endl;
        cout << "   Proximo: " << anterior->proximo << endl;

        cout << "End.Mem.Celula Alvo: " << celAlvo << endl;
        cout << "   Chave:   " << celAlvo->item.chave << endl;
        cout << "   Valor:   " << celAlvo->item.valor << endl;
        cout << "   Proximo: " << celAlvo->proximo << endl;
        // desalocando a memória reservada pela célula alvo
        delete(celAlvo);
        lp.qtdeItens--;
    }
}

//  OPERAÇÕES ESPECÍFICAS

void concatenar2Listas(TListaP l1, TListaP l2, TListaP &l3){

    if (estaVaziaLP(l1) || estaVaziaLP(l2)){
        cout << "Não é possível concatenar!" << endl;
    }
    else{
        //criarLPVazia(l3);

        TCelula *celAux = l1.primeiro;

        while (celAux->proximo != NULL){
            inserirLP(l3,celAux->proximo->item);
            celAux = celAux->proximo;
        }

        celAux = l2.primeiro;

        while (celAux->proximo != NULL){
            inserirLP(l3,celAux->proximo->item);
            celAux = celAux->proximo;
        }
    }

}

void intercalar2LP(TListaP l1, TListaP l2, TListaP &l4){
    // verificar se estão vazias
    if (!estaVaziaLP(l1) && !estaVaziaLP(l2)){
        // verificar se têm o mesmo tamanho
        if (l1.qtdeItens == l2.qtdeItens){
        // se sim, em um único WHILE
            TCelula *celAux1, *celAux2;
            celAux1 = l1.primeiro;
            celAux2 = l2.primeiro;

            while (celAux1->proximo != NULL){
                // pega uma célula de l1 e insere em l4
                inserirLP(l4, celAux1->proximo->item);
                // pega uma célula de l2 e insere em l4
                inserirLP(l4, celAux2->proximo->item);
                // atualiza as células auxiliares
                celAux1 = celAux1->proximo;
                celAux2 = celAux2->proximo;
            }
        }
    }
}


// PROGRAMA PRINCIPAL

int main(){

    setlocale(LC_ALL,"Portuguese");

    TListaP lista1, lista2, lista3, lista4; // instanciação
    //preparando as listas para uso!
    criarLPVazia(lista1);
    criarLPVazia(lista2);
    criarLPVazia(lista3);
    criarLPVazia(lista4);


    TItem itemTemp; // criando uma variável do tipo item para receber os dados do item, antes de inserir na lista
                    // estes valores podem ser atribuídos ou coletados pela digitação. Farei os 2 exemplos

    // inserindo um item manualmente por atribuição
    itemTemp.chave = 5;
    itemTemp.valor = "Gabriel";
    inserirLP(lista1,itemTemp);
    itemTemp.chave = 4;
    itemTemp.valor = "Gabriel";
    inserirLP(lista1,itemTemp);
    itemTemp.chave = 7;
    itemTemp.valor = "Gabriel";
    inserirLP(lista1,itemTemp);
    itemTemp.chave = 2;
    itemTemp.valor = "Gabriel";
    inserirLP(lista1,itemTemp);
    itemTemp.chave = 9;
    itemTemp.valor = "Gabriel";
    inserirLP(lista1,itemTemp);

    mostrar(lista1);

       // inserindo um item manualmente por atribuição
    itemTemp.chave = 5;
    itemTemp.valor = "Gabriel";
    inserirLP(lista2,itemTemp);
    itemTemp.chave = 4;
    itemTemp.valor = "Gabriel";
    inserirLP(lista2,itemTemp);
    itemTemp.chave = 7;
    itemTemp.valor = "Gabriel";
    inserirLP(lista2,itemTemp);
    itemTemp.chave = 2;
    itemTemp.valor = "Gabriel";
    inserirLP(lista2,itemTemp);
    itemTemp.chave = 9;
    itemTemp.valor = "Gabriel";
    inserirLP(lista2,itemTemp);

    mostrar(lista2);

    cout << endl;
    cout << "------------- CONCATENANDO -------------" << endl;
    concatenar2Listas(lista1,lista2,lista3);
    mostrar(lista3);

    cout << endl;
    cout << "------------- INTERCALANDO -------------" << endl;
    intercalar2LP(lista1,lista2,lista4);
    mostrar(lista4);

    return 0;
}
