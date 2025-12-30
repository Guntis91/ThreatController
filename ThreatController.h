#ifndef THREATCONTROLLER_H
#define THREATCONTROLLER_H

#include "Threat.h"
#include "ThreatView.h"
#include <vector>
#include <string>

class ThreatController {
private:
    std::vector<Threat> threats;
    ThreatView view;

    std::string getCurrentTimestamp();

public:
    void logThreat();
    void viewThreats();
    void filterThreats();
    void updateThreat();
    void removeThreat();
    void saveThreats();
    void loadThreats();
};

#endif // THREATCONTROLLER_H
