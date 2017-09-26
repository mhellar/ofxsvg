#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	
	ofBackground(255);
	ofSetColor(0);
	
	svg.load("mandala.svg");
	for (int i = 0; i < svg.getNumPath(); i++){
		ofPath p = svg.getPathAt(i);
		// svg defaults to non zero winding which doesn't look so good as contours
		p.setPolyWindingMode(OF_POLY_WINDING_ODD);
		vector<ofPolyline>& lines = const_cast<vector<ofPolyline>&>(p.getOutline());
		for(int j=0;j<(int)lines.size();j++){
			outlines.push_back(lines[j].getResampledBySpacing(1));
		}
	}
    svg2.load("mandala2.svg");
    for (int i = 0; i < svg2.getNumPath(); i++){
        ofPath p = svg2.getPathAt(i);
        // svg defaults to non zero winding which doesn't look so good as contours
        p.setPolyWindingMode(OF_POLY_WINDING_ODD);
        vector<ofPolyline>& lines = const_cast<vector<ofPolyline>&>(p.getOutline());
        for(int j=0;j<(int)lines.size();j++){
            outlines.push_back(lines[j].getResampledBySpacing(1));
        }
    }
}


//--------------------------------------------------------------
void ofApp::update(){
	step += 0.001;
	if (step > 1) {
		step -= 1;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBeginSaveScreenAsPDF("thename.pdf", true, true,   ofRectangle(0,0,ofGetWindowHeight()*0.7,ofGetWindowHeight()));

    ofScale(.2, .2, .2);
    for(int i =15;i<20;i++){
    ofTranslate(5 * 65,0);
    if((i % 2 ) == 0)
    {
    svg2.draw();
    }
    else{
    svg.draw();
    }
    }
    ofEndSaveScreenAsPDF();

    
//	ofDrawBitmapString(ofToString(ofGetFrameRate()),20,20);
//	ofPushMatrix();
//	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
//	ofRotate(mouseX);
//	float scale = ofMap(mouseY, 0, ofGetHeight(), .5, 10);
//	ofScale(scale, scale, scale);
//	ofTranslate(-250, -250);
//	if(ofGetMousePressed()) {
//		ofNoFill();
//		for (int i = 0; i < (int)outlines.size(); i++){
//			ofPolyline & line = outlines[i];
//
//			int num = step * line.size();
//
//			ofBeginShape();
//			for (int j = 0; j < num; j++){
//				ofVertex(line[j]);
//			}
//			ofEndShape();
//		}
//	} else {
//		svg.draw();
//	}
	
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a') {
        ofSetFrameRate(1);  // so it doesn't generate tons of pages
        ofBeginSaveScreenAsPDF("recording-"+ofGetTimestampString()+".pdf", true);
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	
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
