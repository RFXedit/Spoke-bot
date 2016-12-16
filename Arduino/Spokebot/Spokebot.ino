//CLAVIER + BOUTON
#include <Clavier4x4.h>
Clavier4x4 clavier = Clavier4x4(47,45,43,41,39,37,35,33); // de gauche à droite
int a=50;
int b=52;
int c=53;
int block=0;
long tempsdebutretour;
int execute;

//ECRAN
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#define CLK 11
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);


//------------------------------------------------------------SETUP------------------------------------------------------------//
void setup(){
//CLAVIER + BOUTON + TESTS
Serial.begin(9600);
pinMode(a, OUTPUT);
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
clavier.init();
tempsdebutretour=0;

//ECRAN
matrix.begin();
}

//------------------------------------------------------------LOOP------------------------------------------------------------//
void loop()
{
  long dist = getDistanceCm(13);
  if (dist>20){
    block=0;
    execute = parle(); //S'il y a une personne qui passe à moins de 20cm  du capteur il va parler sinon il va continuer de charger
  }
  else{
  execute = chargement();
}}



//FUNCTIONS
int parle(){ 
    execute = chargement();
    execute = yeux();
    execute = bouche(); // executer les fonctions pour l'affichage du smiley
  long dist = getDistanceCm(13);  
  if(dist<20 && block==0){ // Si la personne reste fixe à moins de 20cm alors le robot va commencer à parler à l'utilisateur
    delay(500);
      for (int i=0; i < 1; i++) {
        execute = parler(); delay(random(100,500));
        if(i==0){
           Serial.println("Hey toi !");
        }}
      block=block+1; //On va implémenter pour passer à l'étape suivante
  }



  
  dist = getDistanceCm(13);
  if(dist<20 && block==1){
    delay(500);
      for (int i=0; i < 2; i++) {
        execute = parler(); delay(random(100,500));
        if(i==0){
           Serial.println("Viens voir !"); //Si la personne est toujours là le robot va continuer son speech
        }}
      block=block+1; //On va implémenter pour passer à l'étape suivante
  }



  
  dist = getDistanceCm(13);
  if(dist<20 && block==2){
    delay(500);
      for (int i=0; i < 5; i++) {
        execute = parler(); delay(random(100,500));
        if(i==0){
           Serial.println("J'ai une bonne affaire pour toi !"); //Si la personne est toujours là le robot va continuer son speech
        }}
      block=block+1; //On va implémenter pour passer à l'étape suivante
  }



  
  dist = getDistanceCm(13);
  if(dist<20 && block==3){
    delay(500);
      for (int i=0; i < 15; i++) {
        execute = parler(); delay(random(100,500));
        if(i==0){
           Serial.println("Tu peux voir dans la vitrine 8 produits en promotion. Appuye sur les touches que tu souhaites pour avoir des infos et le code promo !");
        }}
      block=block+1; //On va implémenter pour passer à l'étape suivante
  }



  //INTERRACTION avec le clavier
  dist = getDistanceCm(13);
  if(dist<20 && block==4){
    while(block==4){
      char key=clavier.getKey();
      if (key != NO_KEY)  {
        // va detecter une touche et va affiché la promotion correspondante
        if(key == '1'){
          execute = flecheclear();
          delay(500);
            for (int i=0; i < 15; i++) {
              execute = parler(); delay(random(100,500));
              if(i==0){
                execute = flecheGH(125); //va afficher une flèche sur l'écran matrice dans la direction du produit sélectionné
                 Serial.println("Tu as sélectionné l'article 1 ! En haut à gauche de moi vous pouvez découvrir un PC de la marque HP Omen parfait pour la bureautique. Le code promo est : OMENPC");
                  digitalWrite(a,HIGH); //Tests pour des leds (ne pas y préter attention)
                  digitalWrite(b,LOW);
                  digitalWrite(c,LOW);
              }}
          delay(500);
        }
        dist = getDistanceCm(13);
        if (dist>20){break;} // retest à chaque fois s'il y a quelqu'un

        
        if(key == '2'){
          execute = flecheclear();
          delay(500);
            for (int i=0; i < 15; i++) {
              execute = parler(); delay(random(100,500));
              if(i==0){
                execute = flecheH(125);
                Serial.println("Tu as sélectionné l'article 2 ! Juste au dessus de moi, c'est un MSI avec une GTX 1080 pour le gaming ! Le code promo est : GTX1080");  
                digitalWrite(a,LOW);
                digitalWrite(b,HIGH);
                digitalWrite(c,LOW);
              }}
          delay(500);
        }
        dist = getDistanceCm(13);
        if (dist>20){break;}

        
        if(key == '3'){
          execute = flecheclear();
          delay(500);
            for (int i=0; i < 15; i++) {
              execute = parler(); delay(random(100,500));
              if(i==0){
                execute = flecheDH(125);
                Serial.println("Tu as sélectionné l'article 3 ! Dans l'angle en haut à droite c'est un Surface Book l'évolution du Surface Pro. Le code promo est : SURFACEEVOLUTION");  
                digitalWrite(a,LOW);
                digitalWrite(b,LOW);
                digitalWrite(c,HIGH);
              }}
          delay(500);
        }
        dist = getDistanceCm(13);
        if (dist>20){break;}

        
        if(key == '4'){
          execute = flecheclear();
          delay(500);
            for (int i=0; i < 15; i++) {
              execute = parler(); delay(random(100,500));
              if(i==0){
                execute = flecheG(125);
                Serial.println("Tu as sélectionné l'article 4 ! A gauche vous pouvez voir un Surface Pro, idéal pour le design graphique avec son stylet. Le code promo est : STYLET");  
                digitalWrite(a,HIGH);
                digitalWrite(b,HIGH);
                digitalWrite(c,LOW);
              }}
          delay(500);
        }
        dist = getDistanceCm(13);
        if (dist>20){break;}

        
        if(key == '6'){
          execute = flecheclear();
          delay(500);
            for (int i=0; i < 15; i++) {
              execute = parler(); delay(random(100,500));
              if(i==0){
                execute = flecheD(125);
                Serial.println("Tu as sélectionné l'article 5 ! A ma droite c'est un Asus ROG, fin et ergonomique il sera aussi puissant pour les jeux vidéos Le code promo est : GAMING");  
                digitalWrite(a,HIGH);
                digitalWrite(b,LOW);
                digitalWrite(c,HIGH);
              }}
          delay(500);
        }
        dist = getDistanceCm(13);
        if (dist>20){break;}

        
        if(key == '7'){
          execute = flecheclear();
          delay(500);
            for (int i=0; i < 15; i++) {
              execute = parler(); delay(random(100,500));
              if(i==0){
                execute = flecheGB(125);
                Serial.println("Tu as sélectionné l'article 6 ! Juste en dessous à gauche de moi c'est un écran Dell 4K très réactif et avec des couleurs fidèles. Le code promo est : DELL4K");  
                digitalWrite(a,LOW);
                digitalWrite(b,HIGH);
                digitalWrite(c,HIGH);
              }}
          delay(500);
        }
        dist = getDistanceCm(13);
        if (dist>20){break;}

        
        if(key == '8'){
          execute = flecheclear();
          delay(500);
            for (int i=0; i < 15; i++) {
              execute = parler(); delay(random(100,500));
              if(i==0){
                execute = flecheB(125);
                Serial.println("Tu as sélectionné l'article 7 ! En dessous c'est une souris Razer Deathadder conseillée par les grands professionnels pour les jeux. Le code promo est : RAZERSOURIS");  
                digitalWrite(a,HIGH);
                digitalWrite(b,HIGH);
                digitalWrite(c,HIGH);
              }}
          delay(500);
        }
        dist = getDistanceCm(13);
        if (dist>20){break;}

        
        if(key == '9'){
          execute = flecheclear();
          delay(500);
            for (int i=0; i < 15; i++) {
              execute = parler(); delay(random(100,500));
              if(i==0){
                execute = flecheDB(125);
                Serial.println("Tu as sélectionné l'article 8 ! En bas à droite voici le clavier logitech g500 méchanique et rétro-éclairé. Le code promo est : RETROECLAIRAGE");  
                digitalWrite(a,HIGH);
                digitalWrite(b,LOW);
                digitalWrite(c,LOW);
              }}
          delay(1500);
        }
        dist = getDistanceCm(13);
        if (dist>20){break;}

        
        digitalWrite(a,LOW);
        digitalWrite(b,LOW);
        digitalWrite(c,LOW);
        Serial.println(key);
      }
    }
  }
}


//FONCTION TEST DISTANCE
long getDistanceCm(const int pin)
{
  // send the ping: low signal
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  // then high signal
  digitalWrite(pin, HIGH);
  delayMicroseconds(5);
  // end the ping
  digitalWrite(pin, LOW);
  // read ping feedback
  pinMode(pin, INPUT);
  // time expressd in microseconds
  long duration = pulseIn(pin, HIGH);
  // convert to cm
  // Sound travels at 320 m/s -> 29 microseconds per centimeter
  // The time is go and back -> divide by 2 to get the distance of the obstacle.
  return duration / 29 / 2;
}

//FONCTION ECRAN MATRICE
int yeux(){ //dessin des formes pour les yeux
  for (int x=12; x < 14; x++) {
    for (int y=3; y < 6; y++) {
      matrix.drawPixel(x, y, matrix.Color333(0,125,125));
    }}
  for (int x=18; x < 20; x++) {
    for (int y=3; y < 6; y++) {
      matrix.drawPixel(x, y, matrix.Color333(0,125,125));
    }}
   }

   
int bouche(){
  for (int x=10; x < 22; x++) {
    for (int y=10; y < 12; y++) {
      matrix.drawPixel(x, y, matrix.Color333(0,125,125));
    }}
  for (int x=8; x < 11; x++) {
    for (int y=9; y < 11; y++) {
      matrix.drawPixel(x, y, matrix.Color333(0,125,125));
    }}
  for (int x=21; x < 24; x++) {
    for (int y=9; y < 11; y++) {
      matrix.drawPixel(x, y, matrix.Color333(0,125,125));
    }}
   }
   
int parler(){
    for (int x=10; x < 22; x++) {
      for (int y=12; y < 13; y++) {
        matrix.drawPixel(x, y, matrix.Color333(0,125,125));
      }}
    for (int x=9; x < 10; x++) {
      for (int y=10; y < 13; y++) {
        matrix.drawPixel(x, y, matrix.Color333(0,125,125));
      }}
    for (int x=22; x < 23; x++) {
      for (int y=10; y < 13; y++) {
        matrix.drawPixel(x, y, matrix.Color333(0,125,125));
      }}
      delay(random(50,300));
    for (int x=10; x < 22; x++) {
      for (int y=12; y < 13; y++) {
        matrix.drawPixel(x, y, matrix.Color333(0, 0, 0));
      }}
    for (int x=9; x < 10; x++) {
      for (int y=11; y < 13; y++) {
        matrix.drawPixel(x, y, matrix.Color333(0, 0, 0));
      }}
    for (int x=22; x < 23; x++) {
      for (int y=11; y < 13; y++) {
        matrix.drawPixel(x, y, matrix.Color333(0, 0, 0));
      }}
   }

//DESSIN de chaque flèche
int  flecheD(int color){
      for (int y=5; y < 11; y++) {  
      matrix.drawPixel(29, y, matrix.Color333(color,0,0));}
      for (int y=6; y < 10; y++) {  
      matrix.drawPixel(30, y, matrix.Color333(color,0,0));}
      for (int y=7; y < 9; y++) {  
      matrix.drawPixel(31, y, matrix.Color333(color,0,0));}
  }
int  flecheG(int color){
      for (int y=5; y < 11; y++) {  
      matrix.drawPixel(2, y, matrix.Color333(color,0,0));}
      for (int y=6; y < 10; y++) {  
      matrix.drawPixel(1, y, matrix.Color333(color,0,0));}
      for (int y=7; y < 9; y++) {  
      matrix.drawPixel(0, y, matrix.Color333(color,0,0));}
  }
int  flecheH(int color){
      for (int x=13; x < 19; x++) {  
      matrix.drawPixel(x, 2, matrix.Color333(color,0,0));}
      for (int x=14; x < 18; x++) {  
      matrix.drawPixel(x, 1, matrix.Color333(color,0,0));}
      for (int x=15; x < 17; x++) {  
      matrix.drawPixel(x, 0, matrix.Color333(color,0,0));}
  }
int  flecheB(int color){
      for (int x=13; x < 19; x++) {  
      matrix.drawPixel(x, 13, matrix.Color333(color,0,0));}
      for (int x=14; x < 18; x++) {  
      matrix.drawPixel(x, 14, matrix.Color333(color,0,0));}
      for (int x=15; x < 17; x++) {  
      matrix.drawPixel(x, 15, matrix.Color333(color,0,0));}
  }

int flecheDH(int color){
      matrix.drawPixel(28, 0, matrix.Color333(color,0,0));
      for (int y=0; y < 2; y++) {  
      matrix.drawPixel(29, y, matrix.Color333(color,0,0));}
      for (int y=0; y < 3; y++) {  
      matrix.drawPixel(30, y, matrix.Color333(color,0,0));}
      for (int y=0; y < 4; y++) {  
      matrix.drawPixel(31, y, matrix.Color333(color,0,0));}
  }

int flecheGH(int color){
      matrix.drawPixel(3, 0, matrix.Color333(color,0,0));
      for (int y=0; y < 2; y++) {  
      matrix.drawPixel(2, y, matrix.Color333(color,0,0));}
      for (int y=0; y < 3; y++) {  
      matrix.drawPixel(1, y, matrix.Color333(color,0,0));}
      for (int y=0; y < 4; y++) {  
      matrix.drawPixel(0, y, matrix.Color333(color,0,0));}
}
int flecheDB(int color){
      matrix.drawPixel(3, 15, matrix.Color333(color,0,0));
      for (int y=14; y < 16; y++) {  
      matrix.drawPixel(2, y, matrix.Color333(color,0,0));}
      for (int y=13; y < 16; y++) {  
      matrix.drawPixel(1, y, matrix.Color333(color,0,0));}
      for (int y=12; y < 16; y++) {  
      matrix.drawPixel(0, y, matrix.Color333(color,0,0));}
}
int flecheGB(int color){
      matrix.drawPixel(28, 15, matrix.Color333(color,0,0));
      for (int y=14; y < 16; y++) {  
      matrix.drawPixel(29, y, matrix.Color333(color,0,0));}
      for (int y=13; y < 16; y++) {  
      matrix.drawPixel(30, y, matrix.Color333(color,0,0));}
      for (int y=12; y < 16; y++) {  
      matrix.drawPixel(31, y, matrix.Color333(color,0,0));}
 }
int flecheclear(){
   execute = flecheB(0);
   execute = flecheH(0);
   execute = flecheD(0);
   execute = flecheG(0);
   execute = flecheGB(0);
   execute = flecheDB(0);
   execute = flecheGH(0);
   execute = flecheDH(0);
}





int chargement(){
  for (int x=0; x < 32; x++) {  
      for (int y=0; y < 16; y++) {  
      matrix.drawPixel(x, y, matrix.Color333(0,125,125));
      matrix.drawPixel(x+1, y, matrix.Color333(0,125,125));
      matrix.drawPixel(x-1, y, matrix.Color333(0, 0, 0));
      matrix.drawPixel(x-2, y, matrix.Color333(0, 0, 0));
      delay(1);
  }}
  for (int x=31; x > 0; x--) {    
      for (int y=0; y < 16; y++) {  
      matrix.drawPixel(x, y, matrix.Color333(0,125,125));
      matrix.drawPixel(x-1, y, matrix.Color333(0,125,125));
      matrix.drawPixel(x+1, y, matrix.Color333(0, 0, 0));
      matrix.drawPixel(x+2, y, matrix.Color333(0, 0, 0));
      delay(1);
  }}
  for (int x=0; x < 3; x++) {    
      for (int y=0; y < 16; y++) {
      matrix.drawPixel(x, y, matrix.Color333(0, 0, 0));
      delay(1);
  }}
  }
