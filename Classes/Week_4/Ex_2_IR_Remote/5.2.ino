#include <IRremote.h>
#include <Servo.h>

const uint16_t kRecvPin = 2;
Servo myServo;
const int servoPin = 3;
int currentAngle = 90;
bool ledState = false;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  IrReceiver.begin(kRecvPin, ENABLE_LED_FEEDBACK);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.print("Received code: ");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    switch (IrReceiver.decodedIRData.decodedRawData) {
      case 0xF609BF00:
        if (currentAngle > 0) {
          currentAngle -= 10;
          myServo.write(currentAngle);
        }
        break;
      case 0xFE01BF00:
        if (currentAngle < 180) {
          currentAngle += 10;
          myServo.write(currentAngle);
        }
        break;
      case 0xF30CBF00:
        currentAngle = 0;
        myServo.write(currentAngle);
        break;
      case 0xEF10BF00:
        currentAngle = 20;
        myServo.write(currentAngle);
        break;
      case 0xEE11BF00:
        currentAngle = 40;
        myServo.write(currentAngle);
        break;
      case 0xED12BF00:
        currentAngle = 60;
        myServo.write(currentAngle);
        break;
      case 0xEB14BF00:
        currentAngle = 80;
        myServo.write(currentAngle);
        break;
      case 0xEA15BF00:
        currentAngle = 100;
        myServo.write(currentAngle);
        break;
      case 0xE916BF00:
        currentAngle = 120;
        myServo.write(currentAngle);
        break;
      case 0xE718BF00:
        currentAngle = 140;
        myServo.write(currentAngle);
        break;
      case 0xE619BF00:
        currentAngle = 160;
        myServo.write(currentAngle);
        break;
      case 0xE51ABF00:
        currentAngle = 180;
        myServo.write(currentAngle);
        break;
      default:
        ledState = !ledState;
        digitalWrite(LED_BUILTIN, ledState);
        break;
    }

    IrReceiver.resume();
  }
}
