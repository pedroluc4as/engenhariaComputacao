/*TRABALHO PRATICO ARDUINO
PEDRO LUCAS LIMA SPERANDIO
CIRCUITOS ELETRICOS
PROF. RICARDO DE MOURA ARAUJO*/

#define ledVerde 2
#define ledAzul 3
#define ledVermelho 4

#define pinoPontoA A0
#define pinoPontoB A1

const float R5 = 100.0;

void setup()
{
    Serial.begin(9600);
    pinMode(ledVerde, OUTPUT);
    pinMode(ledAzul, OUTPUT);
    pinMode(ledVermelho, OUTPUT);
}

void loop()
{
    int leituraA = analogRead(pinoPontoA);
    int leituraB = analogRead(pinoPontoB);
    // 2. Converter as leituras para Tensão (0V - 5V)
    float tensaoA = leituraA * (5.0 / 1023.0);
    float tensaoB = leituraB * (5.0 / 1023.0);

    // 3. Calcular a tensão sobre o R5 (V_R5 = V_A - V_B)
    float tensaoR5 = tensaoA - tensaoB;

    // 4. Calcular a corrente em R5 (I = V/R) em Amperes
    float correnteA = tensaoR5 / R5;
    
    // 5. Converter de Amperes (A) para microamperes (uA)
    // 1 A = 1.000.000 uA

    float corrente_uA = correnteA * 1000000.0;
    // --- LÓGICA DE DECISÃO ---
    // Apaga todos os LEDs antes de acender o correto
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVermelho, LOW);
    // Condição (c): Corrente entre -70uA e +70uA (Equilíbrio)
    if (corrente_uA >= -70.0 && corrente_uA <= 70.0)
    {
        digitalWrite(ledAzul, HIGH);
    }
    // Condição (a): Corrente da direita para a esquerda (< -70uA) [cite: 17]
    else if (corrente_uA < -70.0)
    {
        digitalWrite(ledVermelho, HIGH);
    }
    // Condição (b): Corrente da esquerda para a direita (> +70uA) [cite: 18]
    // (Assumindo que o item 'b' no PDF era um erro de digitação e deveria ser 'esquerda para a direita')
    else if (corrente_uA > 70.0)
    {
        digitalWrite(ledVerde, HIGH);
    }
    // Imprime os valores no Monitor Serial para ajudar a entender o que acontece
    Serial.print("Corrente: ");
    Serial.print(corrente_uA);
    Serial.println(" uA");
    delay(200); // Pequena pausa
}