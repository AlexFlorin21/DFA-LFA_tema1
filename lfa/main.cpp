#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int NR_MAXIM_STARI=100;
const int NR_MAXIM_TRANZITII=1000;
const int NR_MAXIM_LITERE=26;

// Functia care verifica daca un cuvant este acceptat de automat
bool accept(int automat[NR_MAXIM_STARI][NR_MAXIM_LITERE], int starea_initiala, int starea_finala, string cuvant)
{
    int starea_curenta=starea_initiala;
    for (int i=0;i<cuvant.length();i++)
    {
        char litera=cuvant[i];
        int litera_index=litera-'a';
        if (automat[starea_curenta][litera_index]==-1)
        {
            // Litera nu este acceptata de automat
            return false;
        }
        starea_curenta=automat[starea_curenta][litera_index];
    }

    // Daca starea curenta este starea finala, atunci cuvantul este acceptat
    return starea_curenta==starea_finala;
}

// Functia care afiseaza drumul folosit pentru acceptare
void afisareDrum(int automat[NR_MAXIM_STARI][NR_MAXIM_LITERE],int starea_initiala,string cuvant)
{
    int starea_curenta=starea_initiala;
    cout<<"Drumul folosit pentru acceptare este: "<<starea_curenta<<" ";
    for (int i=0;i<cuvant.length();i++)
    {
        char litera=cuvant[i];
        int litera_index=litera - 'a';
        starea_curenta=automat[starea_curenta][litera_index];
        cout<<litera<<" "<<starea_curenta<<" ";
    }
}

int main()
{
    // Citirea automatului din fisier
    int automat[NR_MAXIM_STARI][NR_MAXIM_LITERE];
    for (int i=0;i<NR_MAXIM_STARI;i++)
    {
        for (int j=0;j<NR_MAXIM_LITERE;j++)
        {
            automat[i][j]=-1;
        }
    }

    int numar_stari,numar_tranzitii,starea_initiala;
    char litera;
    int starea_start,starea_finala;
    ifstream f("automat.txt");
    f>>numar_stari>>numar_tranzitii>>starea_initiala>>starea_finala;
    for (int i=0;i<numar_tranzitii;i++)
    {
        int starea_start,starea_finala;
        char litera;
        f>>starea_start>>litera>>starea_finala;
        int litera_index=litera-'a';
        automat[starea_start][litera_index]=starea_finala;
    }

    // Citirea cuvantului
    string cuvant;
    cout<<"Introduceti cuvantul: ";
    cin>>cuvant;

    // Verificarea daca cuvantul este acceptat de automat
    if (accept(automat,starea_initiala,starea_finala,cuvant))
    {
        cout<<"Cuvantul"<<cuvant<<" este acceptat"<<endl;
        afisareDrum(automat,starea_initiala,cuvant);
    }
    else
    {
        cout<<"Cuvantul "<<cuvant<<" nu este acceptat"<<endl;
    }
    return 0;
}
