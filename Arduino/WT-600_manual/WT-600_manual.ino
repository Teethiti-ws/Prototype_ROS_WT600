#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#include <ros.h>
#include <geometry_msgs/Twist.h>
// Pin variables for motors.
const int dir1 = 51;
const int dir2 = 50;
const int en1 = 8;
const int en2 = 9;
const int pwm1 = 6; //8;
const int pwm2 = 7;
int pwm = 255;//255//150

ros::NodeHandle nh;

void MoveFwd() {
     digitalWrite(dir1, HIGH);
     digitalWrite(dir2,HIGH);
     // digitalWrite(pwm1, pwm);
    // digitalWrite(pwm2, pwm);
     analogWrite(pwm1, pwm);
     analogWrite(pwm2, pwm);
}

void MoveStop() {
     digitalWrite(dir1, LOW);
     digitalWrite(dir2,LOW);
     analogWrite(pwm1, 0);
     analogWrite(pwm2, 0);
}

void MoveLeft() {
     digitalWrite(dir1, LOW);
     digitalWrite(dir2,HIGH);
     analogWrite(pwm1, pwm);
     analogWrite(pwm2, pwm);
}

void MoveRight() {
     analogWrite(pwm1, pwm);
     analogWrite(pwm2, pwm);
     digitalWrite(dir1, HIGH);
     digitalWrite(dir2,LOW);
}

void MoveBack() {
     analogWrite(pwm1, pwm);
     analogWrite(pwm2, pwm);
     digitalWrite(dir1, LOW);
     digitalWrite(dir2,LOW);
}

void cmd_vel_cb(const geometry_msgs::Twist & msg) {
     // Read the message. Act accordingly.
     // We only care about the linear x, and the rotational z.
     const float x = msg.linear.x;
     const float z_rotation = msg.angular.z;
     // pwm = int(msg.linea/r.y);
     // Decide on the morot state we need, according to command.
     if (x > 0 && z_rotation == 0) {
         MoveFwd();
     }
    else if (x == 0 && z_rotation == 1) {
        MoveRight();
    }
    else if (x == 0 && z_rotation < 0) {
        MoveLeft();
    }
     else if (x < 0 && z_rotation == 0) {
        MoveBack();
    }
    else{
        MoveStop();
     }
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", cmd_vel_cb);

void setup() {
     pinMode(dir1, OUTPUT);
     pinMode(en1,  OUTPUT);
     pinMode(dir2, OUTPUT);
     pinMode(en2,  OUTPUT);
     pinMode(pwm1, OUTPUT);
     pinMode(pwm2, OUTPUT);

     nh.initNode();
     nh.subscribe(sub);
}

void loop() {
nh.spinOnce();
delay(1);
}
