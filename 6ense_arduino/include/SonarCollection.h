#pragma once

#include <Arduino.h>
#include "Sonar.h"
#include "I_Component.h"
#include "I_BTSender.h"

#include <vector>

class SonarCollection : public I_Component, public I_BTSender{
public:
    // Component Interface
    void setup(bool sonarOn) override;
    void loop(bool sonarOn) override;

    // Blutooth Sender Interface
    String getData() override;
    void updateScore(Scorer scorer) override;

    // Constructor
    SonarCollection();

    std::vector<Sonar> sonarVector;
private:

};

extern SonarCollection sonarCollection;