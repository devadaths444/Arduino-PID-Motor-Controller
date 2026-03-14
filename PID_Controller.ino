
Finishing
Cool Migelo-Leelo
1
// Pins
2
const int potPin = A0;
3
const int pwmPin = 10;
4
const int dir1 = 9;
5
const int dir2 = 8;
6
const int encoderPinA = 2;
7
​
8
// Variables for Encoder and RPM calculation
9
volatile long encoderTicks = 0;
10
long previousMillis = 0;
11
const int interval = 100; // Calculate RPM every 100ms
12
double actualRPM = 0;
13
​
14
// PID Constants (You will tune these!)
15
double Kp = 2.0;
16
double Ki = 5.0;
17
double Kd = 0.1;
18
​
19
// PID Variables
20
double error = 0;
21
double previousError = 0;
22
double integral = 0;
23
double derivative = 0;
24
double outputPWM = 0;
25
​
26
// Interrupt Service Routine (ISR)
27
void countTicks() {
28
  encoderTicks++;
29
}
30
​
Serial Monitor
