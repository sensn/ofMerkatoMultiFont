#include <iostream>

#include "ofApp.h"

void tocon();   //CALL CONSOLE 

//--SETUP------------------------------------------------------------
void ofApp::setup(){
	ofHideCursor();               // Hide the OS mouse pointer.
	ofBackground(ofColor::dodgerBlue); // Set a white background.

	// Setup the Boid. The Mouser is built in the header file.
	theBoid.setup(
		ofGetHeight() / 2,   // middle x position 
		ofGetWidth() / 2,    // middle y position
		ofColor::darkorange, // fill color
		theMouse             // the Mouser
	);
	// the font
	
	bool makeContours{ true };
	float simplifyFont{ 0.0f };
	font1.load("free3of9.ttf", 84,true, true, true,0.0f);     //BARCODE FONT in app/s...bin/data
	font2.load("Inkspot.ttf", 84,true, true, true,0.0f);     //BARCODE FONT in app/s...bin/data
	font3.load("SA-BostonBlvd.ttf", 84,true, true, true,0.0f);     //BARCODE FONT in app/s...bin/data
	//font1.load("free3of9.ttf", 64, true, true, makeContours, simplifyFont);
	//font1.load("NovaMono.ttf", 64, true, true, makeContours, simplifyFont);

}

//--UPDATE------------------------------------------------------------
void ofApp::update(){
	// Update the mouse and the boid.
	theMouse.update();
	theBoid.update();

	//Call my console funktion from main
	//tocon();
}

//--DRAW------------------------------------------------------------
void ofApp::draw(){
	// Draw the mouse and the boid.
	theMouse.draw(theBoid.getLocation());
	theBoid.draw();
	

	//font1.drawStringAsShapes("OSCAR PETERSON", 200, 200); //---Nur Grossbuchstaben für Barcodefont!!
	//font1.drawStringAsShapes(mystr, 200, 200); //---Nur Grossbuchstaben für Barcodefont!!
	vec_mutex.lock();
	int se;
	se = mystr_vec.size();
//	for (auto s : mystr_vec) {
	//for (std::vector<std::string>::iterator it = mystr_vec.begin(); it != mystr_vec.end(); ++it) {
	for (int j=0;j<se;j++){
	/* std::cout << *it; ... */
	

		//font1.drawStringAsShapes(s, 20,20); //---Nur Grossbuchstaben für Barcodefont!!
	//	font1.drawStringAsShapes(s, (i > 4) ? 400 : 20, (i > 4) ? (i-4)*86 : (i+1)*86); //---Nur Grossbuchstaben für Barcodefont!!
		//font2.drawStringAsShapes(s, (i > 4) ? 400 : 20, (i > 4) ? (i-4)*86 : (i+1)*86); //---Nur Grossbuchstaben für Barcodefont!!
		//font3.drawStringAsShapes(*it, (i > 4) ? 400 : 20, (i > 4) ? (i-4)*86 : (i+1)*86); //---Nur Grossbuchstaben für Barcodefont!!
		font3.drawStringAsShapes(mystr_vec[j], (i > 4) ? 400 : 20, (i > 4) ? (i-4)*86 : (i+1)*86); //---Nur Grossbuchstaben für Barcodefont!!
		font3.drawStringAsShapes(std::to_string(mystr_vec.size()), (i > 4) ? 399 : 10, (i > 4) ? (i-4)*86 : (i+1)*86); //---Nur Grossbuchstaben für Barcodefont!!
		i++;
	}
	i = 0;
	vec_mutex.unlock();
}
