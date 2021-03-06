#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	int radius_width = 6;
	int radius_param_span = 3;
	for (int radius_param = 500; radius_param < 3200; radius_param += radius_param_span) {

		float radius = radius_param * 0.1f;

		int deg_span = 1;
		int start_deg = ofRandom(360);
		start_deg += ofMap(ofNoise(ofRandom(360) * 0.005 + ofGetFrameNum() * 0.01), 0, 1, -30, 30);
		int end_deg = start_deg + ofRandom(30, 60);

		ofPoint point = ofPoint(radius * cos(((start_deg + end_deg) / 2) * DEG_TO_RAD), radius * sin(((start_deg + end_deg) / 2) * DEG_TO_RAD));
		if (point.y < -160) {

			ofSetColor(48, 169, 222, 139);
		}
		else if (point.y < 0) {

			ofSetColor(239, 220, 5, 139);
		}
		else if (point.y < 160) {

			ofSetColor(229, 58, 64, 139);
		}
		else {

			ofSetColor(9, 7, 7, 139);
		}

		vector<ofPoint> vertices;
		for (int deg = start_deg; deg <= end_deg; deg += deg_span) {

			vertices.push_back(ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
		}
		for (int deg = end_deg; deg >= start_deg; deg -= deg_span) {

			vertices.push_back(ofPoint((radius + radius_width) * cos(deg * DEG_TO_RAD), (radius + radius_width) * sin(deg * DEG_TO_RAD)));
		}

		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}