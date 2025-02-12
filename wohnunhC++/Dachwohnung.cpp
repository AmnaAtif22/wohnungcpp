#include "Dachwohnung.h"
#include <iomanip>
#include <sstream>
using namespace std;

Dachwohnung::Dachwohnung(double flaecheInnen, double flaecheBalkon, double flaecheSchraegen)
    : Wohnung(flaecheInnen, flaecheBalkon), flaecheSchraegen(flaecheSchraegen) {}

Dachwohnung::Dachwohnung() : Wohnung(), flaecheSchraegen(0.0) {}

double Dachwohnung::getFlaecheSchraegen() const {
    return flaecheSchraegen;
}

void Dachwohnung::setFlaecheSchraegen(double flaecheSchraegen) {
    this->flaecheSchraegen = flaecheSchraegen;
}

double Dachwohnung::getGesamt() const {
    return getFlaecheInnen() - (flaecheSchraegen / 2) + (getFlaecheBalkon() / 2);
}

string Dachwohnung::toString() const {
    ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "Dachwohnung [Innenfläche: " << getFlaecheInnen() << " m², Balkonfläche: " << getFlaecheBalkon() << " m², Schrägenfläche: " << flaecheSchraegen << " m², Gesamtfläche: " << getGesamt() << " m²]";
    return oss.str();
}