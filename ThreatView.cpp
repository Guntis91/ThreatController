#include "ThreatView.h"
#include <iostream>
#include <iomanip>

void ThreatView::displayThreats(const std::vector<Threat>& threats) {
    std::cout << std::setw(10) << "ID" << std::setw(15) << "Level"
        << std::setw(30) << "Description" << std::setw(25) << "Timestamp" << "\n";
    std::cout << std::string(80, '-') << "\n";
    for (const auto& threat : threats) {
        std::cout << std::setw(10) << threat.getId()
            << std::setw(15) << threat.getLevel()
            << std::setw(30) << threat.getDescription()
            << std::setw(25) << threat.getTimestamp() << "\n";
    }
}

void ThreatView::displayMessage(const std::string& message) {
    std::cout << message << "\n";
}

std::string ThreatView::promptInput(const std::string& prompt) {
    std::cout << prompt;
    std::string input;
    std::getline(std::cin, input);
    return input;
}
