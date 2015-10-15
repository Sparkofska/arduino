#ifndef SOUNDBANK_H
#define SOUNDBANK_H

#include "Arduino.h"

#define FREQ_C2 65
#define FREQ_E2 82
#define FREQ_G2 98
#define FREQ_A2 110
#define FREQ_Bb2 117
#define FREQ_C3 131
#define FREQ_D3 147
#define FREQ_E3 165
#define FREQ_F3 175
#define FREQ_G3 196
#define FREQ_A3 220
#define FREQ_B3 247
#define FREQ_C4 262 //Schloss-c
#define FREQ_D4 294
#define FREQ_E4 330
#define FREQ_F4 349
#define FREQ_FIS4 367 //fis
#define FREQ_G4 392
#define FREQ_GIS4 415 //gis
#define FREQ_A4 440 //Kammerton
#define FREQ_B4 494
#define FREQ_C5 523
#define FREQ_D5 587


class Soundbank
{
public:
/**
 * Plays music on given oupout-Pin.
 * 
 * @param notes Array of frequencies to play. Use the defines in top of this File for chromatic notes. Use 0 for breaks.
 * @param beats Array of Length-Values of notes. 1 stands for a quarter note, 2 for a half an so on.
 * @param songLength must be the Length of both given Arrays notes and beats
 * @param bpm tempo of the song.
 */
static void playSong(byte outpin, int notes[], int beats[], int songLength, long bpm)
{
  long tempo = (60L*1000) / bpm;
  
  for(int i=0; i<songLength; i++)
  {
    int duration = beats[i] * tempo;
    
    tone(outpin, notes[i], duration-10);
    delay(duration);
    
  }
}

static void soundBeep(byte outpin){
  tone(outpin, FREQ_E4 *4, 100);
  delay(100);
}

static void soundStarted(byte outpin){
  for(int i = FREQ_E4; i< FREQ_E4*4; i+=2)
  {
    tone(outpin, i);
  }
  noTone(outpin);
  delay(200);
  for(int i = FREQ_E4; i< FREQ_E4*4; i+=2)
  {
    tone(outpin, i);
  }
  noTone(outpin);
}

static void soundSuccess(byte outpin){
  tone(outpin, FREQ_E4 *2, 100);
  delay(100);
  tone(outpin, FREQ_A4 *2, 200);
}

static void soundWarn(byte outpin){
  tone(outpin, FREQ_C5 *2, 100);
  delay(100);
  tone(outpin, FREQ_A4 *2, 200);
}

static void soundError(byte outpin){
  for(int i=2000; i>0; i--){
    tone(outpin, i/4 +100);
  }
  noTone(outpin);
  tone(outpin, 40, 150);
}

static void soundSiren(byte outpin){
  int notes[] = {FREQ_D5, FREQ_A4, FREQ_D5, FREQ_A4, FREQ_D5, FREQ_A4};
  int beats[] = {1, 1, 1, 1, 1, 1};
  playSong(outpin, notes, beats, 6, 120);
}

static void soundHorn(byte outpin){
  tone(outpin, FREQ_C4, 300);
  delay(400);
  tone(outpin, FREQ_C4, 800);
  delay(800);
}

static void soundHappy(byte outpin){
  int notes[] = {FREQ_A4, FREQ_E4, FREQ_E4, FREQ_FIS4, FREQ_E4, 0, FREQ_GIS4, FREQ_A4};
  for(int i=0; i<8; i++)
    notes[i] *=2;
    
  int beats[] = {4, 2, 2, 4, 4, 2, 4, 2};
  playSong(outpin, notes, beats, 8, 600);
}

static void soundSmokeOnTheWater(byte outpin){
  int notes[] = {FREQ_E2, FREQ_G2, FREQ_A2, FREQ_E2, FREQ_G2, FREQ_Bb2, FREQ_A2, FREQ_E2, FREQ_G2, FREQ_A2, FREQ_G2, FREQ_E2};
  int beats[] ={4, 4, 8, 4, 3, 1, 8, 4, 4, 8, 4, 8};
  playSong(outpin, notes, beats, 12, 400);
}
};


#endif //SOUNDBANK_H