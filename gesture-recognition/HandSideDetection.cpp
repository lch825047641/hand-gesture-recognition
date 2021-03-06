/* 
 * File:   HandSideDetection.cpp
 * Author: Alexis
 * 
 * Created on 12 décembre 2012, 17:53
 */

#include "HandSideDetection.h"

HandSide detectHandSide(Mat &rotatedHand, float epsilon) {
    Point2f palmCenter = estimatePalmCenter(rotatedHand, 15);
    Point2f handCenter = computeMassCenter(rotatedHand);
    float horizontalDifference = palmCenter.x - handCenter.x;
    float verticalDifference = palmCenter.y - handCenter.y;
    
    if (abs(horizontalDifference) < epsilon || abs(verticalDifference) < epsilon) {
        return UNDEFINED_SIDE;
    } else {
        if (horizontalDifference * verticalDifference < 0)
            return LEFT_HAND;
        else
            return RIGHT_HAND;
    }
}
