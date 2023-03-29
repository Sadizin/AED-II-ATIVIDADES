/*  Seja uma Lista Linear por ARRANJO, instanciada como lista1A, cujos itens são números inteiros, construa ou modifique suas operações para que sejam capazes de:
a. inserir os elementos na lista;
b. verificar se um número informado pelo usuário pertence à uma lista;
c. remover um elemento de uma lista;
d. mostrar os itens de uma lista;
e. copiar os elementos de uma lista para outra lista;
f. concatenar duas listas numa outra lista;
g. intercalar os elementos de duas listas numa outra lista;
Para demonstrar o funcionamento do seu programa:
• utilize o conjunto de itens {5, 4, 7, 2, 9}, informado nesta ordem;
• use os nomes: lista1A, lista2A, lista3A e lista4A para as instâncias definidas nas operações acima.
*/

#include <iostream>
#include <clocale>
using namespace std;


const int maxTam1 = 5;
const int maxTam2 = maxTam1 *2;


struct TLista_A{

    int vetItens[maxTam1];
    int primeiro;
    int ultimo;
};

struct TLista_B{

    int vetItens[maxTam2];
    int primeiro;
    int ultimo;
};


//OPERAÇOES BASICAS LISTA A

void criarLista_A(TLista_A &lA){
    lA.primeiro = 0;
    lA.ultimo = lA.primeiro;
    cout << "Lista criada e pronta para uso!" << endl;
}

bool estaVazia(TLista_A lA){
    return lA.primeiro == lA.ultimo;
}

bool estaCheia(TLista_A lA){
    return lA.ultimo >= maxTam1;
}

void inserirItem(TLista_A &lA, int x){
    if (estaCheia(lA)){
        cout << "Lista cheia. Não posso inserir!" << endl;
    }
    else{
        lA.vetItens[lA.ultimo] = x;
        lA.ultimo++;
        cout << "Item inserido com sucesso!" << endl;
    }
}

void mostrarLista(TLista_A lA){
    cout << "=== Mostrando itens da lista ===" << endl;
    for (int i=lA.primeiro;i<lA.ultimo;i++){
        cout << "Posição: " << i << endl;
        cout << "  Item:  " << lA.vetItens[i] << endl;
    }
}



void pRetirarPos(TLista_A &lA, int p){

    int aux;

    if((estaVazia(lA)) || (p>=lA.ultimo) || (p<lA.primeiro)){
        cout << "Não posso retirar! Lista vazia ou posição fora do limite" << endl;
    }
    else{
        lA.ultimo--;
        for(aux=p;aux<lA.ultimo;aux++){
            lA.vetItens[aux] = lA.vetItens[aux+1];
        }
    }
}

//OPERAÇOES BASICAS LISTA B

void mostrarListaB(TLista_B lA){
    cout << "=== Mostrando itens da lista ===" << endl;
    for (int i=lA.primeiro;i<lA.ultimo;i++){
        cout << "Posição: " << i << endl;
        cout << "  Item:  " << lA.vetItens[i] << endl;
    }
}
void criarLista_B(TLista_B &lA){
    lA.primeiro = 0;
    lA.ultimo = lA.primeiro;
    cout << "Lista criada e pronta para uso!" << endl;
}

bool estaVaziaB(TLista_B lA){
    return lA.primeiro == lA.ultimo;
}

bool estaCheiaB(TLista_B lA){
    return lA.ultimo >= maxTam2;
}

void inserirItemB(TLista_B &lA, int x){
    if (estaCheiaB(lA)){
        cout << "Lista cheia. Não posso inserir!" << endl;
    }
    else{
        lA.vetItens[lA.ultimo] = x;
        lA.ultimo++;
        cout << "Item inserido com sucesso!" << endl;
    }
}

void pRetirarPosB(TLista_B &lA, int p){

    int aux;

    if((estaVaziaB(lA)) || (p>=lA.ultimo) || (p<lA.primeiro)){
        cout << "Não posso retirar! Lista vazia ou posição fora do limite" << endl;
    }
    else{
        lA.ultimo--;
        for(aux=p;aux<lA.ultimo;aux++){
            lA.vetItens[aux] = lA.vetItens[aux+1];
        }
    }
}



//OPERAÇOES ESPECIFICAS

void copiar(TLista_A l1, TLista_A &l2){

    if(estaVazia(l1)){
        cout << "Não posso copiar! Lista vazia!" << endl;
    }
    else{
        for (int i = 0; i < maxTam1; i++)
        {
            inserirItem(l2,l1.vetItens[i]);
        }
        system("cls");
        cout << "Lista Copiada com sucesso!" << endl;
    }

}

void Concatenar(TLista_A l1, TLista_A l2, TLista_B &l3){

    if(estaVazia(l1)){
        cout << "Não posso concatenar! Lista vazia!" << endl;
    }
    else{
        for (int i = 0; i < maxTam1; i++)
        {
            inserirItemB(l3,l1.vetItens[i]);
        }
        for (int i = 0; i < maxTam1; i++)
        {
            inserirItemB(l3,l2.vetItens[i]);
        }
        system("cls");
        cout << "Lista Concatenada com sucesso!" << endl;

    }

}

void intercalar(TLista_A l1, TLista_A l2, TLista_B &l4){

    if(estaVazia(l1)){
        cout << "Não posso intercalar! Lista vazia!" << endl;
    }
    else{
        for (int i = 0; i < maxTam1; i++)
        {
            inserirItemB(l4,l1.vetItens[i]);
            inserirItemB(l4,l2.vetItens[i]);
        }
        system("cls");
        cout << "Lista intercalada com sucesso!" << endl;

    }

}



int main(){

    setlocale(LC_ALL,"Portuguese");

    TLista_A lista1A,lista2A;
    TLista_B lista3A,lista4A;
    int item;

    criarLista_A(lista1A);
    //Inserindo itens manualmente a lista
    for(int i=0;i<maxTam1;i++){
        cout << "Digite o " << i+1 << "º numero: ";
        cin >> item;
        inserirItem(lista1A,item);
    }

    cout << "    MOSTRANDO A LISTA 1     " << endl;
    mostrarLista(lista1A);

    system("pause");
    //Copiando item de 1 lista para outra
    criarLista_A(lista2A);
    copiar(lista1A,lista2A);

    cout << "    MOSTRANDO A LISTA 2     " << endl;
    mostrarLista(lista2A);

    system("pause");
    //Concatenando as 2 listas
    criarLista_B(lista3A);
    Concatenar(lista1A,lista2A,lista3A);

    cout << "    MOSTRANDO A LISTA 3     " << endl;
    mostrarListaB(lista3A);

    system("pause");
    //Concatenando as 2 listas
    criarLista_B(lista4A);
    intercalar(lista1A,lista2A,lista4A);

    cout << "    MOSTRANDO A LISTA 4     " << endl;
    mostrarListaB(lista4A);



    return 0;
}
