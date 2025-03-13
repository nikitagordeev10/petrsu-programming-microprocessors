// В лесу родилась елочка
#include "pitches.h"
int biz=11;

int melody[] = {
  NOTE_C4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_A4, NOTE_F4, NOTE_C4, NOTE_C4,
  NOTE_C4, NOTE_A4, NOTE_A4, NOTE_AS4,
  NOTE_G4, NOTE_C5, NOTE_C5, NOTE_D4,
  NOTE_D4, NOTE_AS4,NOTE_AS4,NOTE_A4,
  NOTE_G4, NOTE_F4, NOTE_C4, NOTE_A4,
  NOTE_A4, NOTE_G4, NOTE_A4, NOTE_F4
};

int Durations[] = {4,4,4,4,4,4,4,4,4,4,
  4,4,4,2,4,4,4,4,4,4,4,4,4,4,4,4,4,2};

void setup(){}

void loop() {
   for(int i=0;i<2;i++){
   for (int Note = 0; Note < 28; Note++) {
   int Duration = 1000/Durations[Note];
   tone(biz, melody[Note],Duration);

   int pauseNotes = Duration * 1.30;
   delay(pauseNotes);
     noTone(biz); }
    delay(200);}
  delay(6000);
} 