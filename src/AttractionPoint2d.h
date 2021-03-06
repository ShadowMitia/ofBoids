#pragma once


class AttractionLine2d {
public:
    
    float a[2],b[2],u[2];
    float force, sensorDist, lengthZone;
    int group;
    
    AttractionLine2d() {
        a[0] = a[1] = b[0] = b[1] = u[0] = u[1] = force = sensorDist =  0.0f;
        group=0;
    }
    
    void VecteurU(){
        u[0] = b[0] - a[0];
        u[1] = b[1] - a[1];
        
    }
    
    AttractionLine2d(float _a[2], float _b[2], float _force, float _sensorDist, float _lengthZone, int _group){
        a[0] = _a[0];
        a[1] = _a[1];
        b[0] = _b[0];
        b[1] = _b[1];
        force = _force;
        sensorDist = _sensorDist;
        lengthZone = _lengthZone;
        VecteurU();
        group = _group;
    }
    AttractionLine2d(ofPoint _a, ofPoint _b, float _force, float _sensorDist, float _lengthZone, int _group){
        a[0] = _a.x;
        a[1] = _a.y;
        b[0] = _b.x;
        b[1] = _b.y;
        force = _force;
        sensorDist = _sensorDist;
        lengthZone = _lengthZone;
        VecteurU();
        group = _group;
    }
    
    void draw(){
        ofSetColor(ofColor::red);
        ofSetLineWidth(2);
        ofDrawLine(a[0], a[1], b[0], b[1]);
        /*
        ofSetColor(ofColor::blue);
        ofDrawRectangle(u[0], u[1], 3, 3);
        ofSetLineWidth(1);*/
    }
    void draw(ofColor _color){
        ofSetColor(_color);
        ofSetLineWidth(2);
        ofDrawLine(a[0], a[1], b[0], b[1]);
        ofSetColor(ofColor::blue);
        ofDrawRectangle(u[0], u[1], 3, 3);
        ofSetLineWidth(1);
    }
};



class AttractionPoint2d {
public:
	
	float x, y, force, sensorDist;
    int group;
	float halfDist;
	
	AttractionPoint2d() {
		x = y = force = sensorDist = halfDist = 0.0f;
        group=0;
	}

	AttractionPoint2d(float _x, float _y, float _f, float _sensor) {
		x = _x;
		y = _y;
		force = _f;
		sensorDist = _sensor;
		halfDist = sensorDist / 2.0f;
	}
	
	void draw(){
		ofRect(x-halfDist, y-halfDist, sensorDist, sensorDist);
		ofRect(x,y,3,3);
	}
	
	
};
