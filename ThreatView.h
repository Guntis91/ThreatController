#ifndef THREATVIEW_H
#define THREATVIEW_H

#include "Threat.h"
#include <vector>
#include <string>

class ThreatView {
public:
    void displayThreats(const std::vector<Threat>& threats);
    void displayMessage(const std::string& message);
    std::string promptInput(const std::string& prompt);
};

#endif // THREATVIEW_H
