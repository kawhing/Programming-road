//
// Created by kawhing on 26 ╬етб 2025.
//
#pragma once
#include <iostream>
#include <string>
using namespace std;
#ifndef SPEECHMANAGER_SPEAKER_H
#define SPEECHMANAGER_SPEAKER_H


class Speaker {
public:
    Speaker();

    ~Speaker();
    string name;
    double score[2];
};


#endif //SPEECHMANAGER_SPEAKER_H
