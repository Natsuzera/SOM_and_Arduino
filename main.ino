#include "som.h"
#include <stdlib.h> // Para gerar números aleatórios

// Número de clusters e dimensões dos pesos
#define NUM_CLUSTERS 10
#define DIMENSIONS 3

// Matriz de pesos treinada gerada aleatoriamente
float trainedWeights[NUM_CLUSTERS][DIMENSIONS];

// SOM instanciada
SOM som(NUM_CLUSTERS, DIMENSIONS);

void setup() {
    Serial.begin(9600);

    // Gerar pesos aleatórios para simulação
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            trainedWeights[i][j] = random(0, 1000) / 1000.0; // Valores entre 0.0 e 1.0
        }
    }

    // Carregar os pesos aleatórios na rede SOM
    som.loadWeights(&trainedWeights[0][0]);

    Serial.println("Pesos treinados (aleatórios):");
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        Serial.print("Cluster ");
        Serial.print(i);
        Serial.print(": ");
        for (int j = 0; j < DIMENSIONS; j++) {
            Serial.print(trainedWeights[i][j]);
            Serial.print(" ");
        }
        Serial.println();
    }
}

void loop() {
    // Gerar valores aleatórios para leitura do LDR
    float ldrReading[DIMENSIONS];
    for (int i = 0; i < DIMENSIONS; i++) {
        ldrReading[i] = random(0, 1000) / 1000.0; // Valores entre 0.0 e 1.0
    }

    // Mostrar valores do LDR
    Serial.print("Leitura LDR: ");
    for (int i = 0; i < DIMENSIONS; i++) {
        Serial.print(ldrReading[i]);
        Serial.print(" ");
    }
    Serial.println();

    // Prever o cluster vencedor
    int cluster = som.predict(ldrReading);

    // Mostrar o cluster vencedor
    Serial.print("Cluster vencedor: ");
    Serial.println(cluster);

    delay(3000);
}
