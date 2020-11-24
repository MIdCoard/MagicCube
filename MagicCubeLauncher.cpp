#include <cstdio>
#include "LayerBridge.cpp"
#include "util.cpp"

using namespace std;

void initialize() {
    Logic::initLogicLayer();
    Render::initRenderLayer();
}

void sync(double loopStartTime) {
    float loopSlot = 1.0f / 50;
    double endTime = loopStartTime + loopSlot;
    while(getTime() < endTime) {
        sleepMS(1);
    }
}

int main() {
    initialize();
    if (Logic::isInitialize()) {
        double secsPerUpdate = 1.0 / 30.0;
        double previous = getTime();
        double steps = 0.0;
        while (true) {
            double loopStartTime = getTime();
            double elapsed = loopStartTime - previous;
            previous = loopStartTime;
            steps += elapsed;

            handleInput();

            while (steps >= secsPerUpdate) {
                updateGameState();
                steps -= secsPerUpdate;
            }

            render();
            sync(loopStartTime);
        }
    }
}