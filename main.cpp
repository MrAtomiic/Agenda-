#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std; 
struct agenda{
  int id;
  string nome;
  string tell;
  string endereco;
}A[1000];
int cont=0;
void add();
void listar();
void del();
void salvar();
void listar2();
int main() {
unsigned seed = time(0);
srand(seed);
int comando;

do{
cout<<"\n    Agenda Eletrônica.  \n";
cout<<"\n\n +----------MENU----------+\n\n";
cout<<"|--------------------------|"<<endl;
cout<<"| [1] - Adicionar contato. |"<<endl;
cout<<"| [2] - Listar contatos.   |"<<endl;
cout<<"| [3] - Excluir contato.   |"<<endl;
cout<<"| [4] - Salvar no Arquivo. |"<<endl;
cout<<"| [5] - Listar do Arquivo. |"<<endl;
cout<<"| [6] - Sair.              |"<<endl;
cout<<"|--------------------------|"<<endl<<endl;
cout<<"\n\nO que deseja fazer?\n\n";
cin>>comando;


switch(comando){
  
  case 1: add();
  break; 

  case 2: listar();

  break;

  case 3: del();
  break;


  case 4: salvar();
  cout<<"Salvando";
  break;

  case 5: listar2();
  
  break; 

  case 6:
  cout<<"Saindo...";
  break;

  default:
  cout<<"\n\nOpção Inválida! Tente novamente.\n\n"; 
  break;

}}

while(comando!=6);{}


}





void add(){
while(cont<1000){
A[cont].id= rand() % 2000;
cout<<"Digite o nome:"<<endl;
cin>>A[cont].nome;
  cout<<"Digite o número de telefone:"<<endl;
  cin>>A[cont].tell;
  cout<<"Digite o endereço:"<<endl;
   cin.ignore();
  getline(cin,A[cont].endereco);
  cont++;
 break;}
 if(cont==1000){cout<<"Agenda cheia";
}


}

void listar(){
cout<<"\nID | Nome | Telefone | Endereço"<<endl;
for(int i=0; i<1000; i++ ){
  cout<<A[i].id<<"| ";
  cout<<A[i].nome<<" | ";
  cout<<A[i].tell<<" | ";
  cout<<A[i].endereco<<endl;
  cout<<"--------------------------------------------------"<<endl;
  
  }


}


void del (){
int apagar=0;
int i=0;
string nome;

cout<<"\nNome do contato que deseja apagar:"<<endl;
cin>>nome;

for(i=0; i<cont; i++){
  if(nome==A[i].nome)
  apagar=i;
}
if(apagar<0){
  cout<<"Este contato não existe.";
}else
cout<<"\n\nApagando...\n\n";
  for(i=apagar; i<cont; i++){
    A[i].id=A[i+1].id;
    A[i].nome=A[i+1].nome;
    A[i].tell=A[i+1].tell;
    A[i].endereco=A[i+1].endereco;
  

}}

void salvar(){
  ofstream arquivo;
  arquivo.open("agenda.txt",ios::out);
  
  for(cont=0; cont<1000; cont++)
  arquivo<<A[cont].id<<"  | "<<A[cont].nome<<" | "<<A[cont].tell<<"  | " <<A[cont].endereco<<endl;
  cont++;
}

void listar2(){
  cout<<"\n\nlistando\n\n";
  ifstream arquivoS;
  arquivoS.open("agenda.txt", ios::in);
if(!arquivoS){
  cout<<"Não foi possivei abrir.";
}

string linha;
  while(getline(arquivoS,linha)){
cout<< "\n ID | Nome | Telefone | Endereço "<<endl<<linha<<endl;
cout<<"---------------------------------------------"<<endl;
}

arquivoS.close();


arquivoS.close();
}