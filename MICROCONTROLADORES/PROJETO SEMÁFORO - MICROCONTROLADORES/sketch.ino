// PROJETO DE MICROCONTROLADORES - SEMÁFOROS
// ALUNO: PEDRO LUCAS LIMA SPERANDIO

#define botao 13
#define verde1 7
#define amarelo1 6
#define vermelho1 5
//SEMAFORO 02
#define verde2 4
#define amarelo2 3
#define vermelho2 2
//SEMAFORO PEDESTRE
#define verdePedestre 8
#define vermelhoPedestre 12

boolean modoPiscanteAtivo = false;
boolean botaoPedestre = false;
void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(verde1, OUTPUT); // verde 1
  pinMode(amarelo1, OUTPUT); // amarelo 1
  pinMode(vermelho1, OUTPUT); // vermelho 1
  //segundo semáforo
  pinMode(verde2, OUTPUT); // verde 2
  pinMode(amarelo2, OUTPUT); // amarelo 2
  pinMode(vermelho2, OUTPUT); // vermelho 2
  pinMode(verdePedestre, OUTPUT);
  pinMode(vermelhoPedestre, OUTPUT);
  Serial.begin(9600);
  Serial.println("====== Depuração ========");
  digitalWrite(verdePedestre, LOW);
  digitalWrite(vermelhoPedestre, HIGH);
}

void loop() {
  //ESTADO S4 - AMARELO01, AMARELO02 - PISCANTE
  if (Serial.available() > 0)
  {
    String comando = Serial.readStringUntil('\n');

    if (comando == "amarelo") 
    { modoPiscanteAtivo = true; }
    else if (comando == "semaforo")
    { modoPiscanteAtivo = false; }
  }
  if (modoPiscanteAtivo == true)
  {
    digitalWrite(amarelo1, HIGH);
    digitalWrite(amarelo2, HIGH);
    digitalWrite(verde1, LOW);
    digitalWrite(vermelho1, LOW);
    digitalWrite(vermelho2, LOW);
    digitalWrite(verde2, LOW);
    delay(500);

    digitalWrite(amarelo1, LOW);
    digitalWrite(amarelo2, LOW);
    delay(500);
  }
  else
  {
  //ESTADO S0 - VERMELHO01, VERDE02
  digitalWrite(verde1, LOW);
  digitalWrite(amarelo1, LOW);
  digitalWrite(vermelho1, HIGH);
  
  digitalWrite(verde2, HIGH);
  digitalWrite(amarelo2, LOW);
  digitalWrite(vermelho2, LOW);
  delay(1000);

  //-------------------------------//

  //ESTADO S1 - VERMELHO01, AMARELO02
  digitalWrite(verde1, LOW);
  digitalWrite(amarelo1, LOW);
  digitalWrite(vermelho1, HIGH);
  
  digitalWrite(verde2, LOW);
  digitalWrite(amarelo2, HIGH);
  digitalWrite(vermelho2, LOW);
  delay(1000);

  //-------------------------------//

  //ESTADO S2 - VERDE01, VERMELHO02
  digitalWrite(verde1, HIGH);
  digitalWrite(amarelo1, LOW);
  digitalWrite(vermelho1, LOW);
  
  digitalWrite(verde2, LOW);
  digitalWrite(amarelo2, LOW);
  digitalWrite(vermelho2, HIGH);
  delay(1000);

  //-------------------------------//

  //ESTADO S3 - AMARELO01, VERMELHO02
  digitalWrite(verde1, LOW);
  digitalWrite(amarelo1, HIGH);
  digitalWrite(vermelho1, LOW);
  
  digitalWrite(verde2, LOW);
  digitalWrite(amarelo2, LOW);
  digitalWrite(vermelho2, HIGH);
  delay(1000);
  }
  int estadoBotao = digitalRead(botao);
  if (estadoBotao == LOW) {
    digitalWrite(amarelo1, LOW);
    digitalWrite(amarelo2, LOW);
    digitalWrite(verde1, LOW);
    digitalWrite(verde2, LOW);
    digitalWrite(vermelho1, HIGH);
    digitalWrite(vermelho2, HIGH);
    digitalWrite(verdePedestre, HIGH);
    digitalWrite(vermelhoPedestre, LOW);
    delay(5000);
  }
  if (estadoBotao == HIGH) {
    digitalWrite(verdePedestre, LOW);
    digitalWrite(vermelhoPedestre, HIGH);
  }
}