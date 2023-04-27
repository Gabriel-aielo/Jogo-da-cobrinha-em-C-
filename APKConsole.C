#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


//direcoes personagem
#define STOP 0
#define ESQD 1
#define DIRT 2
#define CIMA 3
#define BAIX 4

//layout cenário
#define MURO 178 //178 Se refere ao código na tabela ascii
#define COBR 219 //178 Se refere ao código na tabela ascii
#define FRUTA 149 //178 Se refere ao código na tabela ascii



//variaveis globais
int fimGame;
const int largura = 20;
const int altura = 20;
int x, y, frutax, frutay, pontos, direcao;

/*Quando o jogo iniciar é necessário alguns paramentros já definidos, sendo a posição inicial do personagem, o estado da movimentação do 
personagem (neste caso "stop") e a quantidade de pontos inicialmente*/

void inicializar() { //inicia o jogo

    time_t t;
    fimGame = 0;
    direcao = STOP;

/*----posicao inicial personagem----*/

    x = largura / 2;
    y = altura / 2;

/*---------------------------------*/

    pontos = 0; 
    srand(time(&t)); //fornece a data e hora que o programa é iniciado

/*----posicao frutas (aleatórias)----*/

    frutax = rand() % largura + 1;
    frutay = rand() % altura + 1;

/*---------------------------------*/

}

void desenhar(){ //interface do jogo

int i;
int j;

system("cls"); //limpando a tela system(clear)

printf("\n\n");

for(i = 0; i <= largura + 2; i++){ /* Porque largura + 2? Se não somar 2 perderiamos área útil para o personagem, pois a primeira e o último
                                      caracter serão paredes alinhadas com as paredes verticais (totalizando 18 espaços horizontais )*/
    printf("%c", MURO);
}  

printf(" \a \t Pontos: %i", pontos);

for(j = 0; j <= altura; j++){ 
    
    printf("\n");    

    for(i = 0; i <= largura + 2; i++){
        
        if(i == 0 || i == largura + 2){
            
            printf("%c", MURO);
        
        } else {
            if(i == x && j == y){

                printf("%c", COBR);

            } else if(i == frutax && j == frutay){

                printf("%c", FRUTA);

            } else {
                printf(" ");
            }
        } 
       
    } 
    
    /*printf("%c", MURO);
    printf("\t\t\t%c", MURO);
    printf("\n");*/
}

printf("\n");

for(i = 0; i <= largura + 2; i++){ /* Porque largura + 2? Se não somar 2 perderiamos área útil para o personagem, pois a primeira e o último
                                      caracter serão paredes alinhadas com as paredes verticais (totalizando 18 espaços horizontais )*/
    printf("%c", MURO);
}

/*for(i = 0; i <= largura + 4; i++){
    printf("%c", MURO);
}*/

printf("\n\n");

}

void entradaDados(){ //captura dados de usuario
    
}

void logicaGame(){ //codigo das funcoes do jogo
    
}


int main() {

    //funções criadas para o código do jogo
    inicializar(); //realizada uma única vez
    while(!fimGame){

        desenhar();
        entradaDados();
        logicaGame();
        
        return 0;
    
    }


    //finalizar()  //realizada uma única vez
}