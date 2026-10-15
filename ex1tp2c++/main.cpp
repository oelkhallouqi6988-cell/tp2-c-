#include <iostream>
#include <string>
using namespace std;

class Etudiant {
private:
    string nom;
    string cin;
    double note1;
    double note2;
    double note3;

public:
    // Constructeur par defaut
    Etudiant() {
        nom = "Inconnu";
        cin = "000000000000000";
        note1 = 0;
        note2 = 0;
        note3 = 0;
    }

    // Constructeur avec parametres
    Etudiant(string n, string c, double n1, double n2, double n3) {
        nom = n;
        cin = c;
        setNote1(n1);
        setNote2(n2);
        setNote3(n3);
    }

    // Getters
    string getNom() const {
        return nom;
    }

    string getCin() const {
        return cin;
    }

    double getNote1() const {
        return note1;
    }

    double getNote2() const {
        return note2;
    }

    double getNote3() const {
        return note3;
    }

    // Setters
    void setNom(string n) {
        nom = n;
    }

    void setCin(string c) {
        cin = c;
    }

    void setNote1(double n) {
        if (n >= 0 && n <= 20)
            note1 = n;
        else
            cerr << "Note 1 invalide !" << endl;
    }

    void setNote2(double n) {
        if (n >= 0 && n <= 20)
            note2 = n;
        else
            cerr << "Note 2 invalide !" << endl;
    }

    void setNote3(double n) {
        if (n >= 0 && n <= 20)
            note3 = n;
        else
            cerr << "Note 3 invalide !" << endl;
    }

    // Calculer la moyenne
    double calculerMoyenne() const {
        return (note1 + note2 + note3) / 3.0;
    }

    // Afficher les informations
    void afficher() const {
        cout << "Nom : " << nom << endl;
        cout << "CIN : " << cin << endl;
        cout << "Note 1 : " << note1 << endl;
        cout << "Note 2 : " << note2 << endl;
        cout << "Note 3 : " << note3 << endl;
        cout << "Moyenne : " << calculerMoyenne() << endl;
    }
};

int main() {
    Etudiant e1("Oussama", "AB123456", 15, 16, 14);

    e1.afficher();

    return 0;
}