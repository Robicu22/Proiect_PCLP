//
// Created by robicu on 3/28/25.
//

#include "QualityTools.h"


bool QualityTools::isStringAnInt(string s) {

    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i]))
            return false;
    }

    return true;
}
