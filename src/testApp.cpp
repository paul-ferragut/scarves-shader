#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
width=widthPreview;
height=heightPreview;
name=0;
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofBackground(34, 34, 34);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();

	gui.loadFromFile("settings.xml");

	//we load a font and tell OF to make outlines so we can draw it as GL shapes rather than textures
	font.loadFont("type/verdana.ttf", 100, true, false, true, 0.4, 72);
	shader.load("shaders/noise.vert", "shaders/noise.frag");
	doShader = true;

	//gui.setup("control",0,0,250,1000,false);
	//gui.addPanel("color",1,false);
	//gui.setWhichPanel(0);


	for(int i=0;i<2;i++){
    //gui.addLabel("color"+ofToString(i+1));
	//gui.addSlider("red"+ofToString(i+1),"RED"+ofToString(i+1),0,-2,2,false);
	//gui.addSlider("green"+ofToString(i+1),"GREEN"+ofToString(i+1),0,-2,2,false);
	//gui.addSlider("blue"+ofToString(i+1),"BLUE"+ofToString(i+1),0,-2,2,false);
    gui.add(red[i].setup("red"+ofToString(i+1),0,-2,2));
    gui.add(green[i].setup("green"+ofToString(i+1),0,-2,2));
    gui.add(blue[i].setup("blue"+ofToString(i+1),0,-2,2));

	}
    gui.add(scale.setup("scale x",width,0,12000));

     //gui.add(red[i].setup("scale",width,0,12000);
     //gui.add(red[i].setup("scale y",width,0,12000);
	//gui.addSlider("scale y","sy",height,0,12000,false);

	gui.add(colorBlendingGradientX.setup("colorBlendingGradientX",0,-2,2));
	gui.add(colorBlendingGradientY.setup("colorBlendingGradientY",0,-2,2));
	gui.add(addBlurSurface1.setup("addBlurSurface1",0,-10,10));
	gui.add(addBlurSurface2.setup("addBlurSurface2",0,-10,10));
    gui.add(addInnerSurface1.setup("addInnerSurface1",0,-10,10));
	gui.add(addInnerSurface2.setup("addInnerSurface2",0,-10,10));

	gui.add(moveContrast.setup("move contrast",0,-10,10));
	gui.add(fillThreshold.setup("fillThreshold",0,-10,10));

	gui.add(timeMotion.setup("time",0.001f,0.00001f,0.01f));
	gui.add(fluidity[0].setup("fluidity1",2.3f,0.001f,5));
	gui.add(fluidity[1].setup("fluidity2",0.4f,0.001f,1));
	gui.add(fluidity[2].setup("fluidity3",10,1,40));


}

//--------------------------------------------------------------
void testApp::update(){

/*
    	for(int i=0;i<2;i++){

    red[i]=gui.getValueF("RED"+ofToString(i+1));
    green[i]=gui.getValueF("GREEN"+ofToString(i+1));
    blue[i]=gui.getValueF("BLUE"+ofToString(i+1));

    	}

    timeMotion=gui.getValueF("TIME");
    fluidity[0]=gui.getValueF("FLUIDITY1");
    fluidity[1]=gui.getValueF("FLUIDITY2");
    fluidityI=gui.getValueI("FLUIDITY3");


    colorBlendingGradientX=gui.getValueF("cBGX");
colorBlendingGradientY=gui.getValueF("cBGY");
addBlurSurface1=gui.getValueF("aBS1");
addBlurSurface2=gui.getValueF("aBS2");
addInnerSurface1=gui.getValueF("aIS1");
addInnerSurface2=gui.getValueF("aIS2");
moveContrast=gui.getValueF("mC");
fillThreshold=gui.getValueF("fT");
*/
//sWidth=gui.getValueI("sx");
//sHeight=gui.getValueI("sy");
}

//--------------------------------------------------------------
void testApp::draw(){

	//ofBackground(red[0], green[0], blue[0]);

shader.begin();
shader.setUniform1f("time", ofGetFrameNum() * timeMotion);
shader.setUniform1f("fluidity1",fluidity[0]);
shader.setUniform1f("fluidity2",fluidity[1]);
shader.setUniform1i("fluidity3",fluidity[2]);


shader.setUniform1f("colorBlendingGradientX",colorBlendingGradientX);
shader.setUniform1f("colorBlendingGradientY",colorBlendingGradientY);
shader.setUniform1f("addBlurSurface1",addBlurSurface1);
shader.setUniform1f("addBlurSurface2",addBlurSurface2);
shader.setUniform1f("addInnerSurface1",addInnerSurface1);
shader.setUniform1f("addInnerSurface2",addInnerSurface2);
shader.setUniform1f("moveContrast",moveContrast);
shader.setUniform1f("fillThreshold",fillThreshold);
shader.setUniform1f("red",red[0]);
shader.setUniform1f("green",green[0]);
shader.setUniform1f("blue",blue[0]);

shader.setUniform1f("scaleWidth",scale);
shader.setUniform1f("scaleHeight",scale);
//ofSetColor(red[1], green[1], blue[1]);
ofRect(0,0,width,height);
shader.end();
if(takingStill==false){
ofSetColor(255,255,255);
gui.draw();
takingStill=false;
}

}
void testApp::takeStill(){
    cout<<"take still1"<<endl;
takingStill=true;
ofDirectory DIR;
cout<<"take still2"<<endl;
//DIR.listDir("/");
cout<<"take still2"<<endl;
//name=DIR.numFiles();
name++;
ofSetWindowShape(widthScarf,heightScarf);
width=widthScarf;
height=heightScarf;
cout<<ofGetWidth()<<"  width:"<<width<<endl;
draw();
string fileName;
fileName = "screen"+ofToString(name)+".png";
ofSaveScreen(fileName);
width=widthPreview;
height=heightPreview;
takingStill=false;
cout<<"name"<<name<<endl;
//name++;
//ofSetWindowShape(1024,768);
}
//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	if( key == 's' ){
		doShader = !doShader;
	}

		if( key == ' ' ){
		takeStill();
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}
//--------------------------------------------------------------
void testApp::exit(){
		gui.saveToFile("settings.xml");
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}

