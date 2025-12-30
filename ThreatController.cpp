// ThreatController.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ThreatController.h"
#include <iostream>
#include <fstream>
#include <ctime>

// Helper function to get current timestamp safely
std::string ThreatController::getCurrentTimestamp() {
    time_t now = time(nullptr); // Get current time as a timestamp
    struct tm timeStruct;

    // Use localtime_s to populate timeStruct safely
    localtime_s(&timeStruct, &now);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeStruct); // Format the time
    return std::string(buffer);
}

// Log a new threat
void ThreatController::logThreat() {
    std::string id = view.promptInput("Enter Threat ID: ");
    std::string level = view.promptInput("Enter Threat Level (Low/Medium/High/Critical): ");
    std::string description = view.promptInput("Enter Threat Description: ");
    std::string timestamp = getCurrentTimestamp();
    threats.emplace_back(id, level, description, timestamp);
    view.displayMessage("Threat logged successfully!");
}

// View all threats
void ThreatController::viewThreats() {
    view.displayThreats(threats);
}

// Filter threats by level
void ThreatController::filterThreats() {
    std::string level = view.promptInput("Enter Threat Level to Filter: ");
    std::vector<Threat> filtered;
    for (const auto& threat : threats) {
        if (threat.getLevel() == level) {
            filtered.push_back(threat);
        }
    }
    view.displayThreats(filtered);
}

// Update a threat's details
void ThreatController::updateThreat() {
    std::string id = view.promptInput("Enter Threat ID to Update: ");
    for (auto& threat : threats) {
        if (threat.getId() == id) {
            std::string newLevel = view.promptInput("Enter New Threat Level: ");
            std::string newDescription = view.promptInput("Enter New Threat Description: ");
            threat.setLevel(newLevel);
            threat.setDescription(newDescription);
            view.displayMessage("Threat updated successfully!");
            return;
        }
    }
    view.displayMessage("Threat ID not found!");
}

// Remove a threat
void ThreatController::removeThreat() {
    std::string id = view.promptInput("Enter Threat ID to Remove: ");
    for (auto it = threats.begin(); it != threats.end(); ++it) {
        if (it->getId() == id) {
            threats.erase(it);
            view.displayMessage("Threat removed successfully!");
            return;
        }
    }
    view.displayMessage("Threat ID not found!");
}

// Save threats to a file
void ThreatController::saveThreats() {
    std::ofstream outFile("threats.txt");
    for (const auto& threat : threats) {
        outFile << threat.getId() << "," << threat.getLevel() << ","
            << threat.getDescription() << "," << threat.getTimestamp() << "\n";
    }
    outFile.close();
    view.displayMessage("Threats saved to file successfully!");
}

// Load threats from a file
void ThreatController::loadThreats() {
    std::ifstream inFile("threats.txt");
    if (!inFile.is_open()) {
        view.displayMessage("No saved threats found!");
        return;
    }
    threats.clear();
    std::string id, level, description, timestamp;
    while (std::getline(inFile, id, ',') && std::getline(inFile, level, ',') &&
        std::getline(inFile, description, ',') && std::getline(inFile, timestamp)) {
        threats.emplace_back(id, level, description, timestamp);
    }
    inFile.close();
    view.displayMessage("Threats loaded from file successfully!");
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
