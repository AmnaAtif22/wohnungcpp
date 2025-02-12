#ifndef DACHWOHNUNG_H
#define DACHWOHNUNG_H

#include "Wohnung.h"

class Dachwohnung : public Wohnung {
private:
    double flaecheSchraegen;
public:
    Dachwohnung(double flaecheInnen, double flaecheBalkon, double flaecheSchraegen);
    Dachwohnung();
    double getFlaecheSchraegen() const;
    void setFlaecheSchraegen(double flaecheSchraegen);
    double getGesamt() const override;
    std::string toString() const override;
};

#endif // DACHWOHNUNG_H