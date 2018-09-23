#include <stdio.h>
#include <stdlib.h>
#include <new>
#include <string.h>
#include <iostream>
#include <ctime>

using namespace std;
//declaracao dos rodilhos
void iniciamatriz(char cil[3][12]){
cil[0][0]='A';
cil[0][1]='B';
cil[0][2]='C';
cil[0][3]='D';
cil[0][4]='D';
cil[0][5]='E';
cil[0][6]='E';
cil[0][7]='E';
cil[0][8]='F';
cil[0][9]='F';
cil[0][10]='F';
cil[0][11]='F';

cil[1][0]='A';
cil[1][1]='B';
cil[1][2]='C';
cil[1][3]='C';
cil[1][4]='D';
cil[1][5]='D';
cil[1][6]='E';
cil[1][7]='E';
cil[1][8]='E';
cil[1][9]='F';
cil[1][10]='F';
cil[1][11]='F';

cil[2][0]='A';
cil[2][1]='B';
cil[2][2]='B';
cil[2][3]='C';
cil[2][4]='C';
cil[2][5]='D';
cil[2][6]='D';
cil[2][7]='E';
cil[2][8]='E';
cil[2][9]='F';
cil[2][10]='F';
cil[2][11]='F';

}

void imprimecil(char cil[3][12]){
int i, j;

for(i=0; i<3; i++){
    for(j=0; j<12; j++){
        cout << "Cilindro: " << i+1 << " Letra: " << cil[i][j] << "\n";
    }
    cout << "\n";
}

}

void gerarandom(int aleatorio[3]){
    srand(time(NULL));
    aleatorio[0]=rand() % 12;
    aleatorio[1]=rand() % 12;
    aleatorio[2]=rand() % 12;
}

void geraresultado(int aleatorio[3], char cil[3][12], string &resultado){
    resultado[0]=cil[0][aleatorio[0]];
    resultado[1]=cil[1][aleatorio[1]];
    resultado[2]=cil[2][aleatorio[2]];

}



int verificapremio(string &resultado, int aposta){
    int premio;
    if (!resultado.compare("AAA")){
        premio = aposta * 150;
        cout << "Premio: " << premio << " ("<< aposta<<" x "<<150<<")\n";
    }
    else if (!resultado.compare("BBB")){
        premio = aposta * 75;
        cout << "Premio: " << premio << " ("<< aposta<<" x "<<75<<")\n";
    }
    else if (!resultado.compare("CCC")){
        premio = aposta * 50;
        cout << "Premio: " << premio << " ("<< aposta<<" x "<<50<<")\n";
    }
    else if (!resultado.compare("DDD")){
        premio = aposta * 30;
        cout << "Premio: " << premio << " ("<< aposta<<" x "<<30<<")\n";
    }
    else if (!resultado.compare("EEE")){
        premio = aposta * 15;
        cout << "Premio: " << premio << " ("<< aposta<<" x "<<15<<")\n";
    }
    else if (!resultado.compare("FFF")){
        premio = aposta * 10;
        cout << "Premio: " << premio << " ("<< aposta<<" x "<<10<<")\n";
    }
    else{
        cout << "Premio: 0\n";
        premio=0;
    }



return premio;
}

int main(){
cout << "*** SLOT MACHINE ***\n\n";
int carteira=10000, aposta, aleatorio[3], premio;
char cil[3][12], jogar='S';
string resultado="OOO";


iniciamatriz(cil);
//imprimecil(cil);

    cout << "Carteira: " << carteira << "\n";

while(jogar == 'S' or jogar == 's'){
    cout << "Aposta (1 a 10)-> ";
    cin >> aposta;
    if (1<=aposta && aposta <=10){
        carteira=carteira-aposta;

        gerarandom(aleatorio);

        geraresultado(aleatorio, cil, resultado);
        cout << "\nResultado: " << resultado << "\n";


        premio = verificapremio(resultado, aposta);
        carteira=carteira+premio;
        cout << "Carteira: "<<carteira<<"\n";



        cout << "\nJogar de novo? (S/N): ";
        cin >> jogar;
        cin.clear();
        fflush(stdin);
        while (jogar!='S' and jogar!='s' and jogar!='N' and jogar!='n'){
            cout << "Comando Invalido.\nJogar de novo? (S/N): ";
            cin >> jogar;
            cin.clear();
            fflush(stdin);
        }

        }
    else {
        cout << "Aposta invalida, selecione um valor entre 1 e 10\n";
    }

}

cout << "*** Obrigado por jogar ***";

return 0;
}

