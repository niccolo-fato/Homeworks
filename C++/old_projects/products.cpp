/*dati in input i codici,le descrizioni e i prezzi di una serie di prodotti di
  un supermercato,
  visualizza l'elenco dei prodotti in ordine crescente di codice*/
#include <iostream>
#include <string>
using namespace std;
const int max_prod = 1000;
int num_prod = 0;
bool riprova = 0;
bool contatore = 0;
struct prodotti
{
    string prod;
    int cod;
    float prezzo;
};
struct prodotti p[max_prod];
void inserire_prod()
{ //Inserimento prodotti
    cout << "\t\t"
         << "----Prodotto numero " << num_prod + 1 << "----" << endl;
    cout << "Inserire il codice del prodotto:";
    cin >> p[num_prod].cod;
    cout << "Inserire la descrizione del prodotto:";
    cin >> p[num_prod].prod;
    cout << "Inserire il prezzo del prodotto:";
    cin >> p[num_prod].prezzo;
    num_prod++;
}
void ordinamento()
{ //Ordinamento dei prodotti in base al codice
    prodotti tmp;
    for (int i = 0; i < num_prod - 1; i++)
    {
        for (int j = i + 1; j < num_prod; j++)
        {
            if (p[i].cod > p[j].cod)
            {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    }
    cout << "!I prodotti sono stati ordinati!" << endl;
}
void eliminare_prod()
{ //Cerca e cancella un prodotto
    int cod2;
    cout << "\t\t"
         << "----CANCELLA PRODOTTO----" << endl;
    do
    {
        contatore = 0;
        cout << "Inserire il codice del prodotto che si vuole cancellare:";
        cin >> cod2;
        for (int i = 0; i < num_prod; i++)
        {
            if (cod2 == p[i].cod)
            {
                for (int j = i; j <= num_prod; j++)
                {
                    p[j].cod = p[j + 1].cod;
                    p[j].prod = p[j + 1].prod;
                    p[j].prezzo = p[j + 1].prezzo;
                    riprova = 1;
                }
                p[num_prod].cod = 0;
                p[num_prod].prezzo = 0;
                p[num_prod].prod = " ";
                num_prod--;
                break;
            }
        }
        if (riprova != 0)
        {
            cout << "!Il prodotto e' stato cancellato con successo!" << endl;
        }
        else
        {
            cout << "Il codice del prodotto da lei inserito non e' stato trovato "
                    "per riprovare premi 1 per andare avanti premi 0:";
            cin >> contatore;
        }
        riprova = 0;
    } while (contatore != 0);
}
void stampa()
{ //Stampa tutti i prodotti
    cout << "\t\t"
         << "----ELENCO PRODOTTI----" << endl;
    cout << "Codice\t\tDescrizione\t\tPrezzo" << endl;
    for (int i = 0; i < num_prod; i++)
    {
        cout << p[i].cod << "\t\t";
        cout << p[i].prod << "\t\t\t";
        cout << p[i].prezzo << "$"
             << "\t\t" << endl;
    }
}
void cambia()
{ //Cerca e modifica codice, prezzo e descrizione
    int cont2 = 0, cod3, cod4, prezzo2;
    string prod2;
    do
    {
        cout << "\t\t"
             << "----MENU SCELTA PER CAMBIARE----" << endl;
        cout << "Inserire 1 se si vuole cambiare il codice del prodotto,"
             << "\n"
                "Inserisci 2 se si vuole cambiare la descrizione del prodotto,"
             << "\n"
                "Inserisci 3 se si vuole cambiare il prezzo del prodotto,"
             << "\n"
                "Inserisci 0 per uscire."
             << "\n"
                "Scelta:";
        cin >> cont2;
        switch (cont2)
        {
        case 0:
        {
            cout << "!Hai deciso di uscire !" << endl;
        }
        break;
        case 1:
        {
            contatore = 0;
            cout << "\t\t"
                 << "----CAMBIA CODICE DEL PRODOTTO----" << endl;
            do
            {
                cout << "Inserire il codice del prodotto che si vuole cambiare:";
                cin >> cod3;
                riprova = 0;
                for (int i = 0; i < num_prod; i++)
                {
                    if (cod3 == p[i].cod)
                    {
                        cout << "Inserisci il nuovo codice:";
                        cin >> cod4;
                        p[i].cod = cod4;
                        contatore = 1;
                    }
                }
                if (contatore == 1)
                {
                    cout << "!Il codice del prodotto e' stato modificato con successo!" << endl;
                }
                else
                {
                    cout << "\t\t"
                         << "!ATTENZIONE!" << endl;
                    cout << "Il prodotto da lei cercato non e' stato trovato se vuoi "
                            "riprovare premi 1 se vuoi uscire premi 0:";
                    cin >> riprova;
                }
                contatore = 0;
            } while (riprova != 0);
        }
        break;
        case 2:
        {
            contatore = 0;
            cout << "\t\t"
                 << "----CAMBIA DESCRIZIONE DEL PRODOTTO----" << endl;
            do
            {
                cout << "Inserire il codice del prodotto che si vuole cambiare:";
                cin >> cod3;
                riprova = 0;
                for (int i = 0; i < num_prod; i++)
                {
                    if (cod3 == p[i].cod)
                    {
                        cout << "Inserisci la nuova descrizione del prodotto:";
                        cin >> prod2;
                        p[i].prod = prod2;
                        contatore = 1;
                    }
                }
                if (contatore == 1)
                {
                    cout << "!La descrizione del prodotto e' stato modificata con "
                            "successo!"
                         << endl;
                }
                else
                {
                    cout << "\t\t"
                         << "!ATTENZIONE!" << endl;
                    cout << "Il prodotto da lei cercato non e' stato trovato se vuoi "
                            "riprovare premi 1 se vuoi uscire premi 0:";
                    cin >> riprova;
                }
                contatore = 0;
            } while (riprova != 0);
        }
        break;
        case 3:
        {
            contatore = 0;
            cout << "\t\t"
                 << "----CAMBIA PREZZO DEL PRODOTTO----" << endl;
            do
            {
                cout << "Inserire il codice del prodotto che si vuole cambiare:";
                cin >> cod3;
                riprova = 0;
                for (int i = 0; i < num_prod; i++)
                {
                    if (cod3 == p[i].cod)
                    {
                        cout << "Inserisci il nuovo prezzo del prodotto:";
                        cin >> prezzo2;
                        p[i].prod = prezzo2;
                        contatore = 1;
                    }
                }
                if (contatore == 1)
                {
                    cout << "!Il prezzo del prodotto e' stato modificata con successo!" << endl;
                }
                else
                {
                    cout << "\t\t"
                         << "!ATTENZIONE!" << endl;
                    cout << "Il prodotto da lei cercato non e' stato trovato se vuoi "
                            "riprovare premi 1 se vuoi uscire premi 0:";
                    cin >> riprova;
                }
                contatore = 0;
            } while (riprova != 0);
        }
        break;
        }
    } while (cont2 != 0);
}
int main()
{
    int cont = 0;
    do
    {
        cout << "\t\t"
             << "----MENU SCELTA----" << endl;
        cout << "Inserire 1 per registrare il prodotto,"
             << "\n"
                "Inserire 2 per ordinare i prodotti,"
             << "\n"
                "Inserire 3 per eliminare un prodotto,"
             << "\n"
                "Inserire 4 per stampare i prodotti,"
             << "\n"
                "Inserire 5 se si vuole cambiare codice,descrizione o prezzo di un prodotto, "
             << "\n"
                "Inserire 0 per uscire."
             << "\n"
                "Scelta:";
        cin >> cont;
        switch (cont)
        {
        case 0:
        {
            cout << "!Hai deciso di uscire dal programma!" << endl;
        }
        break;
        case 1:
        {
            inserire_prod();
            cout << "--------------------------------------------------------------" << endl;
        }
        break;
        case 2:
        {
            ordinamento();
            cout << "--------------------------------------------------------------" << endl;
        }
        break;
        case 3:
        {
            eliminare_prod();
            cout << "--------------------------------------------------------------" << endl;
        }
        break;
        case 4:
        {
            stampa();
            cout << "--------------------------------------------------------------" << endl;
        }
        break;
        case 5:
        {
            cambia();
            cout << "--------------------------------------------------------------" << endl;
        }
        break;
        default:
            cout << "Scelta errata" << endl;
            break;
        }
    } while (cont != 0);
    return 0;
}