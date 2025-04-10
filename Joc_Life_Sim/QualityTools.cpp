//
// Created by robicu on 3/28/25.
//
#include "QualityTools.h"

#include <random>
#include <iostream>
#include <bits/stdc++.h>



bool QualityTools::isStringAnInt(string s) {

    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i]))
            return false;
    }

    return true;
}

string QualityTools::curse(string s, int n) {

    int ranIndex, ranCurse;

    for (int i = 0; i < n; i++) {
        ranIndex = rand()%(s.size()-1);
        ranCurse = rand()%(QualityTools::curses.size()-1);

        s[ranIndex] = QualityTools::curses[ranCurse];
    }

    return s;
}

