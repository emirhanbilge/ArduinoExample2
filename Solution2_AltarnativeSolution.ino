struct Node
{
  int arr[7];
};

Node allNumber[15];
Node n0;
Node n1;
Node n2;
Node n3;
Node n4;
Node n5;
Node n6;
Node n7;
Node n8;
Node n9;
Node n10;
Node n11;
Node n12;
Node n13;
Node n14;
Node n15;

const int o1 = 2; // 1
const int o2 = 3; // 2
const int o3 = 4; // 3
const int o4 = 5; // 4
const int o5 = 6; // 5
const int o6 = 7; // 6
const int o7 = 8; // 7
static int i = 0;
const int button = 9;
volatile boolean currentButtonValue = false; // if you press button it change
volatile boolean lastButtonValue = false;    // As the button is pressed, arduino will constantly read the value of 1,

void loadValues()
{
  int zero[7] = {o1, o2, o3, o4, o5, o6};
  int first[7] = {o3, o4};
  int second[7] = {o5, o4, o7, o1, o2};
  int third[7] = {o5, o4, o7, o3, o2};
  int fourth[7] = {o7, o6, o3, o4};
  int five[7] = {o5, o7, o6, o3, o2};
  int six[7] = {o7, o1, o2, o3, o6};
  int seven[7] = {o5, o4, o3};
  int eight[7] = {o1, o2, o3, o4, o5, o6, o7};
  int nine[7] = {o7, o6, o5, o4, o3};
  int ten[7] = {o1, o2, o3, o5, o4, o7};
  int eleven[7] = {o6, o1, o2, o3, o7};
  int twelve[7] = {o5, o1, o2, o6};
  int thirteen[7] = {o4, o3, o2, o1, o7};
  int fourteen[7] = {o4, o5, o6, o1, o2, o7};
  int fifteen[7] = {o1, o7, o5, o6, o1, o7};
  memcpy(n0.arr, zero, sizeof(zero));
  memcpy(n1.arr, first, sizeof(first));
  memcpy(n2.arr, second, sizeof(second));
  memcpy(n3.arr, third, sizeof(third));
  memcpy(n4.arr, fourth, sizeof(fourth));
  memcpy(n5.arr, five, sizeof(five));
  memcpy(n6.arr, six, sizeof(six));
  memcpy(n7.arr, seven, sizeof(seven));
  memcpy(n8.arr, eight, sizeof(eight));
  memcpy(n9.arr, nine, sizeof(nine));
  memcpy(n10.arr, ten, sizeof(ten));
  memcpy(n11.arr, eleven, sizeof(eleven));
  memcpy(n12.arr, twelve, sizeof(twelve));
  memcpy(n13.arr, thirteen, sizeof(thirteen));
  memcpy(n14.arr, fourteen, sizeof(fourteen));
  memcpy(n15.arr, fifteen, sizeof(fifteen));

  allNumber[0] = n0;
  allNumber[1] = n1;
  allNumber[2] = n2;
  allNumber[3] = n3;
  allNumber[4] = n4;
  allNumber[5] = n5;
  allNumber[6] = n6;
  allNumber[7] = n7;
  allNumber[8] = n8;
  allNumber[9] = n9;
  allNumber[10] = n10;
  allNumber[11] = n11;
  allNumber[12] = n12;
  allNumber[13] = n13;
  allNumber[14] = n14;
  allNumber[15] = n15;
  i = 0;
  digitalWrite(8, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);     // for button
  pinMode(3, OUTPUT);     // for button
  pinMode(4, OUTPUT);     // for button
  pinMode(5, OUTPUT);     // for button
  pinMode(6, OUTPUT);     // for button
  pinMode(7, OUTPUT);     // for button
  pinMode(8, OUTPUT);     // for button
  pinMode(button, INPUT); // for button
  loadValues();
}
int GLOBAL_COUNTER = 5;
long randNumber;

void loop()
{

  currentButtonValue = digitalRead(button);  //read button value
  if (lastButtonValue != currentButtonValue) // checking last value . Press the button to make a single change.
  {
    if (currentButtonValue == HIGH) // Pressing button
    {
      for (int j = 2; j < 9; j++)
      {
        digitalWrite(j, HIGH);
      }

      /*      Random Kısmı
            randNumber = random(16)%16;
             for(int j=0 ; j<7 ; j++){
              if(allNumber[randNumber].arr[j] == 0){
                break;
              }
              digitalWrite(allNumber[randNumber].arr[j],LOW); 
            }

            */

      i += GLOBAL_COUNTER;
      if (i > 15)
      {
        i = i % 16;
      }
      for (int j = 0; j < 7; j++)
      {
        if (allNumber[i].arr[j] == 0)
        {
          break;
        }
        digitalWrite(allNumber[i].arr[j], LOW);
      }
      delay(75);
    }
  }
  lastButtonValue = currentButtonValue; // last button value saving
}
