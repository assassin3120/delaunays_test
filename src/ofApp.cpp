#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    video.loadMovie("train.mov");
    video.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    
    flow.calcOpticalFlow(video.getPixelsRef());
    
    pts.clear();
    pts = flow.getFeatures();
    
    delaunay.reset();
    if (pts.size() > 15) {
        for (int i = 0; i < pts.size(); i+=5) {
            delaunay.addPoint(ofPoint(pts[i]));
        }
        delaunay.triangulate();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    video.draw(0,0);
    ofNoFill();
    delaunay.draw();
    ofNoFill();
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
