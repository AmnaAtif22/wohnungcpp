#ifndef WOHNUNG_H
#define WOHNUNG_H

#include <string>
#include <stdexcept>

class FalscheMieteException : public std::exception {
private:
    std::string message;
public:
    FalscheMieteException(const std::string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Wohnung {
protected:
    double flaecheInnen;
    double flaecheBalkon;
public:
    Wohnung(double flaecheInnen, double flaecheBalkon);
    Wohnung();
    double getFlaecheInnen() const;
    void setFlaecheInnen(double flaecheInnen);
    double getFlaecheBalkon() const;
    void setFlaecheBalkon(double flaecheBalkon);
    virtual double getGesamt() const;
    double berechneMietzins() const;
    virtual void ausgabeWohnung() const;
    static Wohnung einlesenWohnung();
    virtual std::string toString() const;
};

#endif // WOHNUNG_H