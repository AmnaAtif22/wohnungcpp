#include "Wohnung.h"
#include "Dachwohnung.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Wohnung*> wohnungen(5);

    wohnungen[0] = new Wohnung(80.0, 12.0);
    wohnungen[1] = new Wohnung(100.0, 20.0);
    wohnungen[2] = new Dachwohnung(120.0, 20.0, 30.0);

    try {
        wohnungen[3] = new Wohnung(Wohnung::einlesenWohnung());
        wohnungen[4] = new Wohnung(Wohnung::einlesenWohnung());
    } catch (const std::invalid_argument& e) {
        std::cerr << "Fehler: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Fehler: " << e.what() << std::endl;
    }

    std::cout << "\nWohnungsinformationen:" << std::endl;
    for (Wohnung* w : wohnungen) {
        if (w != nullptr) {
            try {
                w->ausgabeWohnung();
            } catch (const FalscheMieteException& e) {
                std::cout << "Fehler: " << e.what() << std::endl;
            }
            std::cout << std::endl;
        } else {
            std::cout << "Keine gültige Wohnung erstellt." << std::endl;
        }
    }

    // Clean up dynamically allocated memory
    for (Wohnung* w : wohnungen) {
        delete w;
    }

    return 0;
}