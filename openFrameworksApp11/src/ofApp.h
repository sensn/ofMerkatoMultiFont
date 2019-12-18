#pragma once

#include "ofMain.h"
#include "boid.h"
#include "Mouser.h"

class ofApp : public ofBaseApp{
	
	//Added by me(AG)
	ofTrueTypeFont font1;
	ofTrueTypeFont font2;
	ofTrueTypeFont font3;

	//

	// One Boid (a Seeker) and a Mouser.
	Boid theBoid;
	Mouser theMouse;

	public:
		void setup();
		void update();
		void draw();
		std::string mystr = "H";
		std::vector <std::string> mystr_vec;
		int i = 0;
		
		std::mutex vec_mutex;
};
