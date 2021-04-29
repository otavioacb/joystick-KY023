// Valor das portas usadas pelo módulo
int pinoEixoZ = 7;
int pinoEixoX = A0;
int pinoEixoY = A1;

// Variável para salvar o valor lido
int valorEixoZ;
int valorEixoX;
int valorEixoY;

// Variável para salvar o valor antigo
int valorBaseZ;
int valorBaseX;
int valorBaseY;

void setup() {
  // Definindo a porta do botão como entrada
  pinMode(pinoEixoZ, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // Lendo o valor do estado do Botão
  valorEixoZ = digitalRead(pinoEixoZ);
  // Conferindo se o valor atual esta diferente
  if(valorEixoZ != valorBaseZ) {
    // Caso o botão seja pressionado o valor é HIGH
    if(valorEixoZ == HIGH) {
      Serial.println("Botao: Pressionado");
    }  
    // Guardando o valor atual
    valorBaseZ = valorEixoZ;
  }

  // Lendo o valor do potênciometro do Eixo X
  valorEixoX = analogRead(pinoEixoX);
  if(valorEixoX != valorBaseX) {
      // Conferindo o valor correspondente a direção
      if(valorEixoX > 510) {
        Serial.println("Eixo X: Direita");
      } else if(valorEixoX < 490) {
        Serial.println("Eixo X: Esquerda");  
      }
      valorBaseX = valorEixoX;
  }

  // Lendo o valor do potênciometro do Eixo Y
  valorEixoY = analogRead(pinoEixoY);
  if(valorEixoY != valorBaseY) {
      if(valorEixoY > 520) {
        Serial.println("Eixo Y: Baixo");
      } else if(valorEixoY < 500) {
        Serial.println("Eixo Y: Alto");  
      }
      valorBaseY = valorEixoY;
  }
  
  delay(100);
}
