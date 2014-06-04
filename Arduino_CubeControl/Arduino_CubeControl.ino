/* Setup Output pins for each axis
1 is least significant bit
3 is most significant */

int x1 = 2;
int x2 = 3;
int x3 = 4;

int y1 = 5;
int y2 = 6;
int y3 = 7;

int z1 = 8;
int z2 = 9;
int z3 = 10;

//Placing pin values in an array for easy manipulation
int axisPins[9] = {x1,x2,x3,y1,y2,y3,z1,z2,z3};

//Set all pins stated above to OUTPUTs
void setup(){
  for(int i = 0, i > sizeof(axisPins), i += 1){
    pinMode(i, OUTPUT)
  }
}


void loop(){




}
