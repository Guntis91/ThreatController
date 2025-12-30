#include "ThreatController.h"
#include <iostream>

int main() {
    ThreatController controller;
    int choice;
    do {
        std::cout << "\nThreat Management System Menu:\n";
        std::cout << "1. Log New Threat\n2. View All Threats\n3. Filter Threats by Level\n";
        std::cout << "4. Update Threat Information\n5. Remove Threat\n";
        std::cout << "6. Save Threats to File\n7. Load Threats from File\n8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear input buffer

        switch (choice) {
        case 1: controller.logThreat(); break;
        case 2: controller.viewThreats(); break;
        case 3: controller.filterThreats(); break;
        case 4: controller.updateThreat(); break;
        case 5: controller.removeThreat(); break;
        case 6: controller.saveThreats(); break;
        case 7: controller.loadThreats(); break;
        case 8: std::cout << "Exiting system. Goodbye!\n"; break;
        default: std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
