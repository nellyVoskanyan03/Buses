#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include "crossRoad.h"
#include "bus.h"

class City {
private:
    std::map<int, std::string> crossRoadsMapper;
    std::map<std::string, int> crossRoads;
    std::vector<std::vector<std::pair<int, int>>> streets;
    std::vector<Bus> buses;
    std::vector<std::vector<int>> paths;
    std::vector<std::pair<int, int>> dijkstra;

    bool busExist(std::string a, std::string b);
    bool crossRoadExist(std::string a);
    void initFloyd();
    void floyd();
    void floyd(int a, int b);
    void initDijkstra();
    void dijkstraa(int start);
    void printBusInfo(std::string a, std::string b);
    void printBusesInfo();
    void printBusDetails(std::vector<std::string>& details, int i);

public:
    void addCrossRoad(const std::string& name);
    void addBus(const std::string& a, const std::string& b);
    void constructStreet(const std::string& a, const std::string& b, int distance);
    void busDetails(int i);
    void input();
};

#endif // CITY_H
