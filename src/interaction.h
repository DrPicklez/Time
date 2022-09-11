#ifndef INTERACTION_H
#define INTERACTION_H
#include "ofxKinect.h"
#include "ofxOpenCv.h"

class Interaction
{
public:
    Interaction();
    void setup();
    void update();
    ofTexture getKinect();

    ofxKinect kinect;

    ofxCvColorImage colorImg;
    ofxCvGrayscaleImage grayImage, sumDiff;
    ofxCvGrayscaleImage grayThreshNear;
    ofxCvGrayscaleImage grayThreshFar;
    ofxCvContourFinder contourFinder;


    ofTexture mTex;

    int nearThreshold;
    int farThreshold;
    bool bThreshWithOpenCV;
    int angle;

};

#endif // INTERACTION_H
