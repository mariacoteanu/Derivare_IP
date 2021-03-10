#include <iostream>
#include <string.h>
#include <graphics.h>
#include <winbgim.h>
#include <stdio.h>

#define lmax 3
#define topmax 25
#define lung_max 250

using namespace std;

char expresie[lung_max];
char expresia[lung_max], expr_fpo[lung_max], expr_der_fpo[lung_max];

struct arbore{
    char informatie[lmax];
    char sir_c[topmax];
    arbore *stg;
    arbore *dr;
};

struct sir{
    arbore* operand;
    char operator0[topmax];
}sir_c[topmax];

struct vector0{
    char info[100][4];
    int nr;
};

void Deriveaza( arbore* arbi, arbore* arb)
{
    arbore *arb1, *arb2, *arb3, *arb4, *arb5, *arb6, *arb7;
    arb = new arbore;
    arb->informatie[0] = 'n';
    arb->informatie[1] = 'e';
    arb->informatie[2] = 'w';
    arb->stg = new arbore;
    arb->stg=NULL;
    arb->dr = new arbore;
    arb->dr=NULL;
    switch(arb->informatie[0]){
        case '0': { arb->informatie[0] = '0';
                  break;
         }
        case '1': { arb->informatie[0] = '0';
                  break;
         }
        case '2': { arb->informatie[0] = '0';
                  break;
         }
        case '3': { arb->informatie[0] = '0';
                  break;
         }
        case '4': { arb->informatie[0] = '0';
                  break;
         }
        case '5': { arb->informatie[0] = '0';
                  break;
         }
        case '6': { arb->informatie[0] = '0';
                  break;
         }
        case '7': { arb->informatie[0] = '0';
                  break;
         }
        case '8': { arb->informatie[0] = '0';
                  break;
         }
        case '9': { arb->informatie[0] = '0';
                  break;
         }
        case 'x': { Deriveaza(arbi->stg, arb3);
                    arb->stg = new arbore;
                    arb->stg=arb3;
                    Deriveaza(arbi->dr, arb4);
                    arb->dr = new arbore;
                    arb->dr = arb4;
                    arb->informatie[0] = '+';
                    break;
         }
        case '*': { arb1 = new arbore;
                    arb2 = new arbore;
                    Deriveaza(arbi->stg, arb3);
                    Deriveaza(arbi->dr, arb4);
                    arb->informatie[0]='+';
                    arb1->stg = new arbore;
                    arb1->stg=arb3;
                    arb1->dr = new arbore;
                    arb1->dr = arbi->dr;
                    arb1->informatie[0] = '*';
                    arb2->stg = new arbore;
                    arb2->stg = arbi->stg;
                    arb2->dr = new arbore;
                    arb2->dr = arb4;
                    arb2->informatie[0] = '*';
                    arb->stg = arb1;
                    arb->dr = arb2;
                    break;
         }
        case '/': { arb1 = new arbore;
                    arb2 = new arbore;
                    arb5 = new arbore;
                    Deriveaza(arbi->stg, arb3);
                    Deriveaza (arbi->dr, arb4);
                    arb1->informatie[0] = '*';
                    arb1->stg = new arbore; arb1->stg = arbi->stg;
                    arb1->dr = new arbore; arb1->dr = arb4;
                    arb2->informatie[0] = '*';
                    arb2->stg = new arbore; arb2->stg = arb3;
                    arb2->dr = new arbore; arb2->dr = arbi->dr;
                    arb5->informatie[0] = '-';
                    arb5->stg = new arbore; arb5->stg = arb1;
                    arb5->dr = new arbore; arb5->dr = arb2;
                    arb6 = new arbore;
                    arb7 = new arbore;
                    arb6->informatie[0] = '2';
                    arb6->stg = new arbore; arb6->stg = NULL;
                    arb6->dr = new arbore; arb6->dr = NULL;
                    arb7->informatie[0] = '^';
                    arb7->stg = new arbore; arb7->stg = arbi->dr;
                    arb7->dr = new arbore; arb7->dr = arb6;
                    arb->informatie[0] = '/'; arb->stg = arb5; arb->dr = arb7;
                    break;
         }
         case 's': { arb1 = new arbore;
                     arb1->informatie[0] = 'c';
                     arb1->informatie[1] = 'o';
                     arb1->informatie[2] = 's';
                     arb1->stg = new arbore; arb1->stg = arbi->stg;
                     arb1->dr = new arbore; arb1->dr = NULL;
                     Deriveaza(arbi->stg, arb2);
                     arb->informatie[0] = '*';
                     arb->stg = arb1;
                     arb->dr = arb2;
                     break;
          }
          case 'c': { Deriveaza(arbi->stg, arb4);
                      arb1 = new arbore;
                      arb2 = new arbore;
                      arb3 = new arbore;
                      arb1->informatie[0] = '0';
                      arb1->stg = new arbore; arb1->stg = NULL;
                      arb1->dr = new arbore; arb1->dr = NULL;
                      arb2->informatie[0] = 's';
                      arb2->informatie[1] = 'i';
                      arb2->informatie[2] = 'n';
                      arb2->stg = new arbore; arb2->stg = arbi->stg;
                      arb2->dr = new arbore; arb2->dr = NULL;
                      arb3->informatie[0] = '*';
                      arb3->stg = new arbore; arb3->stg = arbi->stg;
                      arb3->dr = new arbore; arb3->dr = arb4;
                      arb->informatie[0] = '=';
                      arb->stg = arb1; arb->dr = arb3;
                      break;
         }
         case 'l': { Deriveaza(arbi->stg, arb1);
                     arb->informatie[0] = '/';
                     arb->stg = arb1; arb->dr = arbi->stg;
                     break;
         }
         case 'e': { arb2 = new arbore;
                     arb2->informatie[0] = arbi->informatie[0];
                     arb2->stg = new arbore; arb2->stg = arbi->dr;
                     arb2->dr = new arbore; arb2->dr = arbi->dr;
                     Deriveaza(arbi->stg, arb1);
                     arb->informatie[0] = '*';
                     arb->stg = arb2; arb->dr = arb1;
                     break;
         }
         case '^': { Deriveaza(arbi->stg, arb1);
                     arb5 = new arbore;
                     arb2 = new arbore;
                     arb5->informatie[0]='1';
                     arb5->stg = new arbore; arb5->stg = NULL;
                     arb5->dr = new arbore; arb5->dr =  NULL;
                     arb2->informatie[0] = '-';
                     arb2->stg = new arbore; arb2->stg = arbi->dr;
                     arb2->dr = new arbore; arb2->dr = arb5;
                     arb3 = new arbore;
                     arb3->informatie[0] = '^';
                     arb3->stg = new arbore; arb3->stg = arbi->stg;
                     arb3->dr = new arbore; arb3->dr = arb2;
                     arb4 = new arbore;
                     arb4->informatie[0] = '*';
                     arb4->stg = new arbore; arb4->stg = arbi->stg;
                     arb4->dr = new arbore; arb4->dr = arb3;
                     arb->informatie[0] = '*';
                     arb->stg = arb4; arb->dr = arb1;
                     break;
         }
    }
}

void viziteaza(char info[20])
{
    puts(info);
}

void parcurgere_inordine(arbore* arborele)
{
    if(strcmp(arborele->informatie," ") != 0)
    {
        parcurgere_inordine(arborele->stg);
        viziteaza(arborele->informatie);
        parcurgere_inordine(arborele->dr);
    }
}

int main()
{
    arbore* arborele;
    arbore* arborele_derivat;
    arborele_derivat = new arbore;
    arborele = new arbore;
    strcpy(arborele->informatie, "^");
    arborele->stg = new arbore;
    strcpy(arborele->stg->informatie, "x");
    arborele->dr = new arbore;
    strcpy(arborele->dr->informatie, "2");
    arborele->stg->stg = new arbore;
    strcpy(arborele->stg->stg->informatie, " ");
    arborele->stg->dr = new arbore;
    strcpy(arborele->stg->dr->informatie, " ");
    arborele->dr->stg = new arbore;
    strcpy(arborele->dr->stg->informatie, " ");
    arborele->dr->dr = new arbore;
    strcpy(arborele->dr->dr->informatie," ");
    Deriveaza(arborele, arborele_derivat);
    parcurgere_inordine(arborele_derivat);

    return 0;
}
