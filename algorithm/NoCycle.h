//
// Created by DELL on 2023/3/8.
//

#ifndef WORDLIST_NOCYCLE_H
#define WORDLIST_NOCYCLE_H


#include "Algorithm.h"

class NoCycle : public Algorithm {
private:
    Graph *buildNewGraph();

    // 0��ʾ��������࣬1��ʾ��ĸ�����
    void longestPath(int type);

public:
    explicit NoCycle(Graph &graph, Parameter &parameter) : Algorithm(graph, parameter) {

    }

    void allWordlist() override;

    vector<string> &longestWords() override;

    vector<string> &longestAlphas() override;
};


#endif //WORDLIST_NOCYCLE_H
