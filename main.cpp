#include <iostream>
#include <string>
using namespace std;

class Module {
protected:
    string name;

public:
    Module(string moduleName) : name(moduleName) {}

    virtual void execute() {
        cout << "Executing module: " << name << endl;
    }
};

class SecurityModule : public Module {
public:
    SecurityModule() : Module("Security Module") {}

    void execute() override {
        cout << "Initializing security checks..." << endl;
    }
};

class AnalyticsModule : public Module {
public:
    AnalyticsModule() : Module("Analytics Module") {}

    void execute() override {
        cout << "Running analytics engine..." << endl;
    }
};

int main() {
    Module* modules[] = {
        new SecurityModule(),
        new AnalyticsModule()
    };

    for (Module* module : modules) {
        module->execute();
        delete module;
    }

    return 0;
}
