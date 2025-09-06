void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

	analogWrite(5, 255 - RemoteXY.rgb_01_r);
  analogWrite(4, 255 - RemoteXY.rgb_01_g);
  analogWrite(0, 255 - RemoteXY.rgb_01_b);