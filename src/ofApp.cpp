#include "ofApp.h"
#define DEBUG 1

//--------------------------------------------------------------
void ofApp::setup(){
    interaction.setup();
    textures = imloader.getTextures();
    shader.load("shaders_gl3/masking");
    texture = imloader.getTexture();
    textNormalFBO.allocate(ofGetWidth(), ofGetHeight());
    maskNormalFBO.allocate(ofGetWidth(), ofGetHeight());
    //ofDisableArbTex();



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

    float nTex = 1. / textures.size();

    for(int i = 0; i < textures.size(); i ++){
//    for(int i = textures.size() -1; i >= 0; i --){

        textNormalFBO.begin();
        textures[i].draw(0, 0, textNormalFBO.getWidth(), textNormalFBO.getHeight());
        textNormalFBO.end();
        cout << float(nTex * (i + 1)) << endl;
        shader.begin();
        shader.setUniformTexture("maskTex", maskNormalFBO.getTextureReference(), 1);
        shader.setUniform1f("nTex", float(nTex * (i + 1)));
        textNormalFBO.draw(0, 0);
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
