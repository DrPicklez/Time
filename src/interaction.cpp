#include "interaction.h"

Interaction::Interaction()
{

}

void Interaction::setup(){
    kinect.init(false, false); //rid RGB for faster depth

    //Cv Setup
    grayImage.allocate(kinect.width, kinect.height);
    grayThreshNear.allocate(kinect.width, kinect.height);
    grayThreshFar.allocate(kinect.width, kinect.height);
    sumDiff.allocate(kinect.width, kinect.height);
    nearThreshold = 250;
    farThreshold = 150;
    ofSetFrameRate(60);
    angle = 0;
    kinect.setCameraTiltAngle(90);
    kinect.open();
}

void Interaction::update(){

    kinect.update();
    if(kinect.isFrameNew()) {
        grayImage.setFromPixels(kinect.getDepthPixels());

        // we do two thresholds - one for the far plane and one for the near plane
        // we then do a cvAnd to get the pixels which are a union of the two thresholds
        grayThreshNear = grayImage;
        grayThreshFar = grayImage;
        grayThreshNear.threshold(nearThreshold, true);
        grayThreshFar.threshold(farThreshold);
        cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
        grayImage.flagImageChanged();
        grayImage.blurGaussian(3);


        grayImage.convertToRange(0, 3);
        sumDiff += grayImage;
        grayImage.convertToRange(1, 0);
        sumDiff -= grayImage;
    }
}

ofTexture Interaction::getKinect(){
    return grayImage.getTexture();
}
