//Variable Initialization
int x = 0;
int y = 0;
int z = 0;
int coord[3] = {0,0,0};

/* Setup Output pins for each axis
1 is least significant bit
3 is most significant */
const int x1 = 4;
const int x2 = 3;
const int x3 = 2;

const int y1 = 7;
const int y2 = 6;
const int y3 = 5;

const int z1 = 10;
const int z2 = 9;
const int z3 = 8;

//Placing pin values in an array for easy manipulation
int axisPins[9] = {x1,x2,x3,y1,y2,y3,z1,z2,z3};

//Set all pins stated above to OUTPUTs
void setup(){
  for(int i = 0; i < sizeof(axisPins); i++){
    pinMode(axisPins[i], OUTPUT);
  }
  digitalWrite(x1,HIGH);
  digitalWrite(x2,HIGH);
  digitalWrite(x3,HIGH);
  digitalWrite(y1,LOW);
  digitalWrite(y2,LOW);
  digitalWrite(y3,LOW);
  digitalWrite(z1,HIGH);
  digitalWrite(z2,HIGH);
  digitalWrite(z3,HIGH);
}

void cubeWrite(){
  
  if(bitRead(byte(x),0) == 1){digitalWrite(x1,LOW);} else{digitalWrite(x1,HIGH);}
  if(bitRead(byte(x),1) == 1){digitalWrite(x2,LOW);} else{digitalWrite(x2,HIGH);}
  if(bitRead(byte(x),2) == 1){digitalWrite(x3,LOW);} else{digitalWrite(x3,HIGH);}
  if(bitRead(byte(y),0) == 1){digitalWrite(y1,HIGH);} else{digitalWrite(y1,LOW);}
  if(bitRead(byte(y),1) == 1){digitalWrite(y2,HIGH);} else{digitalWrite(y2,LOW);}
  if(bitRead(byte(y),2) == 1){digitalWrite(y3,HIGH);} else{digitalWrite(y3,LOW);}
  if(bitRead(byte(z),0) == 1){digitalWrite(z1,LOW);} else{digitalWrite(z1,HIGH);}
  if(bitRead(byte(z),1) == 1){digitalWrite(z2,LOW);} else{digitalWrite(z2,HIGH);}
  if(bitRead(byte(z),2) == 1){digitalWrite(z3,LOW);} else{digitalWrite(z3,HIGH);}
}

void resizedCube(){ 
  //Expanding/Contracting Box
  //Size is inverted, 3 being smallest, 0 being largest
  for(int i = 0; i < 3; i++){
    int length = 8 - (2 * i);
    int ledx[((length * length * (length - 1)) * 4) + ((length - 2) * (length - 2) * 2)];
    int ledy[((length * length * (length - 1)) * 4) + ((length - 2) * (length - 2) * 2)];
    int ledz[((length * length * (length - 1)) * 4) + ((length - 2) * (length - 2) * 2)];
    x = (8 - length) / 2;
    y = (8 - length) / 2;
    z = (8 - length) / 2;
    int array = 0;
    while(1 == 1){
      if(x == (i) || x == (7 - i) || y == (i) || y == (7 - i) || z == (i) || z == (7 - i)){
        ledx[array] = x;
        ledy[array] = y;
        ledz[array] = z;
      }
      x++;
      if(x > (3 + (length / 2))){
        x = (8 - length) / 2;
        z++;
      }
      if(z > (3 + (length / 2))){
        z = (8 - length) / 2;
        y++;
      }
      if(y > (3 + (length / 2))){
        break;
      }
      array++;
    }
    int repeat = 0;
    while(repeat < 10){
      for(int j = 0; sizeof(ledx); j++){
        x = ledx[j];
        y = ledy[j];
        z = ledz[z];
        cubeWrite();
        delayMicroseconds(5000 / sizeof(ledx));
      }
    }
  }
}

void loop(){
  //resizedCube();
  /* TEST
  x++;
  if(x > 7){
    x = 0;
    z++;
  }
  if(z > 7){
    z = 0;
    y++;
  }
  if(y > 7){
    y = 0;
  }*/
  
  //Random
  x = random(0,8);
  y = random(0,8);
  z = random(0,8);
  //
  /*
  x = 2;
  z++;
  if(z > 7){
    z = 0;
    y++;
  }
  if(y > 7){
    y = 0;
  } */
  cubeWrite();
  delayMicroseconds(5);

}


