// ------------------------------------------------------------------
// ofxTPSprite.cpp
// ofxTexturePacker - https://www.github.com/danoli3/ofxTexturePacker
// Created by Daniel Rosser and Colin Friend on 9/06/2014.
// ------------------------------------------------------------------
#include "ofxTPSprite.h"

ofxTPSprite::ofxTPSprite(ofxTPSpriteDataPtr theData) :
    data(theData)
{
}

float ofxTPSprite::getWidth(){
    return data->getW();
}

void ofxTPSprite::draw(int x, int y) {
    if(data->isRotated()) {
        ofPushMatrix();
            ofTranslate(x, y); // translate Draw position
            x = y = 0;
            ofPushMatrix();
        
//            if(data->isDebugMode()){
//                ofPushStyle();      //----------- Draw original unrotated texture
//                ofSetColor(255, 0, 0, 128);
//                ofNoFill();
//                ofRect(x+data->getOffsetY(), y+data->getOffsetX(), data->getOffsetHeight(), data->getOffsetWidth());
//                if(texture != NULL) {
//                   texture->drawSubsection(x+data->getOffsetY(), y+data->getOffsetX(), data->getW(), data->getH(), data->getX(), data->getY(), data->getW(), data->getH());
//                }
//                ofPopStyle();
//            }
            ofTranslate(data->getOffsetX(), data->getOffsetHeight()-data->getOffsetY());
            ofRotateDeg(-90);
            if(data->isDebugMode()){
                ofPushStyle();
                ofSetColor(0, 255, 0, 128);
                ofNoFill();
                ofDrawRectangle(x-data->getOffsetY(), y-data->getOffsetX(), data->getOffsetHeight(), data->getOffsetWidth());
                ofPopStyle();
            }
        
    } else {
        x += data->getOffsetX();
        y += data->getOffsetY();
    }
    
    if(data->isDebugMode()){
        if(!data->isRotated()){
            ofPushStyle();
            ofNoFill();
            ofDrawRectangle(x-data->getOffsetX(), y-data->getOffsetY(), data->getOffsetWidth(), data->getOffsetHeight());
            ofPopStyle();
        }
    }
    if(texture != NULL) {
        ofPushMatrix();
        //ofLog() << data->getPX() << " " << data->getW();
        ofTranslate(-data->getPX() * data->getW(), -data->getPY() * data->getH());
        texture->drawSubsection(x, y, data->getW(), data->getH(), data->getX(), data->getY(), data->getW(), data->getH());
        ofPopMatrix();
    }
    
    if(data->isRotated()) {
            ofPopMatrix();
         ofPopStyle();
         ofPopMatrix();
    }
}
