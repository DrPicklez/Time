#include "imageloader.h"


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
