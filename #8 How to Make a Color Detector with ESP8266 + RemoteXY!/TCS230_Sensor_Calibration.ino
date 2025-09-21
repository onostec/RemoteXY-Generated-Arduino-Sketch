//TCS230/TCS3200 Sensor Calibration

// Pin definitions for the TCS230/TCS3200 color sensor
#define S0 14        // Frequency scaling pin (connect to D5 on ESP8266)
#define S1 12        // Frequency scaling pin (connect to D6)
#define S2 13        // Color filter select pin (connect to D7)
#define S3 15        // Color filter select pin (connect to D8)
#define sensorOut 5  // Output frequency pin (connect to D1)

// Setup function runs once at power-up
void setup() {
  // Start the Serial Monitor at 9600 baud
  Serial.begin(9600);

  // Set the sensor control pins as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // Set the sensor output pin as input
  pinMode(sensorOut, INPUT);

  // Configure the sensor's frequency scaling to 100% (fastest output)
  // S0 = HIGH, S1 = LOW => 100% output scaling
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

// Loop function runs continuously after setup
void loop() {
  int redPW, greenPW, bluePW;       // Variables to store pulse widths

  // RED
  digitalWrite(S2, LOW);            // S2 LOW, S3 LOW = RED filter
  digitalWrite(S3, LOW);
  delay(100);
  redPW = pulseIn(sensorOut, LOW);  // Measure pulse width for red

  // GREEN
  digitalWrite(S2, HIGH);           // S2 HIGH, S3 HIGH = GREEN filter
  digitalWrite(S3, HIGH);
  delay(100);
  greenPW = pulseIn(sensorOut, LOW);// Measure pulse width for green

  // BLUE
  digitalWrite(S2, LOW);            // S2 HIGH, S3 HIGH = GREEN filter
  digitalWrite(S3, HIGH);
  delay(100);
  bluePW = pulseIn(sensorOut, LOW);// Measure pulse width for blue

  // Print the results to the Serial Monitor
  Serial.print("Red: ");
  Serial.print(redPW);
  Serial.print(" | Green: ");
  Serial.print(greenPW);
  Serial.print(" | Blue: ");
  Serial.println(bluePW);
  
  // Wait a bit before next reading
  delay(1000);
}
