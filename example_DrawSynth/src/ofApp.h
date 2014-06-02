#pragma once

#include "ofMain.h"
#include "ofxStk.h"
#include "DrawSynth.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    void audioOut(float *output, int bufferSize, int nChannels);
    
    // checks if any keys are being held down;
    bool noNotesDown()const;
    
    // prevents the user from drawing illegal waves
    void cutWaveToPoint(ofPoint cutPoint);
    
    // creates 44100 frames of audio from the wave drawing
    stk::StkFrames getFramesFromWave();
    
    // takes the yValue inside the drawing region and converts it to
    // range -1 to 1, where -1 is rext bottom and 1 is rect top
    float transformYValue(float yValue)const ;
    
    ofPolyline wave;
    ofRectangle drawRegion;
    
    DrawSynth drawSynth;
    
    bool drawingBegan;
    bool keyDown;
    
    ofxPanel gui;
    ofxFloatSlider attack;
    ofxFloatSlider decay;
    ofxFloatSlider sustain;
    ofxFloatSlider release;
    ofxFloatSlider gain;
    
    ofTrueTypeFont instructions;
    
    bool aDown;
    bool sDown;
    bool dDown;
    bool fDown;
    bool gDown;
    bool hDown;
    bool jDown;
    bool kDown;
    bool lDown;
};