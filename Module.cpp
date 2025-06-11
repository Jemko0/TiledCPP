
#include "Module.h"
#include <iostream>

void ModuleManager::InitializeAll() {
    for (auto& module : m_Modules) {
        if (module) {
            std::cout << "Initializing module: " << module->GetName() << std::endl;
            if (!module->Initialize()) {
                std::cerr << "Failed to initialize module: " << module->GetName() << std::endl;
                // Handle error - maybe throw or set error flag
            }
        }
    }
}

void ModuleManager::UpdateAll(float deltaTime) {
    for (auto& module : m_Modules) {
        if (module) {
            module->Update(deltaTime);
        }
    }
}

void ModuleManager::ShutdownAll() {
    for (auto it = m_Modules.rbegin(); it != m_Modules.rend(); ++it) {
        if (*it) {
            std::cout << "Shutting down module: " << (*it)->GetName() << std::endl;
            (*it)->Shutdown();
        }
    }
    m_Modules.clear();
}