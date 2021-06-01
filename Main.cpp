#include <iostream>
#include "Main.h"
#include "adjacency_matrix/AdjacencyMatrix.h"
#include "adjacency_list/AdjacencyList.h"

int input;                  // choice of menu option
bool running = true;        //controls the main loop of the program
bool mode = true;           //controls loop of specified mode
bool algorithm = false;     //controls loop of given structure while working in specified mode
using namespace std;

//todo: remove this function from AdjacencyMatrix.cpp and AdjacencyList.cpp and required includes in these files
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

int main() {
    cout << "--------------------------------DS&CC Project--------------------------------" << endl;
    cout << "Jakub Wierzchowiec, 06.2021" << endl;
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
                auto *matrix = new AdjacencyMatrix(0);
                auto *list = new AdjacencyList();
                while (mode) {
                    // path to the file, where graph parameters are stored
                    string filepath, delimiter = " ";
                    bool load = false;
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
                            // todo: generating graph as matrix
                            // todo: generating graph as list
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
                                load = false;
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
                        cout << "[0] Return to menu         |" << endl;
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
                        if(!load){
                            if (input == 0)
                                algorithm = false;
                            else if (input == 1 || input == 2 || input == 7 || input == 8) {
                                list = new AdjacencyList(filepath, delimiter, false);
                                matrix = new AdjacencyMatrix(filepath, delimiter, false);
                            } else if (input == 3 || input == 4 || input == 5 || input == 6) {
                                list = new AdjacencyList(filepath, delimiter, true);
                                matrix = new AdjacencyMatrix(filepath, delimiter, true);
                            } else
                                cout << "Incorrect choice! Try again." << endl;
                            if (input > 0)
                                input % 2 == 1 ? matrix->show() : list->show();
                        }
                        else{

                        }

                        switch (input) {
                            case 0: {
                                algorithm = false;
                            }
                            case 1: {
                                cout << "[1] Prim Algorithm         | matrix" << endl; //undirected
                            }
                                break;
                            case 2: {
                                cout << "[2] Prim Algorithm         | list" << endl; //undirected
                            }
                                break;
                            case 3: {
                                cout << "[3] Dijkstra Algorithm     | matrix" << endl; //directed
                            }
                                break;
                            case 4: {
                                cout << "[4] Dijkstra Algorithm     | list" << endl; //directed
                            }
                                break;
                            case 5: {
                                cout << "[5] Bellman-Ford Algorithm | matrix" << endl; //directed
                            }
                                break;
                            case 6: {
                                cout << "[6] Bellman-Ford Algorithm | list" << endl; //directed
                            }
                                break;
                            case 7: {
                                cout << "[7] Kruskal  Algorithm | matrix" << endl; //undirected
                            }
                                break;
                            case 8: {
                                cout << "[8] Kruskal Algorithm | list" << endl; //undirected
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
                while (mode) {
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
                        }
                            break;
                        case 2: {
                            cout << "[2] Prim Algorithm         | list" << endl;
                        }
                            break;
                        case 3: {
                            cout << "[3] Dijkstra Algorithm     | matrix" << endl;
                        }
                            break;
                        case 4: {
                            cout << "[4] Dijkstra Algorithm     | list" << endl;
                        }
                            break;
                        case 5: {
                            cout << "[5] Bellman-Ford Algorithm | matrix" << endl;

                        }
                            break;
                        case 6: {
                            cout << "[6] Bellman-Ford Algorithm | list" << endl;

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
            }
                break;
            default: {
                cout << "Incorrect choice! Try again." << endl;
            }
        }
        mode = true;
    }
    return 0;
}
