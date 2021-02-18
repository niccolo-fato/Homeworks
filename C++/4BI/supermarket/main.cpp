#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

bool verify = false;

struct products {
  string code;
  string description;
  float quantity;
  float price;
};
class supermarket {
  string name_market;
  vector<products> prod;
  products p;

public:
  supermarket(string new_market) { name_market = new_market; }
  void input() {
    cout << "Inserire il codice del nuovo prodotto:";
    cin >> p.code;
    cout << "Inserire la descrizione del  nuovo prodotto:";
    getline(cin >> std::ws, p.description);
    cout << "Inserire la quantita' del prodotto:";
    cin >> p.quantity;
    cout << "Inserire il prezzo del prodotto:";
    cin >> p.price;
    prod.push_back(p);
  }
  void change_quantity() {
    string search_code;
    float new_quantity;
    int change_quantity;
    cout << "Inserire il codice del prodotto che desidera cercare:";
    cin >> search_code;
    cout << "Ricerca in corso...\n";
    for (int i = 0; i < prod.size(); i++) {
      if (prod[i].code == search_code) {
        cout << "PRODOTTO TROVATO==>Inserire 1 se vuole aumentare la quantita' "
                "o 0 se vuole diminuirla:";
        cin >> change_quantity;
        switch (change_quantity) {
        case 1:
          cout << "Inserisca quante volte e' stato venduto il "
                  "prodotto con codice "
               << prod[i].code << ":";
          cin >> new_quantity;
          prod[i].quantity -= new_quantity;
          verify = true;
          break;
        case 2:
          cout << "Inserisca la nuova quantita' del prodotto con codice "
               << prod[i].code << ":";
          cin >> new_quantity;
          prod[i].quantity += new_quantity;
          verify = true;
          break;
        default:
          cout << "ERROR==>Opzione non disponibile\n";
          break;
        }
      }
    }
    if (!verify)
      cout << "ERROR==>Il codice inserito non esiste!\n";
    verify = false;
  }
  void file() {
    ifstream new_products;
    new_products.open("supermarket.txt");
    while (!new_products.eof()) {
      new_products >> p.code >> p.quantity >> p.price >> p.description;
      if(p.code != ""){
                    prod.push_back(p);
                    verify = true;
                } else{
                    cout<<"ERROR==>E' stato  trovato un prodotto senza codice\n";
                    break;
                }
    }
    new_products.close();
    if(verify)
        cout<<"!Tutti i prodotti del file sono stati inseriti correttamente!\n";
    verify = false;
  }
  void print() {
    int num_prod = prod.size();
    cout << "\t\tProdotti del supermercato " << name_market << ":\n";
    if (num_prod != 0) {
      for (int i = 0; i < prod.size(); i++) {
        cout << "Prodotto numero " << i + 1 << ":\n";
        cout << "Codice:" << prod[i].code << "\n";
        cout << "Descrizione:" << prod[i].description << "\n";
        cout << "Quantita':" << prod[i].quantity << "\n";
        cout << "Prezzo:" << prod[i].price << "\n";
      }
    } else {
      cout << "ERROR==>Non sono stati ancora inseriti prodotti!\n";
    }
  }
};
int main() {
  int choice = 0;
  string new_market;
  cout << "Inserire nome supermercato:";
  getline(cin >> std::ws, new_market);
  supermarket m(new_market);
  do {
    cout << "\t\t----MENU' SCELTA---- \n";
    cout << "1-Per inserire un nuovo prodotto,\n"
            "2-Per cercare e cambiare la quantita' di un prodotto,\n"
            "3-Per inserire piu' prodotti da file,\n"
            "4-Per stampare\n"
            "0-Per uscire.\n"
            "Scelta:";
    cin >> choice;
    switch (choice) {
    case 0:
      cout << "Hai deciso di uscire dal programma\n";
      break;
    case 1: {
      m.input();
      cout << "============================================\n";
    } break;
    case 2: {
      m.change_quantity();
      cout << "============================================\n";
    } break;
    case 3: {
      m.file();
    } break;
    case 4: {
      m.print();
      cout << "============================================\n";
    } break;
    default:
      cout << "ERROR==>Opzione non disponibile\n";
      break;
    }
  } while (choice != 0);
}