

#include "ofMain.h"

struct Ball {
    int x;
    int y;
    int vx;
    int vy;
    int radius;
};


struct Words {
    string word;
};


struct Letters {
    string letter;
    int x;
    int y;
    int vy;
    int red;
    int green;
    int blue;
};


class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    Ball balls[10];
    Words words [28];
    Letters letters[4*28];
    
    int wordCounter  ;
    int thunderCount;
    int letterCounter;
    int xSpace;
    int totalLetters;
    int activeLetters;
    int passScreen;
    
    ofTrueTypeFont monoType;
    ofSoundPlayer drops[5];
    ofSoundPlayer thunder[3];
    
    int ranRed;
    int ranGreen;
    int ranBlue;
    
    
};;

