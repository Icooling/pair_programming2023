//
// Created by DELL on 2023/3/7.
//

#ifndef WORDLIST_SOLVER_H
#define WORDLIST_SOLVER_H

#include <vector>
#include "../var/Word.h"
#include "../var/Graph.h"
#include "../var/Parameter.h"

using namespace std;
class Solver {
private:
    Parameter &parameter;
    Graph graph;

public:
    explicit Solver(Parameter &parameter);

    void solve();
    void newWord(char *word);
};


#endif //WORDLIST_SOLVER_H
