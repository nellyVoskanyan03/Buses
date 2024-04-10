#include "City.h"

bool City::busExist(std::string a, std::string b) {
    bool exist = false;
    for (int i = 0; i < buses.size(); i++) {
        if ((buses[i].startPoint == crossRoads[a] && buses[i].endPoint == crossRoads[b]) ||
            (buses[i].startPoint == crossRoads[b] && buses[i].endPoint == crossRoads[a])) {
            exist = true;
            break;
        }
    }
    return exist;
}

bool City::crossRoadExist(std::string a) {
    return !(crossRoads.find(a) == crossRoads.end());
}

void City::initFloyd() {
    std::vector<std::vector<int>> p(crossRoads.size(), *(new std::vector<int>(crossRoads.size(), INT_MAX)));

    for (int i = 0; i < crossRoads.size(); i++) {
        p[i][i] = 0;
    }

    for (int i = 0; i < streets.size(); i++) {
        for (int j = 0; j < streets[i].size(); j++) {
            int dest = streets[i][j].first;
            int val = streets[i][j].second;

            p[i][dest] = val;
        }
    }

    paths = p;
}

void City::floyd() {
    initFloyd();

    // all crossroads
    for (int i = 0; i < crossRoads.size(); i++) {

        // all paths
        for (int j = 0; j < paths.size(); j++) {
            for (int k = j; k < paths[j].size(); k++) {
                if (paths[j][i] != INT_MAX && paths[i][k] != INT_MAX) {
                    if (paths[j][i] < paths[j][k] - paths[i][k]) {
                        int num = paths[j][i] + paths[i][k];
                        paths[j][k] = num;
                        paths[k][j] = num;
                    }
                }
            }
        }
    }
}

void City::floyd(int a, int b) {

    // all paths
    for (int j = 0; j < paths.size(); j++) {
        for (int k = 0; k < paths[j].size(); k++) {
            int num1 = INT_MAX, num2 = INT_MAX;
            if (paths[j][a] != INT_MAX && paths[b][k] != INT_MAX) {
                if (paths[j][a] < paths[j][k] - paths[b][k] - paths[a][b])
                {
                    num1 = paths[j][a] + paths[b][k] + paths[a][b];
                }
            }

            if (paths[j][b] != INT_MAX && paths[a][k] != INT_MAX) {
                if (paths[j][b] < paths[j][k] - paths[a][k] - paths[a][b])
                {
                    num2 = paths[j][b] + paths[a][k] + paths[a][b];
                }
            }

            int num = std::min(num1, num2);
            if (num != INT_MAX) {
                paths[j][k] = num;
            }


        }
    }

}

void City::initDijkstra() {
    std::vector<std::pair<int, int>> d(crossRoads.size(), std::make_pair(-1, INT_MAX));
    dijkstra = d;
}

void City::dijkstraa(int start) {
    initDijkstra();
    std::priority_queue<CrossRoad, std::vector<CrossRoad>, std::greater<CrossRoad>> pq;

    dijkstra[start].second = 0;
    pq.push(CrossRoad(start, 0));

    while (!pq.empty()) {
        CrossRoad current = pq.top();
        pq.pop();

        int u = current.id;
        int dist = current.distance;

        if (dijkstra[u].second < dist) {
            continue;
        }

        for (const auto& neighbor : streets[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist != INT_MAX && weight != INT_MAX && dist < dijkstra[v].second - weight) {
                dijkstra[v].second = dist + weight;
                dijkstra[v].first = current.id;
                pq.push(CrossRoad(v, dijkstra[v].second));
            }
        }
    }
}

void City::printBusInfo(std::string a, std::string b) {
    if (paths[crossRoads[a]][crossRoads[b]] == INT_MAX) {
        std::cout << "Waiting for streets to be constructed..." << std::endl;
        return;
    }

    std::cout << "Minimal time for bus to get from "
        << a << " to " << b << " : "
        << paths[crossRoads[a]][crossRoads[b]] << " minutes" << std::endl;
}

void City::printBusesInfo() {

    std::cout << "The shortest paths for buses:" << std::endl;
    for (int i = 0; i < buses.size(); i++) {
        if (paths[buses[i].startPoint][buses[i].endPoint] == INT_MAX) {
            std::cout << "Waiting for streets to be constructed..." << std::endl;
            continue;
        }
        std::cout << "from " << crossRoadsMapper[buses[i].startPoint]
            << " to " << crossRoadsMapper[buses[i].endPoint] << ": " <<
            paths[buses[i].startPoint][buses[i].endPoint] << " minutes" << std::endl;

    }
}

void City::printBusDetails(std::vector<std::string>& details, int i) {

    std::cout << "Details for bus " << i << " : ";
    for (int i = 0; i < details.size(); i++) {
        std::cout << details[i] << " ";
    }
    std::cout << std::endl;

}

void City::addCrossRoad(const std::string& name) {

    if (crossRoads.find(name) == crossRoads.end()) {
        crossRoads.insert(std::make_pair(name, crossRoads.size()));
        crossRoadsMapper.insert(std::make_pair(crossRoadsMapper.size(), name));
        streets.push_back(*(new std::vector<std::pair<int, int>>()));
    }

}

void City::addBus(const std::string& a, const std::string& b) {
    if (paths.size() == 0) {
        floyd();
    }

    if (!busExist(a, b)) {
        buses.push_back(*(new Bus(crossRoads[a], crossRoads[b])));
    }

    printBusInfo(a, b);

}

void City::constructStreet(const std::string& a, const std::string& b, int distance) {

    streets[crossRoads[a]].push_back(std::make_pair(crossRoads[b], distance));
    streets[crossRoads[b]].push_back(std::make_pair(crossRoads[a], distance));


    if (buses.size() > 0) {
        paths[crossRoads[a]][crossRoads[b]] = distance;
        paths[crossRoads[b]][crossRoads[a]] = distance;

        floyd(crossRoads[a], crossRoads[b]);
        printBusesInfo();
    }
    else {
        floyd();
    }
}

void City::busDetails(int i) {

    if (i >= buses.size()) {
        std::cout << "No such bus" << std::endl;
        return;
    }

    Bus bus = buses[i];

    dijkstraa(bus.startPoint);

    std::vector<std::string> details;

    auto current = dijkstra[bus.endPoint];
    while (current.first != -1) {
        details.push_back(crossRoadsMapper[current.first]);
        current = dijkstra[current.first];
    }

    std::reverse(details.begin(), details.end());

    details.push_back(crossRoadsMapper[bus.endPoint]);

    printBusDetails(details, i);

}

void City::input() {
    int crossroadsNum = 0;
    int streetsNum = 0;

    std::cout << "Input the number of crossroads: " << std::endl;
    std::cin >> crossroadsNum;
    for (int i = 0; i < crossroadsNum; i++) {
        std::string k;
        std::cout << "crossroad " << i << " : ";
        std::cin >> k;
        addCrossRoad(k);
        std::cout << std::endl;
    }

    std::cout << "Input the number of streets: " << std::endl;
    std::cin >> streetsNum;
    for (int i = 0; i < streetsNum; i++) {
        std::string a;
        std::string b;
        int k;
        std::cout << "street (source destination duration)" << i << " : ";
        std::cin >> a >> b >> k;
        constructStreet(a, b, k);
        std::cout << std::endl;
    }

    std::cout << "program START (to exit enter EXIT)" << std::endl;
    std::cout << "Commands are \n  - add_bus \n  - construct_street \n  - details" << std::endl;

    while (true) {
        std::string command;
        std::cout << "Insert the command: ";
        std::cin >> command;
        if (command == "add_bus") {
            std::string a, b;
            std::cin >> a >> b;
            if (crossRoadExist(a) && crossRoadExist(b)) {
                addBus(a, b);
            }
            std::cout << std::endl;
        }
        else if (command == "construct_street") {
            std::string a;
            std::string b;
            int k;
            std::cin >> a >> b >> k;
            if (crossRoadExist(a) && crossRoadExist(b)) {
                constructStreet(a, b, k);
            }

            std::cout << std::endl;
        }
        else if (command == "details") {
            int k;
            std::cin >> k;
            busDetails(k);
            std::cout << std::endl;
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            std::cout << "No such command" << std::endl;
        }

    }
}
