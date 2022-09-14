#include "ofApp.h"
#define DEBUG 1

//--------------------------------------------------------------
void ofApp::setup(){
    interaction.setup();
    shader.load("shaders_gl3/masking");
    imloader.setup(ofVec2f(ofGetWidth(), ofGetHeight()));

    fbos = imloader.getFBOs();
    nImages = fbos.size();

//    imloader.packFBOsForCircularBuffer();
//    nImages = imloader.sampsInCircularBuffer;
    cout << "nImgaes: " << nImages << endl;

    textNormalFBO.allocate(ofGetWidth(), ofGetHeight());
    maskNormalFBO.allocate(ofGetWidth(), ofGetHeight());
}
//--------------------------------------------------------------
void ofApp::update(){
    interaction.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushStyle();
    ofSetColor(ofColor::wheat);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPopStyle();

    maskNormalFBO.begin();
    interaction.sumDiff.draw(0, 0, maskNormalFBO.getWidth(), maskNormalFBO.getHeight());
    maskNormalFBO.end();

    float nTex = 1. / nImages;

    for(int i = 0; i < nImages; i ++){
//        textNormalFBO.begin();
//        textNormalFBO.end();

        shader.begin();
        shader.setUniformTexture("maskTex", maskNormalFBO.getTexture(), 1);
        shader.setUniform1f("nTex", float(nTex * (i + 1)));
        fbos[i].draw(0, 0);
//        imloader.getCircularBufferTexture(0).draw(0, 0);
//        textNormalFBO.draw(0, 0);
        shader.end();
    }

    if(DEBUG){
        maskNormalFBO.draw(0, 0, ofGetWidth()/4, ofGetHeight()/4);
        ofPushStyle();
        ofSetColor(ofColor::green);
        ofDrawBitmapString(ofToString(ofGetFrameRate()),0, 10, 1);
        ofPopStyle();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
