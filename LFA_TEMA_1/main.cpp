#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int NR_MAXIM_STARI = 100;
const int NR_MAXIM_TRANZITII = 1000;
const int NR_MAXIM_SIMBOLURI = 62; //
//inregistreaza ceva de genul a b c d...A B C D...0 1 2 3 4 5 6 7 8 9<=>pozitii in vector(0 1 2 3 4 5 6 7....59 60
int index(char simbol) {
    if (simbol>='a' && simbol<='z'){
        return simbol-'a';
    } else if (simbol>='A' && simbol<='Z'){
        return 26+(simbol-'A');
    } else if(simbol>='0' && simbol<='9'){
        return 52+(simbol-'0');
    }
    return -1;
}


int main(){
    int a[NR_MAXIM_STARI][NR_MAXIM_SIMBOLURI],i,j;
///umplu toata matrice cu -1
    for (i=0;i<NR_MAXIM_STARI;i++){
        for (j=0;j<NR_MAXIM_SIMBOLURI;j++) {
            a[i][j]=-1;
        }
    }

    int numar_stari,numar_tranzitii,si,sf;
    ifstream f("numere1.in");
    f>>numar_stari>>numar_tranzitii>>si>>sf;
///pun in matrice indexii tranzitiilor spre exemplu avem o matrice 4x4 cu q0,q1,q2,q3 atat pe linie cat si pe coloana
/// va adauga indexul corespunzator simbolului pe pozitia aferenta...q0 1 q1(din q0 merge in q1 cu a)
    for (i=0;i<numar_tranzitii;i++){
        int st, sf;
        char simbol;
        f>>st>>simbol>>sf;
        int simbol_index=index(simbol);
        a[st][simbol_index] = sf;
    }

    string cuvant;
    cout<<"Introduceti cuvantul: ";
    cin>>cuvant;

    int sc=si;
    bool acceptat=true;
///verific daca cuvantul meu trece doar prin tranzitii diferite de -1..adica acolo unde avem simbol
    for (i=0;i<cuvant.length();i++){
        char simbol=cuvant[i];
        int simbol_index=index(simbol);
        if (simbol_index==-1 || a[sc][simbol_index] == -1) {
            acceptat = false;
            break;
        }
////
        sc=a[sc][simbol_index];
    }

    acceptat=acceptat&&(sc==sf);///0 daca sc nu e stare finala sau 1 daca sc e stare finala
    if (acceptat){
        cout<<"Cuvantul "<<cuvant<<" este acceptat"<<endl;
        sc=si;
        cout<<"Drumul folosit pentru acceptare este: "<<"q"<<sc<<" ";
        for (i=0;i<cuvant.length();i++) {
            char simbol=cuvant[i];
            int simbol_index=index(simbol);
            sc=a[sc][simbol_index];
            cout<<simbol<<" "<<"q"<<sc<<" ";
        }
    } else {
        cout<<"Cuvantul "<<cuvant<<" nu este acceptat" << endl;
    }

    return 0;
}
