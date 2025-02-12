#include "Wohnung.h"
#include <iostream>
#include <limits>

Wohnung::Wohnung(double flaecheInnen, double flaecheBalkon) {
    if (flaecheInnen < 0 || flaecheBalkon < 0) {
        throw std::invalid_argument("Fläche darf nicht negativ sein.");
    }
    this->flaecheInnen = flaecheInnen;
    this->flaecheBalkon = flaecheBalkon;
}

Wohnung::Wohnung() : flaecheInnen(80.0), flaecheBalkon(12.0) {}

double Wohnung::getFlaecheInnen() const {
    return flaecheInnen;
}

void Wohnung::setFlaecheInnen(double flaecheInnen) {
    if (flaecheInnen < 0) {
        throw std::invalid_argument("Innenfläche darf nicht negativ sein.");
    }
    this->flaecheInnen = flaecheInnen;
}

double Wohnung::getFlaecheBalkon() const {
    return flaecheBalkon;
}

void Wohnung::setFlaecheBalkon(double flaecheBalkon) {
    if (flaecheBalkon < 0) {
        throw std::invalid_argument("Balkonfläche darf nicht negativ sein.");
    }
    this->flaecheBalkon = flaecheBalkon;
}

double Wohnung::getGesamt() const {
    return flaecheInnen + (flaecheBalkon / 2);
}

double Wohnung::berechneMietzins() const {
    double mietzins = getGesamt() * 8.50;

    if (mietzins < 200.0) {
        throw FalscheMieteException("Der berechnete Mietzins ist zu niedrig: " + std::to_string(mietzins) + " EUR.");
    } else if (mietzins > 5000.0) {
        throw FalscheMieteException("Der berechnete Mietzins ist zu hoch: " + std::to_string(mietzins) + " EUR.");
    }

    return mietzins;
}

void Wohnung::ausgabeWohnung() const {
    std::cout << "Innenfläche: " << flaecheInnen << " m²" << std::endl;
    std::cout << "Balkonfläche: " << flaecheBalkon << " m²" << std::endl;
    std::cout << "Gesamtfläche: " << getGesamt() << " m²" << std::endl;
    std::cout << "Mietzins: " << berechneMietzins() << " EUR" << std::endl;
}

Wohnung Wohnung::einlesenWohnung() {
    double innen = 0.0;
    double balkon = 0.0;

    std::cout << "Geben Sie die Innenfläche an: ";
    std::cin >> innen;
    if (innen < 0) {
        throw std::invalid_argument("Innenfläche darf nicht negativ sein.");
    }

    std::cout << "Geben Sie die Balkonfläche an: ";
    std::cin >> balkon;
    if (balkon < 0) {
        throw std::invalid_argument("Balkonfläche darf nicht negativ sein.");
    }

    return Wohnung(innen, balkon);
}

std::string Wohnung::toString() const {
    return "Wohnung { flaecheInnen = " + std::to_string(flaecheInnen) + ", flaecheBalkon = " + std::to_string(flaecheBalkon) + " }";
}