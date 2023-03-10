//
// Created by DELL on 2023/3/8.
//

#include "Cycle.h"
#include "../tools/JudgeChar.h"
#include "../var/Information.h"

#include <iostream>
#include <cstring>

using namespace std;

void Cycle::allWordlist() {
    cout << "数据可构成环，无法求解单词链数量" << endl;
}

static void splitByBlank(const string &str, vector<string> &split) {
    int i = 0;
    for (int j = 1; j < str.length(); j++) {
        if (str.at(j) == ' ') {
            split.push_back(str.substr(i, j - i));
            i = j + 1;
            j++;
        }
    }
    if (i < str.length()) {
        split.push_back(str.substr(i, str.length() - i));
    }
}

static int weightByWords(const string &path) {
    vector<string> split;
    splitByBlank(path, split);
    return (int) split.size();
}

static int weightByAlphas(const string &path) {
    vector<string> split;
    splitByBlank(path, split);
    return (int) path.length() - (int) split.size() + 1;
}


string dfs(Graph &graph, Parameter &parameter, int now, bool vis[],
           const string &nowPath, string &longestPath, int getWeight(const string &path)) {
    for (int next: graph.getEdges().at(now)) {
        if (vis[next]) {
            continue;
        }
        Word nextWord = graph.getNode(next);
        string newStr = nowPath + " " + nextWord.getWord();
        if (lastOk(parameter, nextWord.getLast())) {
            if (getWeight(nowPath) > getWeight(longestPath)) {
                longestPath = newStr;
            }
        }
        vis[next] = true;
        dfs(graph, parameter, next, vis, newStr, longestPath, getWeight);
        vis[next] = false;
    }
    return longestPath;
}

static void printPath(const string &path) {
    vector<string> split;
    splitByBlank(path, split);
    for (string &str: split) {
        cout << str << endl;
    }
}

void Cycle::longestPath(int getWeight(const string &path)) {
    int size = this->graph.getSize();
    string ans;
    bool vis[size + 5];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < size; i++) {
        if (firstOk(this->parameter, this->graph.getNode(i).getFirst())) {
            vis[i] = true;
            string startFromNowPath = dfs(graph, parameter, i, vis,
                                          graph.getNode(i).getWord(), ans, getWeight);
            vis[i] = false;
            if (getWeight(ans) > getWeight(startFromNowPath)) {
                ans = startFromNowPath;
            }
        }
    }

    if (ans.empty()) {
        cout << NO_SATISFYING_WL << endl;
    } else {
        printPath(ans);
    }
}

vector<string> &Cycle::longestWords() {
    longestPath(weightByWords);
}

vector<string> &Cycle::longestAlphas() {
    longestPath(weightByAlphas);
}


