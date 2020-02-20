// Arduino-Pin verbunden mit SH_CP des 74HC595
int shiftPin = 8;
// Arduino-Pin verbunden mit ST_CP des 74HC595
int storePin = 10;
// Arduino-Pin verbunden mit DS des 74HC595
int dataPin = 11;
int a = 9425465;

// Dieses Muster soll ausgegeben werden
//    
//int null_1[16] = {0,0,0,0,1,1,1,1,1,1,!,0,0,0,0,0};                                     
  int null_1[16] = {0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0};  
  int eins_1[16] = {0,0,0,0,0,0,0,0,1,1,0,1,1,1,0,0};  
  int zwei_1[16] = {0,0,0,1,0,1,1,1,0,1,1,1,1,1,0,0};  
  int drei_1[16] = {0,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0};      
  int vier_1[16] = {0,0,0,1,1,0,0,0,1,1,0,1,1,1,0,0};    
 int fuenf_1[16] = {0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0};   
 int sechs_1[16] = {0,0,0,1,1,1,1,1,1,0,1,1,1,1,0,0};    
int sieben_1[16] = {0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0};     
  int acht_1[16] = {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0}; 
 int neun_1[16] = {0,0,0,1,1,0,1,1,1,1,1,1,1,1,0,0};
   
  int null_2[16] = {0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,0};  
  int eins_2[16] = {0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,0};  
  int zwei_2[16] = {0,0,0,1,0,1,1,1,0,1,1,1,1,0,1,0};  
  int drei_2[16] = {0,0,0,1,0,0,1,1,1,1,1,1,1,0,1,0};      
  int vier_2[16] = {0,0,0,1,1,0,0,0,1,1,0,1,1,0,1,0};    
 int fuenf_2[16] = {0,0,0,1,1,0,1,1,1,0,1,1,1,0,1,0};   
 int sechs_2[16] = {0,0,0,1,1,1,1,1,1,0,1,1,1,0,1,0};    
int sieben_2[16] = {0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0};     
  int acht_2[16] = {0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,0}; 
 int neun_2[16] = {0,0,0,1,1,0,1,1,1,1,1,1,1,0,1,0};   

  int null_3[16] = {0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0};  
  int eins_3[16] = {0,0,0,0,0,0,0,0,1,1,0,1,1,1,0,0};  
  int zwei_3[16] = {0,0,0,1,0,1,1,1,0,1,1,1,1,1,0,0};  
  int drei_3[16] = {0,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0};      
  int vier_3[16] = {0,0,0,1,1,0,0,0,1,1,0,1,1,1,0,0};    
 int fuenf_3[16] = {0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0};   
 int sechs_3[16] = {0,0,0,1,1,1,1,1,1,0,1,1,1,1,0,0};    
int sieben_3[16] = {0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0};     
  int acht_3[16] = {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0}; 
 int neun_3[16] = {0,0,0,1,1,0,1,1,1,1,1,1,1,1,0,0};    
//                 {0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0}; //deactivate 1-4  
//               {0,0,0,0,0,0,9,8,7,6,5,4,3,2,1,0};
void setup() {
 
 // Pins 8,9,10 auf Ausgabe
 pinMode(storePin, OUTPUT);
 pinMode(shiftPin, OUTPUT);
 pinMode(dataPin, OUTPUT);
 
 // storePin sicherheitshalber auf LOW
 digitalWrite(storePin, LOW); 
 
 for (int i=0; i<16; i++) {
 // Zuerst immer alle 3 Pins auf LOW
 // Aktion passiert bei Wechsel von LOW auf HIGH
 digitalWrite(shiftPin, LOW);
 // Jetzt den Wert der aktuellen Stelle ans Datenpin DS anlegen 
 digitalWrite(dataPin, drei_1[i]);
 digitalWrite(dataPin, zwei_1[i]); 
 // Dann ShiftPin SHCP von LOW auf HIGH, damit wird der Wert
 // am Datenpin ins Register geschoben. 
 digitalWrite(shiftPin, HIGH);
 }
 
 // Wenn alle 8 Stellen im Register sind, jetzt das StorePin STCP
 // von LOW auf HIGH, damit wird Registerinhalt an Ausgabepins
 // kopiert und der Zustand an den LEDs sichtbar
 
 digitalWrite(storePin, HIGH);
}
 
void loop () {
 digitalWrite(storePin, LOW); 
 
 for (int i=0; i<16; i++) {
 digitalWrite(shiftPin, LOW);
 if (ExtractDigit(a,1) == 1){
 digitalWrite(dataPin, eins_1[i]);}
 if (ExtractDigit(a,1) == 2){
 digitalWrite(dataPin, vier_1[i]);}
 if (ExtractDigit(a,1) == 3){
 digitalWrite(dataPin, drei_1[i]);} 
  if (ExtractDigit(a,1) == 4){
 digitalWrite(dataPin, vier_1[i]);}
 if (ExtractDigit(a,1) == 5){
 digitalWrite(dataPin, fuenf_1[i]);}
 if (ExtractDigit(a,1) == 6){
 digitalWrite(dataPin, sechs_1[i]);} 
  if (ExtractDigit(a,1) == 7){
 digitalWrite(dataPin, sieben_1[i]);}
 if (ExtractDigit(a,1) == 8){
 digitalWrite(dataPin, acht_1[i]);}
 if (ExtractDigit(a,1) == 9){
 digitalWrite(dataPin, neun_1[i]);} 
  if (ExtractDigit(a,1) == 0){
 digitalWrite(dataPin, null_1[i]);} 
 digitalWrite(shiftPin, HIGH);

 }

  digitalWrite(storePin, HIGH);
delay(1);   
 digitalWrite(storePin, LOW); 
 
 for (int i=0; i<16; i++) {
 digitalWrite(shiftPin, LOW);
 if (ExtractDigit(a,2) == 1){
 digitalWrite(dataPin, eins_2[i]);}
 if (ExtractDigit(a,2) == 2){
 digitalWrite(dataPin, vier_2[i]);}
 if (ExtractDigit(a,2) == 3){
 digitalWrite(dataPin, drei_2[i]);} 
  if (ExtractDigit(a,2) == 4){
 digitalWrite(dataPin, vier_2[i]);}
 if (ExtractDigit(a,2) == 5){
 digitalWrite(dataPin, fuenf_2[i]);}
 if (ExtractDigit(a,2) == 6){
 digitalWrite(dataPin, sechs_2[i]);} 
  if (ExtractDigit(a,2) == 7){
 digitalWrite(dataPin, sieben_2[i]);}
 if (ExtractDigit(a,2) == 8){
 digitalWrite(dataPin, acht_2[i]);}
 if (ExtractDigit(a,2) == 9){
 digitalWrite(dataPin, neun_2[i]);} 
  if (ExtractDigit(a,2) == 0){
 digitalWrite(dataPin, null_2[i]);} 
 digitalWrite(shiftPin, HIGH);

 }

  digitalWrite(storePin, HIGH);  
delay(1);  
 digitalWrite(storePin, LOW); 
 
 for (int i=0; i<16; i++) {
 digitalWrite(shiftPin, LOW);
 if (ExtractDigit(a,0) == 1){
 digitalWrite(dataPin, eins_3[i]);}
 if (ExtractDigit(a,0) == 2){
 digitalWrite(dataPin, vier_3[i]);}
 if (ExtractDigit(a,0) == 3){
 digitalWrite(dataPin, drei_3[i]);} 
  if (ExtractDigit(a,0) == 4){
 digitalWrite(dataPin, vier_3[i]);}
 if (ExtractDigit(a,0) == 5){
 digitalWrite(dataPin, fuenf_3[i]);}
 if (ExtractDigit(a,0) == 6){
 digitalWrite(dataPin, sechs_3[i]);} 
  if (ExtractDigit(a,0) == 7){
 digitalWrite(dataPin, sieben_3[i]);}
 if (ExtractDigit(a,0) == 8){
 digitalWrite(dataPin, acht_3[i]);}
 if (ExtractDigit(a,0) == 9){
 digitalWrite(dataPin, neun_3[i]);} 
  if (ExtractDigit(a,0) == 0){
 digitalWrite(dataPin, null_3[i]);} 
 digitalWrite(shiftPin, HIGH);

 }

  digitalWrite(storePin, HIGH);    
  delay(1);  
}
int ExtractDigit(int V, int P)
{
  return int(V/(pow(10,P-1))) - int(V/(pow(10,P)))*10;
}
