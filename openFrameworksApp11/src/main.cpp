#include "ofMain.h"
#include "ofApp.h"
//int main1(std::string* mystring);
int main1(std::vector<std::string>* mystring_vec);
//========================================================================
int main( ){
	//printf("HUHU");
	ofApp* theapp = new ofApp();

    std:string mystr = "HUHU";
	//std::thread t1(main1,&theapp->mystr);
	std::thread t1(main1,&theapp->mystr_vec);
	t1.detach();
	
	
	//ofSetupOpenGL(1024,768, OF_FULLSCREEN);			// <-------- setup the GL context
	//ofSetupOpenGL(640,400, OF_WINDOW);			// <-------- setup the GL context
	ofSetupOpenGL(800,600, OF_WINDOW);			// <-------- setup the GL context
	
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	theapp->mystr_vec.resize(10, "");
	//ofApp* theapp = new ofApp();
	ofRunApp(theapp);
	//ofRunApp(new ofApp());

}

void tocon() {
	printf("HOHUO");

}
