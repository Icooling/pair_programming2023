//
// Created by DELL on 2023/3/7.
//

#include "Solver.h"
#include "Algorithm.h"
#include "NoCycle.h"
#include "Cycle.h"
#include "../error/Error.h"
#include <cstring>
#include <queue>

void Solver::newWord(char *word) {
    Word wordObj(word);
    this->graph.addNode(wordObj);
}

// ���������������ж�ͼ���Ƿ��л�
static bool hasCycle(Graph &graph) {
    int n = graph.getSize();

    // 1. ��ø�������
    int in[n + 5];
    memset(in, 0, sizeof(in));
    for (int i = 0; i < n; i++) {
        vector<int> now = graph.getEdges().at(i);
        for (int &v: now) {
            in[v]++;
        }
    }

    // 2. ����ʼ���Ϊ0�ĵ����
    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
            cnt++;
        }
    }

    // 3. ���ϼ���ͼ�еĵ�
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int v: graph.getEdges().at(now)) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
                cnt++;
            }
        }
    }

    return cnt != n;
}

void Solver::solve() {
    Algorithm *algorithm;
    if (!hasCycle(this->graph)) {
        // �޻�ͼ
        algorithm = new NoCycle(this->graph, this->parameter);
    } else {
        if (!this->parameter.isR()) {
            Error::dataCyclicWithoutR();
        }
        algorithm = new Cycle(this->graph, this->parameter);
    }

    if (this->parameter.isN()) {
        algorithm->allWordlist();
    } else if (this->parameter.isW()) {
        algorithm->longestWords();
    } else if (this->parameter.isC()) {
        algorithm->longestAlphas();
    }

    delete algorithm;
}

Solver::Solver(Parameter &parameter) : parameter(parameter) {}
