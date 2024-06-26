
}


void setup() {

  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {

  // Ask for revolutions
  Serial.println("===========================\nInicio del programa");
  Serial.println("===========================\n");
  Serial.println("Ingrese la cantidad de vueltas.");

  //Read revolutions number
  while (!Serial.available()) {

    //Wait for user to enter data
  }

  //Read
  float vueltas = Serial.parseFloat();
  delay(20);

  //Calculate steps
  int pasos = calcularPasos(vueltas);

  // Print steps for revolutions
  Serial.print("Ha seleccionado ");
  Serial.print(vueltas);
  Serial.print(" vueltas.");

  //Ask for CW or CCW;
  Serial.print("\nColoque 1 para CW y 2 para CCW.\n");

  //Read CW or CCW
  while (!Serial.available()) {

    //Wait for user to enter data
  }

  //Read
  float CW = Serial.parseFloat();
  delay(20);

  if (CW == 1) {
    pasos_a_realizar = pasos;
  }

  if (CW == 2) {
    pasos_a_realizar = -pasos;
  }

  //Mover stepper
  Serial.print("Moviendo el stepper ");
  Serial.print(vueltas);
  Serial.print(" vueltas en direccion ");

  if (pasos > 0) {
    Serial.print("CCW");
  }

  if (pasos < 0) {
    Serial.print("CW");
  }
  Serial.println("...");

  myStepper.step(pasos_a_realizar);
  delay(20);
  Serial.println("\nEl movimiento ha terminado.");
  Serial.println("\nReiniciando el programa...\n");
}
