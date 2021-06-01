#include <iostream>
#include <fstream>
#include "Main.h"
#include "adjency_matrix/AdjacencyMatrix.h"

int input;              // choice of menu option
bool running = true;    //controls the main loop of the program
bool mode = true;       //controls loop of specified mode
bool algorithm = true;  //controls loop of given structure while working in specified mode
using namespace std;

//todo: remove this function from AdjacencyMatrix.cpp and AdjacencyList.cpp and required includes in these files
//todo: uncomment this function
//int *interpret(string line, const string &delimiter, int number) {
//    int *tmp = new int[number], i = 0;
//    size_t position;
//    string token;
//    while ((position = line.find(delimiter)) != string::npos) {
//        token = line.substr(0, position);
//        tmp[i++] = atoi(token.c_str());
//        line.erase(0, position + delimiter.length());
//    }
//    tmp[i] = atoi(line.c_str());
//    return tmp;
//}

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
                while (mode) {
                    AdjacencyMatrix *matrix;
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
                            fstream file;       // handle for .txt file
                            string filepath;    // path to the file, where graph parameters are stored
                            cout << "WARNING! FILE MUST BE IN THE SAME FOLDER AS EXECUTABLE FILE." << endl;
                            cout << "NAME OF THE FILE SHOULD BE ENTERED LIKE THIS: name.extension" << endl;
                            cout << "Name of the file: ";
                            cin >> filepath;
                            if (file.good()) {
                                matrix=new AdjacencyMatrix(filepath," ");
                                matrix->show();
                                //todo: reading and generating list
                            } else {
                                cout << "Error! Name of the file incorrect or file does not exist. Try again." << endl;
                            }
                        }
                            break;
                        default: {
                            cout << "Incorrect choice! Try again." << endl;
                        }
                            break;
                    }
                    while (algorithm) {
                        cout << "--------------------------------Control mode--------------------------------" << endl;
                        cout << "[0] Return to menu" << endl;
                        cout << "[1] Prim Algorithm | matrix" << endl;
                        cout << "[2] Prim Algorithm | list" << endl;
                        cout << "[3] Dijkstra Algorithm | matrix" << endl;
                        cout << "[4] Dijkstra Algorithm | list" << endl;
                        cout << "[5] Bellman-Ford Algorithm | matrix" << endl;
                        cout << "[6] Bellman-Ford Algorithm | list" << endl;
                        cout << "[7] Kruskal  Algorithm | matrix" << endl;
                        cout << "[8] Kruskal Algorithm | list" << endl;
                        cout << "> ";
                        cin >> input;
                        switch (input) {
                            case 0: {
                                algorithm = false;
                            }
                                break;
                            case 1: {
                                cout << "[1] Prim Algorithm | matrix" << endl;


                            }
                                break;
                            case 2: {
                                cout << "[2] Prim Algorithm | list" << endl;

                            }
                                break;
                            case 3: {
                                cout << "[3] Dijkstra Algorithm | matrix" << endl;


                            }
                                break;
                            case 4: {
                                cout << "[4] Dijkstra Algorithm | list" << endl;

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
                                cout << "[7] Kruskal  Algorithm | matrix" << endl;
                            }
                                break;
                            case 8: {
                                cout << "[8] Kruskal Algorithm | list" << endl;
                            }
                                break;
                            default: {
                                cout << "Incorrect choice! Try again." << endl;
                            }
                                break;

                        }
                    }
//                   todo: delete matrix;
                }

            }
                break;
            case 2: {
                while (mode) {
                    cout << "--------------------------------Metrological mode--------------------------------" << endl;
                    cout << "[0] Return to menu" << endl;
                    cout << "[1] Prim Algorithm | matrix" << endl;
                    cout << "[2] Prim Algorithm | list" << endl;
                    cout << "[3] Dijkstra Algorithm | matrix" << endl;
                    cout << "[4] Dijkstra Algorithm | list" << endl;
                    cout << "[5] Bellman-Ford Algorithm | matrix" << endl;
                    cout << "[6] Bellman-Ford Algorithm | list" << endl;
                    cout << "[7] Kruskal  Algorithm | matrix" << endl;
                    cout << "[8] Kruskal Algorithm | list" << endl;
                    cout << "> ";
                    cin >> input;
                    switch (input) {
                        case 0: {
                            mode = false;
                        }
                            break;
                        case 1: {
                            cout << "[1] Prim Algorithm | matrix" << endl;
                        }
                            break;
                        case 2: {
                            cout << "[2] Prim Algorithm | list" << endl;
                        }
                            break;
                        case 3: {
                            cout << "[3] Dijkstra Algorithm | matrix" << endl;
                        }
                            break;
                        case 4: {
                            cout << "[4] Dijkstra Algorithm | list" << endl;
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
                            cout << "[7] Kruskal  Algorithm | matrix" << endl;

                        }
                            break;
                        case 8: {
                            cout << "[8] Kruskal Algorithm | list" << endl;
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
