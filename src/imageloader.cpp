#include "imageloader.h"
void ImageLoader::setup(ofVec2f _widHig){
    widHig = _widHig;
}

ofTexture ImageLoader::getSingleTexture(){
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
    for(int i = 0; i < 5; i ++){
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


ofFbo ImageLoader::getFBO(){
    ofFbo fbo;
    ofFbo _fbo;
    ofImage im;
    for(int i = 0; i < 20; i ++){
        string path = string("time/" + ofToString(i+1) + ".jpg");
        im.load(path);
        fbo.allocate(widHig.x, widHig.y, GL_RGBA);
        fbo.begin();
//        ofClear(255,255,255, 0);
        im.draw(0, 0, fbo.getWidth(), fbo.getHeight());
        fbo.end();
        _fbo.attachTexture(fbo.getTexture(), GL_RGBA, i);
        cout << path << widHig.x << widHig.y << endl;
    }
    return _fbo;
}


void ImageLoader::packFBOsForCircularBuffer(){

    vector<ofFbo>fbosToPack = getFBOs();
    sampsInCircularBuffer = fbosToPack.size();
    if(ofFbo::checkGLSupport()){
        int nSamps = ofFbo::maxColorAttachments();

        ofFbo _fbo;
        _fbo.allocate(fbosToPack[0].getWidth(), fbosToPack[0].getWidth(), GL_RGBA, nSamps);
        cout << "maxSamples: " << nSamps << endl;

        int _iter = 0;
        for(int i = 0; i < fbosToPack.size(); i ++){
            ofTexture tex = fbosToPack[i].getTextureReference();
            _fbo.attachTexture(tex, GL_RGBA, _iter);
            cout << "attached" << endl;
            _iter ++;
            if(_iter == nSamps || (_iter == fbosToPack.size())){
                fboCircularBuffer.push_back(_fbo);

                cout << "Num Textures: "<< _fbo.getNumTextures() << endl;
                _fbo.clear();
                _iter = 0;
            }
        }
    }
}


ofTexture ImageLoader::getCircularBufferTexture(int n){
//    return fboCircularBuffer[0].getTexture((n + 1)%sampsInCircularBuffer);
    return fboCircularBuffer[0].getTexture(n);
}
