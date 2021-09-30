int carVermelho = 12;
int carAmarelo = 11;
int carVerde = 10;
int pedVermelho = 8;
int pedVerde = 9;
int button = 2;
int CrossTime = 5000;
unsigned long changeTime;

void setup (){
  pinMode(carVermelho, OUTPUT);
  pinMode(carAmarelo, OUTPUT);
  pinMode(carVerde, OUTPUT);
  pinMode(pedVermelho, OUTPUT);
  pinMode(pedVerde, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(carVerde, HIGH);
  digitalWrite(pedVermelho, HIGH);;
}
  void loop (){
    int state = digitalRead (button);

    if (state == HIGH  &&(millis() - changeTime)>5000){
      
      changeLights();
    }
    
  }
  
void changeLights(){
  digitalWrite(carVerde, LOW);
  digitalWrite(carAmarelo, HIGH);
  delay(2000);
  digitalWrite(carAmarelo, LOW);
  digitalWrite(carVermelho,HIGH);
  delay(1000);
  digitalWrite(pedVermelho,LOW);
  digitalWrite(pedVerde, HIGH);

  delay(CrossTime);

   for( int x=0; x<10; x++){                                                                //tempo do farol pedestre 
    digitalWrite(pedVerde, LOW); // Verde apaga
    digitalWrite(pedVermelho, LOW); // Vermelho começa a piscar 10x
    delay(250);
    digitalWrite(pedVermelho, HIGH);
    delay(250);
   
   }

  digitalWrite(pedVerde, LOW);
  delay(1000);
  digitalWrite(carVerde, HIGH);
  digitalWrite(carVermelho, LOW);
  delay(1000);
  digitalWrite(carVerde, HIGH);
  digitalWrite(carAmarelo, LOW);

  changeTime - millis();
}
