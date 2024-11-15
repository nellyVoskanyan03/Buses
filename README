# Buses 2: Optimal Bus Pathing System

## Overview
**Buses 2** is a project that calculates optimal bus routes for a newly designed city represented as a graph of crossroads and streets. The goal is to provide efficient and fast routing, dynamic street addition, and detailed route breakdowns for buses. This system is ideal for city planning applications where continuous updates to infrastructure need to be reflected immediately in transportation routes.

## Features
The system supports the following operations:

1. **Shortest Path Calculation**: For each newly added bus, the system calculates the shortest travel time between its start and end points with an optimal \(O(1)\) time complexity.
2. **Dynamic Street Addition**: When a new street is added, the system updates all affected paths for existing buses to reflect the change in the city's layout. This operation has an \(O(N^2)\) time complexity.
3. **Detailed Route Breakdown**: For a specific bus, the system provides the exact crossroads it should traverse to reach its destination efficiently. This operation has an \(O(N \log M)\) time complexity.

## Requirements
- **Floyd-Warshall Algorithm**: Used to handle the shortest path calculations for the operations of adding a new bus and adding a new street.
- **Dijkstra’s Algorithm**: Used to provide detailed route information for specific buses.
- **Adjacency List**: Employed to store the graph of crossroads and streets, optimizing space and access speed.

## Code Structure

### Source Files (`src` Directory)
| File             | Description                                |
|------------------|--------------------------------------------|
| `city.cpp`       | Implements the city representation, including functionality for managing crossroads and streets, and shortest path calculations. |
| `crossRoad.cpp`  | Defines individual crossroads and their properties in the city's graph. |
| `main.cpp`       | The main program file, handles user input and coordinates the execution of different operations. |

### Header Files (`include` Directory)
| File             | Description                                |
|------------------|--------------------------------------------|
| `bus.h`          | Declares the `Bus` class, which manages each bus's unique properties and path information. |
| `city.h`         | Declares the `City` class, which handles the overall structure and operations of the city's graph. |
| `crossRoad.h`    | Declares the `CrossRoad` class, representing individual nodes in the city's graph. |

## Algorithms

### Floyd-Warshall
Used for calculating shortest paths for all pairs of crossroads. This algorithm ensures that the system can update pathing efficiently when new streets are added.

### Dijkstra's Algorithm
Provides detailed routing information for individual buses, focusing on the shortest path from a specific starting point to a destination.

### Adjacency List Representation
The city's layout is stored in an adjacency list, allowing efficient storage and retrieval of streets and travel times between crossroads.

## Complexity Analysis

| Operation             | Complexity  |
|-----------------------|-------------|
| Add Bus               | \(O(1)\)    |
| Add Street            | \(O(N^2)\)  |
| Route Breakdown       | \(O(N \log M)\) |

## Future Enhancements
- **Dynamic Traffic Updates**: Allow real-time updates of street travel times based on traffic conditions.
- **Alternative Path Options**: Suggest alternative routes in case of congestion or closures.
- **Visualization**: Integrate a map-based visualization of the bus routes and paths.
