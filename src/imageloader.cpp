#include "imageloader.h"
void ImageLoader::setup(ofVec2f _widHig){
    widHig = _widHig;
}

ofTexture ImageLoader::getTexture(){
    ofImage im;
    im.load("css_sprites.png");
    return  im.getTexture();
}
vector<ofTexture> ImageLoader::getTextures(){
    vector<ofTexture>_mTex;
    for(int i = 0; i < 20; i ++){
        ofImage im;
        string path = string("time/" + ofToString(i+1) + ".jpg");
        im.load(path);
        _mTex.push_back(im.getTexture());
        //cout << path << endl;
    }
    return _mTex;
}

vector<ofFbo> ImageLoader::getFBOs(){
    vector<ofFbo>_mTex;
    ofFbo fbo;
    ofImage im;
    for(int i = 0; i < 20; i ++){
        string path = string("time/" + ofToString(i+1) + ".jpg");
        im.load(path);
        fbo.allocate(widHig.x, widHig.y, GL_RGBA);

        fbo.begin();
//        ofClear(255,255,255, 0);
        im.draw(0, 0, fbo.getWidth(), fbo.getHeight());
        fbo.end();
        _mTex.push_back(fbo);
        cout << path << widHig.x << widHig.y << endl;
    }
    return _mTex;
}
