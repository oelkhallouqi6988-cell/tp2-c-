#include <iostream>
#include <string>
using namespace std;

// Declaration anticipee
class Filiere;

class Etudiant {
private:
    string nom;
    string cin;
    double note1, note2, note3;
    Filiere* filiere;

public:
    Etudiant(string n, string c, double n1, double n2, double n3)
        : nom(n), cin(c), note1(n1), note2(n2), note3(n3),
          filiere(nullptr) {}

    string getNom() const {
        return nom;
    }

    string getCin() const {
        return cin;
    }

    void setFiliere(Filiere* f) {
        filiere = f;
    }

    Filiere* getFiliere() const {
        return filiere;
    }
};

class Filiere {
private:
    string nomFiliere;
    Etudiant* etudiantInscrit;

public:
    Filiere(string nom)
        : nomFiliere(nom), etudiantInscrit(nullptr) {}

    void inscrireEtudiant(Etudiant* e) {
        if (e == nullptr) {
            cout << "Etudiant invalide !" << endl;
            return;
        }

        if (etudiantInscrit != nullptr) {
            cout << "Filiere deja occupee !" << endl;
            return;
        }

        if (e->getFiliere() != nullptr) {
            cout << "Etudiant deja inscrit dans une filiere !" << endl;
            return;
        }

        etudiantInscrit = e;
        e->setFiliere(this);
    }

    Etudiant* getEtudiantInscrit() const {
        return etudiantInscrit;
    }

    void afficherInfo() const {
        cout << "Filiere : " << nomFiliere << endl;

        if (etudiantInscrit != nullptr) {
            cout << "Etudiant inscrit : "
                 << etudiantInscrit->getNom() << endl;

            cout << "CIN : "
                 << etudiantInscrit->getCin() << endl;
        } else {
            cout << "Aucun etudiant inscrit." << endl;
        }
    }
};

int main() {
    Etudiant e1("Oussama", "AB123456", 15, 16, 14);

    Filiere f1("Informatique");

    f1.inscrireEtudiant(&e1);

    f1.afficherInfo();

    return 0;
}