#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
void citire_graf(int a[4][4],int n){
int i,j,k;
for(i=0;i<=n;i++)
    for(j=0;j<=n;j++)
        a[i][j]=-1;
ifstream f("numere.in");
while(f>>i>>j>>k){
a[i][j]=k;
cout<<"q"<<i<<" "<<k<<" "<<"q"<<j<<endl;
}
f.close();
}
int ok=1;
void q0(char s){

    if(s=='1') ok=2;
        else ok=0;
                }
void q1(char s){
  if(s=='0') ok=3;
        else ok=0;

                }
void q2(char s){
    if(s=='1') ok=4;
        else ok=0;

                }
void q3(char s){
    if(s=='1') ok=4;
        else ok=0;
                }
int main()
{
int a[4][4],n;
n=3;
citire_graf(a,n);
char numar[]="10111111";
int i,lungime=strlen(numar);
cout<<"q0"<<"->";
for(i=0;i<lungime;i++){
    if(ok==1)  q0(numar[i]);
    else if(ok==2) {cout<<"q1"<<"->";q1(numar[i]);}
        else if(ok==3){cout<<"q2"<<"->";q2(numar[i]);}
            else if(ok==4){cout<<"q3"<<"->"; q3(numar[i]);}
                else ok=0;
                            }
if (ok==4) cout<<"Acceptat";
    else cout<<"Neacceptat";
return 0;
                        }

