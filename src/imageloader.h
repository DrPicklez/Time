#ifndef IMAGELOADER_H
#define IMAGELOADER_H
#include "ofMain.h"

class ImageLoader
{
public:
    void setup(ofVec2f _widHig);
    ofTexture getSingleTexture();
    vector<ofTexture> getTextures();
    vector<ofFbo> getFBOs();
    void packFBOsForCircularBuffer();
    vector<ofFbo> fboCircularBuffer;
    ofTexture getCircularBufferTexture(int n);
    ofFbo getFBO();
    int sampsInCircularBuffer = 0;
    int nSamps =0;
    ofVec2f widHig;

};

#endif // IMAGELOADER_H
