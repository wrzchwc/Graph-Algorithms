#include <iostream>
#include <random>
#include <chrono>
#include "Main.h"
#include "adjacency_matrix/AdjacencyMatrix.h"
#include "adjacency_list/AdjacencyList.h"
#include "dijkstra_algorithm/DijkstraAlgorithm.h"
#include "prim_algorithm/PrimAlgorithm.h"
#include "kruskal_algorithm/KruskalAlgorithm.h"

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

void directedGraphError() {
    cout << "Error! Mode unavailable because directed graph was generated. " << endl;
    cout << "Return to menu and generate undirected graph or load graph from file." << endl;
}

void undirectedGraphError() {
    cout << "Error! Mode unavailable because undirected graph was generated ";
    cout << "or graph with negative edges was generated. " << endl;
    cout << "Return to menu and generate directed graph or load graph from file." << endl;
}

int getInitialVertex() {
    int input;
    cout << "Start vertex: ";
    cin >> input;
    return input;
}

//parameters[0]-size
//parameters[1]-max weight
//parameters[2]-start
//parameters[3]-density
//parameters[4]-attempts
//parameters[5]-min weight
double *getParameters() {
    auto *parameters = new double[6];
    cout << "Vertexes: ";
    cin >> parameters[0];
    cout << "Maximum edge weight: ";
    cin >> parameters[1];
    cout << "Minimum edge weight: ";
    cin >> parameters[5];
    cout << "Starting vertex: ";
    cin >> parameters[2];
    cout << "Density: ";
    cin >> parameters[3];
    cout << "Attempts: ";
    cin >> parameters[4];
    return parameters;
}

//menu headlines 1-2:P, 2-3:D,4-5:BF,7-8:K
string headlines[9] = {"[0] Return to menu",
                       "[1] Prim Algorithm         | matrix",
                       "[2] Prim Algorithm         | list",
                       "[3] Dijkstra Algorithm     | matrix",
                       "[4] Dijkstra Algorithm     | list",
                       "[5] Bellman-Ford Algorithm | matrix",
                       "[6] Bellman-Ford Algorithm | list",
                       "[7] Kruskal  Algorithm     | matrix",
                       "[8] Kruskal Algorithm      | list"};
string filepaths[8] = {"prim_matrix.txt", "prim_list.txt", "dijkstra_matrix.txt", "dijkstra_list.txt",
                       "bellman-ford_matrix.txt", "bellman-ford_list.txt", "kruskal_matrix.txt", "kruskal_list.txt"
};

double densities[4] = {0.25, 0.5, 0.75, 0.99};

int sizes[5] = {30, 60, 90, 120, 150};

void printAlgorithms() {
    for (const string &headline:headlines)
        cout << headline << endl;
    cout << "> ";
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
                    int minWeight = 0;
                    cout << "[0] Return to menu" << endl;
                    cout << "[1] Generate graph" << endl;
                    cout << "[2] Load graph from the file" << endl;
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
                            auto accepted = false;
                            while (!accepted) {
                                cout << "Directed graph (1-yes, 0-no): ";
                                cin >> input;
                                cout << "Minimum weight of edge: ";
                                cin >> minWeight;
                                accepted = (input == 1) || (input == 0 && minWeight >= 0);
                            }
                            directed = input != 0;
                            KPUnavailable = input != 0;
                            matrix = new AdjacencyMatrix(size, directed, density, minWeight, maxWeight);
                            list = new AdjacencyList(matrix);
                            algorithm = true;
                            cout << "Graph generation successful." << endl;
                        }
                            break;
                        case 2: {
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
                        printAlgorithms();
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
                                    cout << headlines[input] << endl; //undirected
                                    PrimAlgorithm::solve(matrix,
                                                         load ? matrix->getInitialVertex() : getInitialVertex());
                                } else
                                    directedGraphError();
                            }
                                break;
                            case 2: {
                                if (!KPUnavailable || load) {
                                    cout << headlines[input] << endl; //undirected
                                    PrimAlgorithm::solve(list, load ? list->getInitialVertex() : getInitialVertex());
                                } else
                                    directedGraphError();
                            }
                                break;
                            case 3: {
                                if ((KPUnavailable || load) && minWeight >= 0) {
                                    cout << headlines[input] << endl;
                                    DijkstraAlgorithm::solve(matrix,
                                                             load ? matrix->getInitialVertex() : getInitialVertex());
                                } else
                                    undirectedGraphError();
                            }
                                break;
                            case 4: {
                                if ((KPUnavailable || load) && minWeight >= 0) {
                                    cout << headlines[input] << endl;
                                    DijkstraAlgorithm::solve(list,
                                                             load ? list->getInitialVertex() : getInitialVertex());
                                } else
                                    undirectedGraphError();
                            }
                                break;
                            case 5: {
                                if (KPUnavailable || load) {
                                    cout << headlines[input] << endl;
                                    auto initialVertex = load ? matrix->getInitialVertex() : getInitialVertex();
                                    auto response = BellmanFordAlgorithm::solve(matrix, initialVertex);
                                    if (response)
                                        cout << "There are not any negative cycles." << endl;
                                    else
                                        cout << "Error! There is at least one negative cycle in the graph" << endl;

                                } else
                                    undirectedGraphError();
                            }
                                break;
                            case 6: {
                                if (KPUnavailable || load) {
                                    cout << headlines[input] << endl;
                                    auto initialVertex = load ? list->getInitialVertex() : getInitialVertex();
                                    auto response = BellmanFordAlgorithm::solve(list, initialVertex);
                                    if (response)
                                        cout << "There are not any negative cycles." << endl;
                                    else
                                        cout << "Error! There is at least one negative cycle in the graph" << endl;
                                } else
                                    undirectedGraphError();
                            }
                                break;
                            case 7: {
                                if (!KPUnavailable || load) {
                                    cout << headlines[input] << endl;
                                    KruskalAlgorithm::solve(matrix);
                                } else
                                    directedGraphError();
                            }
                                break;
                            case 8: {
                                if (!KPUnavailable || load) {
                                    cout << headlines[input] << endl;
                                    KruskalAlgorithm::solve(list);
                                } else
                                    directedGraphError();
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
                    double time = 0.0;
                    cout << "--------------------------------Metrological mode--------------------------------" << endl;
                    printAlgorithms();
                    cin >> input;
                    switch (input) {
                        case 0: {
                            mode = false;
                        }
                            break;
                        case 1: {
                            cout << headlines[input] << endl;
                            for (int size:sizes) {
                                for (double density:densities) {
                                    for (int i = 0; i < 100; i++) {
                                        matrix = new AdjacencyMatrix(size, false, density, 1, 1000);
                                        auto start = steady_clock::now();
                                        PrimAlgorithm::solve(matrix, 0);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                        save(time, filepaths[input - 1]);
                                    }
                                }
                            }

                        }
                            break;
                        case 2: {
                            cout << headlines[input] << endl;
                            for (int size:sizes) {
                                for (double density : densities) {
                                    for (int k = 0; k < 100; k++) {
                                        matrix = new AdjacencyMatrix(size, false, density, 1, 1000);
                                        list = new AdjacencyList(matrix);
                                        auto start = steady_clock::now();
                                        PrimAlgorithm::solve(list, 0);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                        save(time, filepaths[input - 1]);
                                    }
                                }
                            }
                        }
                            break;
                        case 3: {
                            cout << headlines[input] << endl;
                            for (int size:sizes)
                                for (double density : densities)
                                    for (int i = 0; i < 100; i++) {
                                        matrix = new AdjacencyMatrix(size, true, density, 1, 1000);
                                        auto start = steady_clock::now();
                                        DijkstraAlgorithm::solve(matrix, 0);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                        save(time, filepaths[input - 1]);
                                    }
                        }
                            break;
                        case 4: {
                            cout << headlines[input] << endl;
                            for (int size:sizes)
                                for (double density : densities)
                                    for (int i = 0; i < 100; i++) {
                                        matrix = new AdjacencyMatrix(size, true, density, 1, 1000);
                                        list = new AdjacencyList(matrix);
                                        auto start = steady_clock::now();
                                        DijkstraAlgorithm::solve(list, 0);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                        save(time, filepaths[input - 1]);
                                    }
                        }
                            break;
                        case 5: {
                            cout << headlines[input] << endl;
                            for (int size:sizes)
                                for (double density : densities)
                                    for (int i = 0; i < 100;) {
                                        matrix = new AdjacencyMatrix(size, true, density, 1, 1000);
                                        auto start = steady_clock::now();
                                        auto tmp = BellmanFordAlgorithm::solve(matrix, 0);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                        if (tmp) {
                                            save(time, filepaths[input - 1]);
                                            i++;
                                        }
                                    }
                        }
                            break;
                        case 6: {
                            cout << headlines[input] << endl;
                            for (int size:sizes)
                                for (double density : densities)
                                    for (int i = 0; i < 100;) {
                                        matrix = new AdjacencyMatrix(size, true, density, 1, 1000);
                                        list = new AdjacencyList(matrix);
                                        auto start = steady_clock::now();
                                        auto tmp = BellmanFordAlgorithm::solve(list, 0);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                        if (tmp) {
                                            save(time, filepaths[input - 1]);
                                            i++;
                                        }
                                    }
                        }
                            break;
                        case 7: {
                            cout << headlines[input] << endl;
                            for (int size:sizes)
                                for (double density : densities)
                                    for (int i = 0; i < 100; i++) {
                                        matrix = new AdjacencyMatrix(size, false, density, 1, 1000);
                                        auto start = steady_clock::now();
                                        KruskalAlgorithm::solve(matrix);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                        save(time, filepaths[input - 1]);
                                    }
                        }
                            break;
                        case 8: {
                            cout << headlines[input] << endl;
                            for (int size:sizes)
                                for (double density : densities)
                                    for (int i = 0; i < 100; i++) {
                                        matrix = new AdjacencyMatrix(size, false, density, 1, 1000);
                                        list = new AdjacencyList(matrix);
                                        auto start = steady_clock::now();
                                        KruskalAlgorithm::solve(list);
                                        auto end = steady_clock::now();
                                        time = double(duration_cast<nanoseconds>(end - start).count());
                                        save(time, filepaths[input - 1]);
                                    }
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
