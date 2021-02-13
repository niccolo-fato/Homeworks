/*scrivere un programma che inserisce in una tabella i dati di una serie di
film, i dati sono composti da un titolo, autore,incasso e
nazionalita(italia,francia,..). Il programma esegua le seguenti funzionalità:
1)Stampi l'incasso medio dei film di un determinato autore
2)dato il titolo di un film in input stampi i dati di quel film
3)stampi i dati del film straniero con maggiore incasso
4)dato un incasso in input ,stampi la lista dei titoli di film con incasso
superiore all'incasso fornito in input*/
#include <iostream>
#include <string>
using namespace std;
const int mf = 1000;
int nf = 0;
bool riprova = 0;
bool contatore = 0;
int pos = 0;
struct film
{
    string tit;
    string aut;
    float inc;
    string naz;
};
film f[mf];
void inserire()
{
    cout << "\t\t"
         << "----Film numero " << pos + 1 << "----" << endl;
    cout << "Inserire titolo del film:";
    cin >> f[nf].tit;
    cout << "Inserire l'autore del film:";
    cin >> f[nf].aut;
    cout << "Inserire l'incasso del film:";
    cin >> f[nf].inc;
    cout << "Inserire la nazionalita' del film:";
    cin >> f[nf].naz;
    nf++;
    pos++;
}
void media()
{
    string aut2;
    float s, m, cont2 = 0;
    cout << "\t\t"
         << "----MEDIA INCASSO FILM----" << endl;
    cout << "Inserire l'autore dei film:";
    cin >> aut2;
    for (int i = 0; i < nf; i++)
    {
        if (aut2 == f[i].aut)
        {
            s = s + f[i].inc;
            riprova = 1;
            cont2++;
        }
    }
    if (riprova == 1)
    {
        m = s / cont2;
        cout << "La media degli incassi dei film di " << aut2 << " e' " << m << endl;
    }
    else
    {
        cout << "!Attenzione l'autore da lei inserito non esiste!" << endl;
    }
    riprova = 0;
}
void incassi()
{
    string n = "italiana", naz2;
    float m = 0;
    for (int i = 0; i < nf; i++)
    {
        if (n != f[i].naz)
        {
            if (m < f[i].inc)
            {
                naz2 = f[i].tit;
                m = f[i].inc;
            }
        }
    }
    cout << "\t\t"
         << "----FILM STRANIERO CON PIU' INCASSI----" << endl;
    cout << "Il film straniero con piu' incassi e' " << naz2
         << " ed ha un incasso di " << m << "$" << endl;
}
void maggiore()
{
    float inc2;
    cout << "\t\t"
         << "----INCASSI MAGGIORI----" << endl;
    cout << "Inserire un incasso per trovare i film con gli incassi maggiori:";
    cin >> inc2;
    cout << "\t\t"
         << "-Lista film con incassi maggiori:-" << endl;
    for (int i = 0; i < nf; i++)
    {
        if (inc2 < f[i].inc)
        {
            cout << "Il titolo del film e' " << f[i].tit << ",l'autore e' "
                 << f[i].aut << ", l'incasso e' " << f[i].inc << "$"
                 << " e la nazionalita' e' " << f[i].naz << endl;
        }
    }
}
void stampa()
{
    cout << "\t\t"
         << "----LISTA DEI FILM----" << endl;
    for (int i = 0; i < nf; i++)
    {
        cout << "Il titolo del film e' " << f[i].tit << ",l'autore e' " << f[i].aut
             << ", l'incasso e' " << f[i].inc << "$"
             << " e la nazionalita' e' " << f[i].naz << endl;
    }
}
void elimina()
{
    string tit3;
    cout << "\t\t"
         << "----CANCELLA UN FILM----" << endl;
    do
    {
        contatore = 0;
        cout << "Inserire titolo del film che si vuole cancellare:";
        cin >> tit3;
        for (int i = 0; i < nf; i++)
        {
            if (tit3 == f[i].tit)
            {
                for (int j = i; j <= nf; j++)
                {
                    f[j].tit = f[j + 1].tit;
                    f[j].aut = f[j + 1].aut;
                    f[j].inc = f[j + 1].inc;
                    f[j].naz = f[j + 1].naz;
                    riprova = 1;
                }
                f[nf].tit = " ";
                f[nf].aut = " ";
                f[nf].inc = 0;
                f[nf].naz = " ";
                nf--;
                i = nf;
            }
        }
        if (riprova != 0)
        {
            cout << "\t\t"
                 << "!Il film e' stato cancellato con successo!" << endl;
        }
        else
        {
            cout << "Il titolo del film da lei inserito non e' stato trovato "
                    "per riprovare prema 1 per andare avanti prema 0:";
            cin >> contatore;
        }
        riprova = 0;
    } while (contatore != 0);
}
int main()
{
    int cont = 0;
    do
    {
        cout << "\t\t"
             << "----MENU SCELTA----" << endl;
        cout << "Inserire 1 per registrare un film," << endl;
        cout << "Inserire 2 per stampare l'incasso medio dei film di un autore," << endl;
        cout << "Inserire 3 per stampare i dati del film straniero con piu' incassi," << endl;
        cout << "Inserire 4 per trovare i film maggiori ad un determinato incasso," << endl;
        cout << "Inserire 5 se si vuole stampare tutti i film inseriti fino ad ora, " << endl;
        cout << "Inserire 6 per cercare e eliminare un film," << endl;
        cout << "Inserire 0 per uscire." << endl;
        cout << "Scelta:";
        cin >> cont;
        switch (cont)
        {
        case 1:
        {
            inserire();
            cout << "==============================================================" << endl;
        }
        break;
        case 2:
        {
            media();
            cout << "==============================================================" << endl;
        }
        break;
        case 3:
        {
            incassi();
            cout << "==============================================================" << endl;
        }
        break;
        case 4:
        {
            maggiore();
            cout << "==============================================================" << endl;
        }
        break;
        case 5:
        {
            stampa();
            cout << "==============================================================" << endl;
        }
        break;
        case 6:
        {
            elimina();
            cout << "==============================================================" << endl;
        }
        break;
        default:
            cout << "Scelta errata" << endl;
            break;
        }
    } while (cont != 0);
    return 0;
}