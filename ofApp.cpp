#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(30);
    
    
    monoType.loadFont("Cousine-Regular.ttf",20);
    
    thunder[0].loadSound("sounds/thunder2.wav");
    thunder[1].loadSound("sounds/thunder1.wav");
    thunder[2].loadSound("sounds/thunder3.wav");
    
        drops[0].loadSound("sounds/drops1.wav");
        drops[1].loadSound("sounds/drops2.wav");
        drops[2].loadSound("sounds/drops3.wav");
        drops[3].loadSound("sounds/drops4.wav");
        drops[4].loadSound("sounds/drops5.wav");
    
        words[0].word = "....";
        words[1].word = "rain";
        words[2].word = "....";
        words[3].word = "wash";
        words[4].word = "....";
        words[5].word = "away";
        words[6].word = "....";
        words[7].word = "this";
        words[8].word = "....";
        words[9].word = "hate";
        words[10].word = "....";
        words[11].word = "keep";
        words[12].word = "....";
        words[13].word = "your";
        words[14].word = "....";
        words[15].word = "head";
        words[16].word = "....";
        words[17].word = "high";
        words[18].word = "....";
        words[19].word = "stay";
        words[20].word = "....";
        words[21].word = "wait";
        words[22].word = "....";
        words[23].word = "your";
        words[24].word = "....";
        words[25].word = "fate";
        words[26].word = "....";
        words[27].word = "BOOM";

    
//for each word
    

for (int i=0; i<28; i++){
    
        xSpace = (ofRandom(20,(ofGetWidth()-(30*5))));
    int intSpace = 0;
        ranRed = ofRandom(100,255);
        ranGreen = ofRandom(100,255);
        ranBlue = ofRandom(100,255);
    
//get each character
    for (int i=0; i<4; i++) {
        letters[totalLetters].letter = words[wordCounter].word.at(letterCounter);
        letters[totalLetters].x= xSpace + (30*(intSpace+1));
        letters[totalLetters].vy = ofRandom(5,8);
        letters[totalLetters].y = 20;
        
                letters[totalLetters].red = ranRed;
                letters[totalLetters].green = ranGreen;
                letters[totalLetters].blue = ranBlue;
        
        letterCounter = letterCounter  + 1;
        totalLetters = totalLetters + 1;
        intSpace  = intSpace + 1;
        
    }
    
    wordCounter = wordCounter + 1;
    letterCounter = 0;

    
}
}


//--------------------------------------------------------------
void ofApp::update() {
    


    
    for (int i=0; i<(activeLetters); i++){
            
        letters[i].y= letters[i].y + letters[i].vy;
        if (letters[i].y >= ofGetHeight()) {
            
            int randomSound  = ofRandom(0,4);
            drops[randomSound].play();
    
            
            letters[i].y = (ofGetHeight()-1);
            letters[i].vy = 0;

        }
    }
}




//--------------------------------------------------------------
void ofApp::draw(){
 
        if (activeLetters > 0) {

            
    for (int i=0; i<(activeLetters); i++){
        ofSetColor(letters[i].red,letters[i].green,letters[i].blue);
        monoType.drawString(letters[i].letter, letters[i].x, letters[i].y);
    }
        }
    
    

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
    
    thunderCount = ofRandom(0,2);
    thunder[thunderCount].play();
    
    activeLetters  = activeLetters + 4;
    
    if (activeLetters >= (4*28)) {
        activeLetters = 0;
        wordCounter = 0;
        letterCounter = 0;
        totalLetters = 0;
        
        for (int i=0; i<28; i++){
            
            xSpace = (ofRandom(20,(ofGetWidth()-(30*5))));
            int intSpace = 0;
            
            //get each character
            for (int i=0; i<4; i++) {
                letters[totalLetters].letter = words[wordCounter].word.at(letterCounter);
                
                letters[totalLetters].x= xSpace + (30*(intSpace+1));
                letters[totalLetters].vy = ofRandom(7,8);
                letters[totalLetters].y = 20;
                
                letterCounter = letterCounter  + 1;
                totalLetters = totalLetters + 1;
                intSpace  = intSpace + 1;
            }
            
            wordCounter = wordCounter + 1;
            letterCounter = 0;
            
            
        }

    }
    
//    for (int i=0; i<4; i++) {
//        letters[letterCounter].letter = words[wordCounter].word.at(letterCounter);
//        
//        ySpace = (ofRandom(20,ofGetWidth()-300));
//        letters[letterCounter].y= ySpace + 30;
//        letters[letterCounter].vy = ofRandom(3,15);
//        letters[letterCounter].x = 20;
//        
//        letterCounter = letterCounter  + 1;
//    }
//    wordCounter = wordCounter + 1;
//    letterCounter = 0;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}
