#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int NR_MAXIM_STARI=100;
const int NR_MAXIM_TRANZITII=1000;
const int NR_MAXIM_LITERE=26;

// Functia care verifica daca un cuvant este acceptat de automat
bool accept(int automat[NR_MAXIM_STARI][NR_MAXIM_LITERE], int si, int sf, string cuvant)
{
    int sc=si;
    for (int i=0;i<cuvant.length();i++)
    {
        char litera=cuvant[i];
        int litera_index=litera-'a';
        if (automat[sc][litera_index]==-1)
        {
            // Litera nu este acceptata de automat
            return false;
        }
        sc=automat[sc][litera_index];
    }

    // Daca starea curenta este starea finala, atunci cuvantul este acceptat
    return sc==sf;
}

// Functia care afiseaza drumul folosit pentru acceptare
void afisareDrum(int automat[NR_MAXIM_STARI][NR_MAXIM_LITERE],int si,string cuvant)
{
    int sc=si;
    cout<<"Drumul folosit pentru acceptare este: "<<sc<<" ";
    for (int i=0;i<cuvant.length();i++)
    {
        char litera=cuvant[i];
        int litera_index=litera - 'a';
        sc=automat[sc][litera_index];
        cout<<litera<<" "<<sc<<" ";
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

    int numar_stari,numar_tranzitii,si;
    char litera;
    int st,sf;
    ifstream f("numere.in");
    f>>numar_stari>>numar_tranzitii>>si>>sf;
    for (int i=0;i<numar_tranzitii;i++)
    {
        int st,sf;
        char litera;
        f>>st>>litera>>sf;
        int litera_index=litera-'a';
        automat[st][litera_index]=sf;
    }

    // Citirea cuvantului
    string cuvant;
    cout<<"Introduceti cuvantul: ";
    cin>>cuvant;

    // Verificarea daca cuvantul este acceptat de automat
    if (accept(automat,si,sf,cuvant))
    {
        cout<<"Cuvantul"<<cuvant<<" este acceptat"<<endl;
        afisareDrum(automat,si,cuvant);
    }
    else
    {
        cout<<"Cuvantul "<<cuvant<<" nu este acceptat"<<endl;
    }
    return 0;
}
