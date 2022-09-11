#ifndef IMAGELOADER_H
#define IMAGELOADER_H
#include "ofMain.h"

class ImageLoader
{
public:
    void setup(ofVec2f _widHig);
    ofTexture getTexture();
    vector<ofTexture> getTextures();
    vector<ofFbo> getFBOs();
    ofVec2f widHig;

};

#endif // IMAGELOADER_H
