#include <iostream>
#include <string>
#include <vector>
#include <random>    // Für den neuen Zufallsgenerator
#include <algorithm> // Für std::find

using std::string;
using std::cout;
using std::endl;
using std::vector;

// Zufallsgenerator mit Mersenne Twister (std::mt19937) und einer zufälligen Quelle (std::random_device)

using std::random_device rd;                            // Hardware-Zufallsquelle
using std::mt19937 gen(rd());                           // Mersenne-Twister-Engine
using std::uniform_int_distribution<> distrib(0, 6);    // Zufallszahlen im Bereich [0, 6] (wird dynamisch angepasst)

int main()
{

    // Vektor der Schenkenden
    vector<string> Schenkende; 
    Schenkende.push_back("Ole"); 
    Schenkende.push_back("Aris");
    Schenkende.push_back("Eva");
    Schenkende.push_back("Julia");
    Schenkende.push_back("Marie");
    Schenkende.push_back("Emil");
    Schenkende.push_back("Tim");

    // Kopie von Schenkende für Beschenkte
    vector<string> Beschenkte = Schenkende; 

    // Durchlaufen der Schenkenden
    for(int i = 0; i < Schenkende.size(); i++)
    {
        // Dynamische Anpassung der Obergrenze für die Zufallszahl
        std::uniform_int_distribution<> distrib(0, Beschenkte.size() - 1); // Zufallszahlen im Bereich [0, Beschenkte.size()-1]

        // Generiere eine Zufallszahl zwischen 0 und Beschenkte.size()-1 (Vektorlänge)
        int Zahl = distrib(gen);

        // Prüfen, ob die Zahl bereits beschenkt wurde
        while(Schenkende[i] == Beschenkte[Zahl])
        {
            Zahl = distrib(gen); // Neue Zahl generieren, wenn diese schon beschenkt wurde
        }

        // Ausgabe der Zuteilung
        cout << Schenkende[i] << " beschenkt " << Beschenkte[Zahl] << endl;

        // Die beschenkte Person aus der Liste entfernen
        Beschenkte.erase(Beschenkte.begin() + Zahl);
    }

    return 0; 
}

