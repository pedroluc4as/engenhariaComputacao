/*TRABALHO PRATICO ARDUINO
PEDRO LUCAS LIMA SPERANDIO
CIRCUITOS ELETRICOS
PROF. RICARDO DE MOURA ARAUJO*/

#define ledVerde 3
#define ledAzul 4
#define ledVermelho 5

#define pinoPontoA A0
#define pinoPontoB A1

const float R5 = 100.0;
/*aqui indico ao arduino que ele 
não pode mudar o valordo resistor R5*/
void setup()
{
    /*aqui eu abro o terminal para exibir
    os prints ao decorrer do programa e
    declaro ao arduino o pino de cada LED*/
    Serial.begin(9600);
    pinMode(ledVerde, OUTPUT);
    pinMode(ledAzul, OUTPUT);
    pinMode(ledVermelho, OUTPUT);
}

void loop()
{
    /*aqui declaro a leitura das duas portas
    analogicas, que serao usadas para medir a
    tensao no ponto A e B*/
    int leituraA = analogRead(pinoPontoA);
    int leituraB = analogRead(pinoPontoB);

    /*o arduino converte essa leitura em um numero
    inteiro, que varia de 0 a 1023, pois é uma
    entrada de 10 bits = 2¹⁰ = 1024 que é de 0 a 1023*/
    //converter as leituras para tensão (0V - 5V)
    float tensaoA = leituraA * (5.0 / 1023.0);
    float tensaoB = leituraB * (5.0 / 1023.0);
    
    //calcular a tensão sobre o R5 (V_R5 = V_A - V_B)
    float tensaoR5 = tensaoA - tensaoB;

    /*aqui ja nos diz o sentido da corrente
    no resistor R5, se a tensao for negativa
    a corrente vai do pontoB para o pontoA
    se a tensao for positiva vai do pontoA para
    o pontoB*/

    //calcular a corrente em R5 (I = V/R) em Amperes
    float correnteA = tensaoR5 / R5;
    
    //converter de Amperes (A) para microamperes (uA)
    float corrente_uA = correnteA * 1000000.0;
    
    /*aqui comeca a logica do codigo onde vamos definir qual
    LED ficara aceso de acordo com o sentido da corrente*/
    //apaga todos os LEDs antes de acender o correto
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVermelho, LOW);
    
    //condição corrente entre -70uA e +70uA (equilibrio)
    if (corrente_uA >= -70.0 && corrente_uA <= 70.0)
    {
        digitalWrite(ledAzul, HIGH);
        Serial.println("Corrente em equilibrio entre -70uA e +70uA");
    }

    //condição corrente da direita para a esquerda (< -70uA)
    if (corrente_uA < -70.0)
    {
        digitalWrite(ledVermelho, HIGH);
        Serial.println("Corrente da D -> E");
    }

    //condição corrente da esquerda para a direita (> +70uA)
    if (corrente_uA > 70.0)
    {
        digitalWrite(ledVerde, HIGH);
        Serial.println("Corrente da E -> D");
    }

    /*aqui é feita a exibição dos prints no console*/
    Serial.print("Tensao A: ");
    Serial.print(tensaoA);
    Serial.print(" V | Tensao B: ");
    Serial.print(tensaoB);
    Serial.print(" V | Corrente: ");
    Serial.print(corrente_uA);
    Serial.println(" uA");
    
    delay(1000); //1s para imprimir novamente
}