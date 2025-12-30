#ifndef THREAT_H
#define THREAT_H

#include <string>

class Threat {
private:
    std::string id;
    std::string level;
    std::string description;
    std::string timestamp;

public:
    Threat(const std::string& id, const std::string& level, const std::string& description, const std::string& timestamp);

    std::string getId() const;
    std::string getLevel() const;
    std::string getDescription() const;
    std::string getTimestamp() const;

    void setLevel(const std::string& newLevel);
    void setDescription(const std::string& newDescription);
};

#endif // THREAT_H