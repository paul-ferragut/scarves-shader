#pragma once

#include "ofMain.h"
//#include "ofxControlPanel.h"
#include "ofxXmlSettings.h"
#include "ofxGui.h"


#define widthScarf 5140//2580
#define heightScarf 5140//2580



#define widthPreview 1024
#define heightPreview 768

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();
		void takeStill();

		void keyPressed  (int key);
		void keyReleased (int key);

		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofTrueTypeFont font;
		ofShader shader;
		bool doShader;

//		ofxControlPanel gui;
ofxPanel gui;
ofxFloatSlider red[2];
ofxFloatSlider green[2];
ofxFloatSlider blue[2];


		//float red[2];
	//	float green[2];
	//	float blue[2];

		ofxFloatSlider timeMotion;
		ofxFloatSlider fluidity[2];
		ofxIntSlider fluidityI;

ofxFloatSlider colorBlendingGradientX;
ofxFloatSlider colorBlendingGradientY;

ofxFloatSlider addBlurSurface1;
ofxFloatSlider addBlurSurface2;

ofxFloatSlider addInnerSurface1;
ofxFloatSlider addInnerSurface2;

ofxFloatSlider moveContrast;
ofxFloatSlider fillThreshold;

int width;
int height;

ofxIntSlider scale;


int name;
bool takingStill;


};

