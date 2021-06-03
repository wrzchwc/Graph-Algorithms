#include <iostream>
#include <random>
#include <chrono>
#include "Main.h"
#include "adjacency_matrix/AdjacencyMatrix.h"
#include "adjacency_list/AdjacencyList.h"
#include "dijkstra_algorithm/DijkstraAlgorithm.h"
#include "prim_algorithm/PrimAlgorithm.h"

using namespace std;
using namespace std::chrono;

int *interpret(string line, const string &delimiter, int number) {
    int *tmp = new int[number], i = 0;
    size_t position;
    string token;
    while ((position = line.find(delimiter)) != string::npos) {
        token = line.substr(0, position);
        tmp[i++] = atoi(token.c_str());
        line.erase(0, position + delimiter.length());
    }
    tmp[i] = atoi(line.c_str());
    return tmp;
}

int random_number(int minimum, int maximum) {
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<> distribution(minimum, maximum);
    return distribution(generator);
}

void save(double time, const string &filepath) {
    fstream file;
    cout << time << endl;
    file.open(filepath, ios::out | ios::app);
    file << time << endl;
    file.close();
}

int main() {
    cout << "--------------------------------DS&CC Project--------------------------------" << endl;
    cout << "Jakub Wierzchowiec, 06.2021" << endl;
    int input;                  // choice of menu option
    bool running = true;        //controls the main loop of the program
    bool mode = true;           //controls loop of specified mode
    bool algorithm = true;     //controls loop of given structure while working in specified mode
    while (running) {
        cout << "[0] Quit" << endl;
        cout << "[1] Control mode" << endl;
        cout << "[2] Metrological mode" << endl;
        cout << "> ";
        cin >> input;
        switch (input) {
            case 0: {
                running = false;
            }
                break;
            case 1: {
                auto *matrix = new AdjacencyMatrix();
                auto *list = new AdjacencyList();
                while (mode) {
                    // path to the file, where graph parameters are stored
                    string filepath, delimiter = " ";
                    bool load = false, KPUnavailable = false;
                    cout << "[0] Return to menu" << endl;
                    cout << "[1] Generate graph" << endl;
                    cout << "[2] Read graph from the file" << endl;
                    cout << "> ";
                    cin >> input;
                    switch (input) {
                        case 0: {
                            mode = false;
                            algorithm = false;
                        }
                            break;
                        case 1: {
                            load = false;
                            int size, maxWeight;
                            float density;
                            bool directed = false;
                            cout << "Number of vertexes: ";
                            cin >> size;
                            cout << "Density (edges/edges_max): ";
                            cin >> density;
                            cout << "Maximum weight of edge: ";
                            cin >> maxWeight;
                            cout << "Directed graph (1-yes, 0-no): ";
                            cin >> input;
                            if (input == 0) {
                                directed = false;
                                KPUnavailable = false;
                            } else {
                                directed = true;
                                KPUnavailable = true;
                            }
                            matrix = new AdjacencyMatrix(size, true, directed, density, maxWeight);
                            list = new AdjacencyList(matrix);
                            algorithm = true;
                            cout << "Graph generation successful." << endl;
                        }
                            break;
                        case 2: {
                            // handle for .txt file
                            fstream file;
                            cout << "WARNING! FILE MUST BE IN THE SAME FOLDER AS EXECUTABLE FILE." << endl;
                            cout << "NAME OF THE FILE SHOULD BE ENTERED LIKE THIS: name.extension" << endl;
                            cout << "Name of the file: ";
                            cin >> filepath;
                            file.open(filepath, ios::in);
                            if (file.good()) {
                                cout << "Filepath saved. No errors." << endl;
                                algorithm = true;
                                load = true;
                            } else {
                                cout << "Error! File does not exist or its name is incorrect." << endl;
                                algorithm = false;
                                load = true;
                            }
                            file.close();
                        }
                            break;
                        default: {
                            cout << "Incorrect choice! Try again." << endl;
                            algorithm = false;
                        }
                            break;
                    }
                    while (algorithm) {
                        cout << "--------------------------------Control mode--------------------------------" << endl;
                        cout << "[0] Return to menu" << endl;
                        cout << "[1] Prim Algorithm         | matrix" << endl; //undirected
                        cout << "[2] Prim Algorithm         | list" << endl; //undirected
                        cout << "[3] Dijkstra Algorithm     | matrix" << endl; //directed
                        cout << "[4] Dijkstra Algorithm     | list" << endl; //directed
                        cout << "[5] Bellman-Ford Algorithm | matrix" << endl; //directed
                        cout << "[6] Bellman-Ford Algorithm | list" << endl; //directed
                        cout << "[7] Kruskal  Algorithm     | matrix" << endl; //undirected
                        cout << "[8] Kruskal Algorithm      | list" << endl; //undirected
                        cout << "> ";
                        cin >> input;
                        input == 0 ? algorithm = false : algorithm = true;
                        if (load && input > 0) {
                            if (input == 1 || input == 2 || input == 7 || input == 8) {
                                list = new AdjacencyList(filepath, delimiter, false);
                                matrix = new AdjacencyMatrix(filepath, delimiter, false);
                            } else if (input == 3 || input == 4 || input == 5 || input == 6) {
                                list = new AdjacencyList(filepath, delimiter, true);
                                matrix = new AdjacencyMatrix(filepath, delimiter, true);
                            } else
                                cout << "Incorrect choice! Try again." << endl;
                            if (input > 0)
                                input % 2 == 1 ? matrix->show() : list->show();
                        } else if (input > 0) {
                            if (input < 9 && input % 2 == 1)
                                matrix->show();
                            else if (input < 9)
                                list->show();
                        }
                        switch (input) {
                            case 0: {
                                algorithm = false;
                            }
                                break;
                            case 1: {
                                if (!KPUnavailable || load) {
                                    cout << "[1] Prim Algorithm         | matrix" << endl; //undirected
                                    cout << "Start vertex: ";
                                    cin >> input;
                                    PrimAlgorithm::solve(matrix, input);
                                } else {
                                    cout << "Error! Mode unavailable because directed graph was generated. " << endl;
                                    cout << "Return to menu and generate undirected graph or load graph from file."
                                         << endl;
                                }
                            }
                                break;
                            case 2: {
                                if (!KPUnavailable || load) {
                                    cout << "[2] Prim Algorithm         | list" << endl; //undirected
                                    cout << "Start vertex: ";
                                    cin >> input;
                                    PrimAlgorithm::solve(list, input);
                                } else {
                                    cout << "Error! Mode unavailable because directed graph was generated. " << endl;
                                    cout << "Return to menu and generate undirected graph or load graph from file."
                                         << endl;
                                }
                            }
                                break;
                            case 3: {
                                if (KPUnavailable || load) {
                                    cout << "Start vertex: ";
                                    cin >> input;
                                    DijkstraAlgorithm::solve(matrix, input);
                                } else {
                                    cout << "Error! Mode unavailable because undirected graph was generated. " << endl;
                                    cout << "Return to menu and generate directed graph or load graph from file."
                                         << endl;
                                }

                            }
                                break;
                            case 4: {
                                if (KPUnavailable || load) {
                                    cout << "Start vertex: ";
                                    cin >> input;
                                    DijkstraAlgorithm::solve(list, input);
                                } else {
                                    cout << "Error! Mode unavailable because undirected graph was generated." << endl;
                                    cout << "Return to menu and generate directed graph or load graph from file."
                                         << endl;
                                }
                            }
                                break;
                            case 5: {
                                if (KPUnavailable || load) {
                                    cout << "[5] Bellman-Ford Algorithm | matrix" << endl; //directed
                                } else {
                                    cout << "Error! Mode unavailable because undirected graph was generated." << endl;
                                    cout << "Return to menu and generate directed graph or load graph from file."
                                         << endl;
                                }
                            }
                                break;
                            case 6: {
                                if (KPUnavailable || load) {
                                    cout << "[6] Bellman-Ford Algorithm | list" << endl; //directed
                                } else {
                                    cout << "Error! Mode unavailable because undirected graph was generated." << endl;
                                    cout << "Return to menu and generate directed graph or load graph from file."
                                         << endl;
                                }
                            }
                                break;
                            case 7: {
                                if (!KPUnavailable || load) {
                                    cout << "[7] Kruskal  Algorithm | matrix" << endl; //undirected
                                } else {
                                    cout << "Error! Mode unavailable because undirected graph was generated. " << endl;
                                    cout << "Return to menu and generate directed graph or load graph from file."
                                         << endl;
                                }
                            }
                                break;
                            case 8: {
                                if (!KPUnavailable || load) {
                                    cout << "[8] Kruskal Algorithm | list" << endl; //undirected
                                } else {
                                    cout << "Error! Mode unavailable because undirected graph was generated. " << endl;
                                    cout << "Return to menu and generate undirected graph or load graph from file."
                                         << endl;
                                }
                            }
                                break;
                            default: {
                                cout << "Incorrect choice! Try again." << endl;
                            }
                                break;
                        }
                    }

                }
                delete matrix;
                delete list;
            }
                break;
            case 2: {
                auto *matrix = new AdjacencyMatrix();
                auto *list = new AdjacencyList();
                while (mode) {
                    int size, maxWeight, startingEdge;
                    double density, time;
                    cout << "--------------------------------Metrological mode--------------------------------" << endl;
                    cout << "[0] Return to menu" << endl;
                    cout << "[1] Prim Algorithm         | matrix" << endl;
                    cout << "[2] Prim Algorithm         | list" << endl;
                    cout << "[3] Dijkstra Algorithm     | matrix" << endl;
                    cout << "[4] Dijkstra Algorithm     | list" << endl;
                    cout << "[5] Bellman-Ford Algorithm | matrix" << endl;
                    cout << "[6] Bellman-Ford Algorithm | list" << endl;
                    cout << "[7] Kruskal  Algorithm     | matrix" << endl;
                    cout << "[8] Kruskal Algorithm      | list" << endl;
                    cout << "> ";
                    cin >> input;
                    switch (input) {
                        case 0: {
                            mode = false;
                        }
                            break;
                        case 1: {
                            cout << "[1] Prim Algorithm         | matrix" << endl;
                            cout << "Vertexes: ";
                            cin >> size;
                            cout << "Maximum edge weight: ";
                            cin >> maxWeight;
                            cout << "Starting vertex: ";
                            cin >> startingEdge;
                            cout << "Density: ";
                            cin >> density;
                            cout << "Attempts: ";
                            cin >> input;
                            for (int i = 0; i < input; i++) {
                                matrix = new AdjacencyMatrix(size, true, true, density, maxWeight);
                                auto start = steady_clock::now();
                                PrimAlgorithm::solve(matrix, startingEdge);
                                auto end = steady_clock::now();
                                time = double(duration_cast<nanoseconds>(end - start).count());
                                save(time, "prim_matrix.txt");
                            }

                        }
                            break;
                        case 2: {
                            cout << "[2] Prim Algorithm         | list" << endl;
                            cout << "Vertexes: ";
                            cin >> size;
                            cout << "Maximum edge weight: ";
                            cin >> maxWeight;
                            cout << "Starting vertex: ";
                            cin >> startingEdge;
                            cout << "Density: ";
                            cin >> density;
                            cout << "Attempts: ";
                            cin >> input;
                            for (int i = 0; i < input; i++) {
                                matrix = new AdjacencyMatrix(size, true, true, density, maxWeight);
                                list = new AdjacencyList(matrix);
                                auto start = steady_clock::now();
                                PrimAlgorithm::solve(list, startingEdge);
                                auto end = steady_clock::now();
                                time = double(duration_cast<nanoseconds>(end - start).count());
                                save(time, "prim_list.txt");
                            }

                        }
                            break;
                        case 3: {
                            cout << "[3] Dijkstra Algorithm     | matrix" << endl;
                            cout << "Vertexes: ";
                            cin >> size;
                            cout << "Maximum edge weight: ";
                            cin >> maxWeight;
                            cout << "Starting vertex: ";
                            cin >> startingEdge;
                            cout << "Density: ";
                            cin >> density;
                            cout << "Attempts: ";
                            cin >> input;
                            for (int i = 0; i < input; i++) {
                                matrix = new AdjacencyMatrix(size, true, true, density, maxWeight);
                                auto start = steady_clock::now();
                                DijkstraAlgorithm::solve(matrix, startingEdge);
                                auto end = steady_clock::now();
                                time = double(duration_cast<nanoseconds>(end - start).count());
                                save(time, "dijkstra_matrix.txt");
                            }
                        }
                            break;
                        case 4: {
                            cout << "[4] Dijkstra Algorithm     | list" << endl;
                            cout << "Vertexes: ";
                            cin >> size;
                            cout << "Maximum edge weight: ";
                            cin >> maxWeight;
                            cout << "Starting vertex: ";
                            cin >> startingEdge;
                            cout << "Density: ";
                            cin >> density;
                            cout << "Attempts: ";
                            cin >> input;
                            for (int i = 0; i < input; i++) {
                                matrix = new AdjacencyMatrix(size, true, true, density, maxWeight);
                                list = new AdjacencyList(matrix);
                                auto start = steady_clock::now();
                                DijkstraAlgorithm::solve(list, startingEdge);
                                auto end = steady_clock::now();
                                time = double(duration_cast<nanoseconds>(end - start).count());
                                save(time, "dijkstra_list.txt");
                            }
                        }
                            break;
                        case 5: {
                            cout << "[5] Bellman-Ford Algorithm | matrix" << endl;
                            cout << "Vertexes: ";
                            cin >> size;
                            cout << "Maximum edge weight: ";
                            cin >> maxWeight;
                            cout << "Starting vertex: ";
                            cin >> startingEdge;
                            cout << "Density: ";
                            cin >> density;
                            cout << "Attempts: ";
                            cin >> input;
                            for (int i = 0; i < input; i++) {
                                matrix = new AdjacencyMatrix(size, true, true, density, maxWeight);
                                auto start = steady_clock::now();
                                // todo: plug algorithm in
                                auto end = steady_clock::now();
                                time = double(duration_cast<nanoseconds>(end - start).count());
                                save(time, "bellman-ford_matrix.txt");
                            }
                        }
                            break;
                        case 6: {
                            cout << "[6] Bellman-Ford Algorithm | list" << endl;
                            cout << "Vertexes: ";
                            cin >> size;
                            cout << "Maximum edge weight: ";
                            cin >> maxWeight;
                            cout << "Starting vertex: ";
                            cin >> startingEdge;
                            cout << "Density: ";
                            cin >> density;
                            cout << "Attempts: ";
                            cin >> input;
                            for (int i = 0; i < input; i++) {
                                matrix = new AdjacencyMatrix(size, true, true, density, maxWeight);
                                list = new AdjacencyList(matrix);
                                auto start = steady_clock::now();
                                //todo:plug algorithm in here
                                auto end = steady_clock::now();
                                time = double(duration_cast<nanoseconds>(end - start).count());
                                save(time, "bellman-ford_list.txt");
                            }

                        }
                            break;
                        case 7: {
                            cout << "[7] Kruskal  Algorithm      | matrix" << endl;

                        }
                            break;
                        case 8: {
                            cout << "[8] Kruskal Algorithm       | list" << endl;
                        }
                            break;
                        default: {
                            cout << "Incorrect choice! Try again." << endl;
                        }
                            break;

                    }
                }
                delete matrix;
                delete list;
            }
                break;
            default: {
                cout << "Incorrect choice! Try again." << endl;
            }
                break;
        }
        mode = true;
    }
    return 0;
}
