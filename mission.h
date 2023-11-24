#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
int getCurrentMission(int x)
{
	int mission = 0;
	if ((x > 0) && (x < 400)) { mission = 0; }
	if (x > 400) { mission = 1; }
	if (x > 700) { mission = 2; }
	if (x > 2200) { mission = 3; }
	return mission;
}
void getTextMission(int currentMission) {
	Image mission;
	switch (currentMission)
	{
	case 0: break;
	case 1: mission.loadFromFile("run turnaround-Sheet.png"); break;
	case 2: mission.loadFromFile("run turnaround-Sheet.png"); break;
	case 3: mission.loadFromFile("run turnaround-Sheet.png"); break;
	}
};