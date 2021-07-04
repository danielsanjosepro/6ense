#pragma once

#include <Arduino.h>
#include "Sonar.h"
#include "I_Component.h"
#include "I_BTSender.h"

#include <vector>

class SonarCollection : public I_Component, public I_BTSender{
public:
    // Component Interface
    void setup(bool sonar_on) override;
    void loop(bool sonar_on) override;

    // Blutooth Sender Interface
    String getData() override;

    // Constructor
    SonarCollection();

    std::vector<Sonar> sonarVector;
private:

};

extern SonarCollection sonarCollection;