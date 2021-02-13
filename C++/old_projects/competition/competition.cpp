/*A un concorso di bellezza partecipano N ragazze. Le informazioni per ogni ragazza, da memorizzare in una
  tabella sono:
  -cognome,
  -località di provenienza,
  -età,
  -altezza.
  Scrivi un programma che, dopo aver caricato i dati delle ragazze, permetta di:
  -calcolare e stampare l'età mdia delle partecipanti provenienti da una determinata 
   località fornita in input,
  -dato in input il cognome di una partecipante, stampare la località di provenienza e l'età (segnalare se 
   non esiste),
  -ordinare e stampare l'elenco in base all'età,
  -contare quante sono le ragazze con una differenza di altezza di almeno DELTA rispetto a un valore H
   fornito in input,
  -spostare le ragazze con età superiore ai 18 anni in un altro file.*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MR = 10;
struct concorso {
  string c;
  float eta;
  string prov;
  float h;
};
fstream dati;
int nr = 0;
concorso c[MR];
float media(string prov2) { //Media ragazze di una determinata località
  float media;
  int cont = 0;
  for (int i = 0; i < nr; i++) {
    if (prov2 == c[i].prov) {
      media += c[i].eta;
      cont++;
    }
  }
  media /= cont;
  return media;
}
void cerca() { //Cerca partecipante
  string c2;
  bool riprova = false;
  cout << "\t\t"<< "----CERCA PARTECIPANTE----" << endl;
       cout<<"Inserisci il cognome del partecipante che si desidera cercare:";
       cin>>c2;
  for (int i = 0; i < nr; i++) {
    if (c[i].c == c2) {
      cout << "La provenienza di " << c[i].c << " e' " << c[i].prov
           << " e l' eta' e' " << c[i].eta << endl;
      riprova = true;
    }
  }
  if (riprova == false)
    cout << "!Il partecipante da lei cercato non esiste!" << endl;
  riprova = false;
}
void ordina() { //Ordina e stampa partecipanti in base all'età
  concorso tmp;
  for (int i = 0; i < nr - 1; i++) {
    for (int j = i + 1; j < nr; j++) {
      if (c[i].eta > c[j].eta) {
        tmp = c[i];
        c[i] = c[j];
        c[j] = tmp;
      }
    }
  }
  cout << "LISTA PARTECIPANTI:" << endl;
  for (int i = 0; i < nr; i++) {
    cout << "\t\t"<< "----Partecipante numero " << i + 1 << "----" << endl;
    cout << "Cognome:" << c[i].c << endl;
    cout << "Eta':" << c[i].eta << endl;
    cout << "Provenienza:" << c[i].prov << endl;
    cout << "Altezza:" << c[i].h << endl;
  }
}
void differenza() { //Stampa ragazze con una differenza di DELTA
  float h2, delta;
  cout << "Inserire altezza:";
  cin >> h2;
  cout << "Inserire delta:";
  cin >> delta;
  cout<<"\t\t"<<"----Le partecipanti con altezza maggiore o minore di delta sono:----"<<endl;
  for (int i = 0; i < nr; i++) {
    if (c[i].h < (h2 - delta) || c[i].h > (h2 + delta)) {
      cout << c[i].c << " ha un altezza di " << c[i].h << endl;
    }
  }
}
void sposta(){ //Sposta ragazze con età maggiore di 18 anni in un secondo file
  dati.open("dati2.txt", ios::out);
   for (int i = 0; i < nr; i++) {
    if (c[i].eta >= 18) {
      dati << c[i].c << "\t" << c[i].prov<< "\t"<< c[i].eta<< "\t" << c[i].h<<endl;
    }
  }
  cout << "!I partecipanti con eta' maggiori di 18 anni sono stati inseriti nel "
          "file dati2.txt!"<< endl;
  dati.close();
}
int main() {
  dati.open("dati.txt", ios::in);
    while (!dati.eof()) {
      dati >> c[nr].c >> c[nr].prov >> c[nr].eta >> c[nr].h;
      nr++;
    }
  dati.close();
  int cont = 0;
  do {
    cout << "\t\t"<< "----MENU SCELTA----" << endl;
    cout << "Inserire 1 per fare la media," <<"\n"
            "Inserire 2 per cercare un partecipante," <<"\n"
            "Inserire 3 per ordinare le partecipanti," <<"\n"
            "Inserire 4 per stampare i partecipanti in base al delta," <<"\n"
            "Inserire 5 per inserire i partecipanti con eta' maggiore di 18 anni in un altro file" <<"\n"
            "Inserire 0 per uscire." <<"\n"
            "Scelta:";
    cin >> cont;
    switch (cont) {
    case 0: {
      cout<<"!Hai deciso di uscire dal programma!"<<endl;
    } break;
    case 1: {
      string prov2;
      cout << "\t\t"<< "----CALCOLO MEDIA----" << endl;
      cout << "Inserire la località delle partecipanti:";
      cin >> prov2;
      cout << "La media è " << media(prov2) << endl;
      cout << "--------------------------------------------------------------"<< endl;
    } break;
    case 2: {
      cerca();
      cout << "--------------------------------------------------------------"<< endl;
    } break;
    case 3: {
      ordina();
      cout << "--------------------------------------------------------------"<< endl;
    } break;
    case 4: {
      differenza();
      cout << "--------------------------------------------------------------"<< endl;
    } break;
    case 5: {
      sposta();
      cout << "--------------------------------------------------------------"<< endl;
    } break;
    default:
      cout << "Scelta errata" << endl;
      break;
    }
  } while (cont != 0);
  return 0;
}