//
//  GroupBoids2d.h
//  example-boids-attract
//
//  Created by FatDazz_mac on 02/03/2016.
//
//
#pragma once


//#ifndef GroupBoids2d_h
//#define GroupBoids2d_h
#include <ofMain.h>
#include "Boid2d.h"
//#endif /* GroupBoids2d_h */

class Regle{
public:
    int group;
    bool act;
    float separateNoGroup, alignNoGroup, cohesionNoGroup;
    float distSeparationNoGroup, distAlignNoGroup, distCohesionNoGroup;
    
    
    Regle() {
        group = 0;
        separateNoGroup = 10;
        alignNoGroup = 0;
        cohesionNoGroup =0;
        distSeparationNoGroup = 100;
        distAlignNoGroup = 0;
        distCohesionNoGroup =0;
        act=false;
    }
    
    void initRegle(float _separateNoGroup, float _distSeparationNoGroup, float _cohesionNoGroup, float _distCohesionNoGroup, float _alignNoGroup, float _distAlignNoGroup){
        //group = _group;
        separateNoGroup = _separateNoGroup;
        alignNoGroup = _alignNoGroup;
        cohesionNoGroup =_cohesionNoGroup;
        distSeparationNoGroup = _distSeparationNoGroup;
        distAlignNoGroup = _distCohesionNoGroup;
        distCohesionNoGroup =_distAlignNoGroup;
        act=true;
    }
    
    void actRegle(){
        act=!act;
    }
    
};


class GroupBoid2d {
public:
    
  vector<shared_ptr<Boid2d> >    boids;
  vector<Regle> vectorRegle;
  int                 id;
    
  /*
    void initVectorRegleDefault(int _group){
    Regle r ;
    //r.initRegle(_group, 0.f, 0.f);
    }
  */
  int getNumRegle(){
    return vectorRegle.size();
  }
  int getNumBoids(){
    return boids.size();
  }
    
  void update(float amount){
    for(int i=0; i< boids.size() ; i++){
      boids[i]->update(amount);
    }
  }
    
    
    
    
    
    
  // Alig
  void setValsAligBoids(float _alig, float _distAlig){
    for (int i=0; i<boids.size(); i++) {
      setValsAligBoid(_alig, _distAlig, i);
    }
  }
  void setValsAligBoid(float _alig, float _distAlig, int _at){    
    boids[_at]->setValAlig(_alig, _distAlig);
  }
  // Sepa
  void setValsSepaBoids(float _sepa, float _distSepa){
    for (int i=0; i<boids.size(); i++) {
      setValsSepaBoid(_sepa, _distSepa, i);
    }
  }
  void setValsSepaBoid(float _sepa, float _distSepa, int _at){    
    boids[_at]->setValSepa(_sepa,_distSepa);
  }
  // Cohe
  void setValsCoheBoids(float _cohe, float _distCohe){
    for (int i=0; i<boids.size(); i++) {
      setValsCoheBoid(_cohe, _distCohe, i);
    }
  }
  void setValsCoheBoid(float _cohe, float _distCohe, int _at){    
    boids[_at]->setValCohe(_cohe,_distCohe);
  }
  // Speed
  void setMaxSpeedBoids(float _maxSpeed){
    for (int i=0; i<boids.size(); i++) {
      setMaxSpeedBoid(_maxSpeed, i);
    }
  }
  void setMaxSpeedBoid(float _maxSpeed, int _at){    
    boids[_at]->setMaxSpeed(_maxSpeed);
  }
  // Force
  void setMaxForceBoid(float _maxForce, int _at){    
    boids[_at]->setMaxForce(_maxForce);
  }
  void setMaxForceBoids(float _maxFore){
    for (int i=0; i<boids.size(); i++) {
      setMaxForceBoid(_maxFore, i);
    }
  }
  // Lead
  void setLead(bool _lead,int _at){    
    boids[_at]->setLead(_lead);
  }
    
  // vals global
  void setValsGlobalBoids(float _alig, float _distAlig,float _sepa, float _distSepa,float _cohe, float _distCohe){
    for (int i=0; i<boids.size(); i++) {
      setValsGlobalBoid(_alig,_distAlig,_sepa,_distSepa,_cohe, _distCohe, i);
    }
  }
  void setValsGlobalBoid(float _alig, float _distAlig,float _sepa, float _distSepa,float _cohe, float _distCohe, int _at){
    setValsAligBoid(_alig, _distAlig,_at);
    setValsCoheBoid(_cohe, _distCohe, _at);
    setValsSepaBoid(_sepa, _distSepa, _at);

  }
    
    

    
  void addRegle(){
    vectorRegle.push_back(Regle());
  }
    
  void changeRegle(int _group, int _noGroup,
		   float _separateNoGroup, float _distSeparationNoGroup,
		   float _cohesionNoGroup, float _distCohesionNoGroup,
		   float _alignNoGroup, float _distAlignNoGroup){
    if(_group!=_noGroup){
      vectorRegle[_noGroup].initRegle(_separateNoGroup, _distSeparationNoGroup,
				      _cohesionNoGroup, _distCohesionNoGroup,
				      _alignNoGroup, _distAlignNoGroup);
        
    }
  }
  void actAllRegle(int _group){
    for (int i=0; i<vectorRegle.size(); i++) {
      vectorRegle[i].actRegle();
    }
  }
  /*
    void addRegleGroup(int _goup,int _regle){
    vectorRegle[_regle].group=_goup;
    }
  */

 private:
    
  bool            actRegle = false;
    
};
