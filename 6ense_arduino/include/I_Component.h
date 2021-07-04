#pragma once

class I_Component{
    virtual void setup(bool component_on) = 0;
    virtual void loop(bool component_on) = 0;
};